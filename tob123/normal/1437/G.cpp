#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

vector<string> S;
vector<int> V;
vector<int> indx;
vector<multiset<int>> vv;

struct AhoCorasick  {
  #define ep emplace_back
  vector<array<int,26>> nx, go;
  vector<vector<int>> fin;
  vector<int> lnk;
  int cnt;
  AhoCorasick() : cnt(0) { add(); }
  AhoCorasick(const vector<string> &S) : cnt(0) {
    add();
    int ind = 0;
    for (auto &s : S) {
      int cur = 0;
      for (auto c: s) {
        if (!nx[cur][c-'a'])
          nx[cur][c-'a'] = cnt, add();
        cur = nx[cur][c-'a'];
      }
      fin[cur].push_back(ind++);
    }
    for (queue<int> q({0}); !q.empty();) {
      int u = q.front(); q.pop();
      for (int i = 0; i < 26; i++) {
        int v = nx[u][i];
        if (v) {
          lnk[v] = go[lnk[u]][i];
          q.push(v);
        }
        go[u][i] = v ? v : go[lnk[u]][i];
      }
    }
    for (queue<int> q({0}); !q.empty();) {
      int u = q.front(); q.pop();
      if(sz(fin[lnk[u]]) == 0){
        lnk[u] = lnk[lnk[u]];
      }
      for (int i = 0; i < 26; i++) {
        int v = nx[u][i];
        if (v) {
          q.push(v);
        }
      }
    }
  }
  void add() {
    cnt++, nx.ep(), go.ep(), fin.ep(), lnk.ep();
  }
  int q2(int cur){
    int res = -1;
    while(cur != 0){
      for(int x : fin[cur])
        res = max(res, *(--(vv[x].end())));
      cur = lnk[cur];
    }
    return res;
  }
  int query(const string &s) {
    int cur = 0, ans = -1;
    for (char c : s) {
      cur = go[cur][c-'a'];
      ans = max(ans, q2(cur));
    }
    return ans;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  S.resize(N);
  V.resize(N);
  vv.resize(N);
  indx.resize(N);
  vector<pair<string,int>> A;
  for(int i=0; i<N; i++){
    cin >> S[i];
    A.emplace_back(S[i], i);
  }
  sort(A.begin(), A.end());
  S.clear();
  S.push_back(A[0].first);
  for(int i=1, ind=1; i<sz(A); i++){
    if(A[i].first == A[i-1].first)
      indx[A[i].second] = indx[A[i-1].second];
    else{
      indx[A[i].second] = ind++;
      S.push_back(A[i].first);
    }
  }
  for(int i=0; i<N; i++)
    vv[indx[i]].insert(0);
  AhoCorasick aho(S);
  for(int m=0; m<M; m++){
    char c; string q; int i, x;
    cin >> c;
    if(c == '1'){
      cin >> i >> x;
      i--;
      vv[indx[i]].erase(vv[indx[i]].find(V[i]));
      V[i] = x;
      vv[indx[i]].insert(x);
    }
    else{
      cin >> q;
      cout << aho.query(q) << "\n";
    }
  }
}