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
  cout << "}" << endl;
}

const int n = 4e5;

vector<int> G[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  vector<int> toC(N, -1);
  vector<int> nxt(N, -1);
  for(int i=0; i<N; i++){
    cin >> P[i];
    P[i]--;
  }
  for(int i=0; i<K; i++){
    int x, y;
    cin >> x >> y;
    nxt[x-1] = y-1;
    toC[y-1] = -2;
  }
  bool pos = true;
  int curC = 0;
  vector<vector<int>> C;
  vector<int> st;
  for(int i=0; i<N; i++){
    if(toC[i] == -1){
      C.push_back(vector<int>());
      toC[i] = curC++;
      st.push_back(i);
      int x = i;
      C.back().push_back(x);
      while(nxt[x] != -1){
        toC[nxt[x]] = toC[x];
        x = nxt[x];
        C.back().push_back(x);
      }
      x = i;
      set<int> bef;
      pos &= P[x] == -1 || toC[P[x]] != toC[x];
      while(nxt[x] != -1){
        bef.insert(x);
        x = nxt[x];
        pos &= P[x] == -1 || toC[P[x]] != toC[x] || bef.count(P[x]);
      }
    }
  }
  for(int x : toC){
    pos &= x != -2;
  }
  if(!pos){
    cout << 0 << endl;
    return 0;
  }
  vector<int> deg(sz(C));
  for(int c=0; c<sz(C); c++){
    for(int x : C[c]){
      if(P[x] != -1 && toC[P[x]] != c){
        G[toC[P[x]]].push_back(c);
        deg[c]++;
      }
    }
  }
  queue<int> Q;
  for(int i=0; i<sz(C); i++)
    if(deg[i] == 0)
      Q.push(i);
  vector<int> res;
  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();
    for(int x : G[cur]){
      deg[x]--;
      if(deg[x] == 0)
        Q.push(x);
    }
    for(int x : C[cur]){
      res.push_back(x);
    }
  }
  if(sz(res) == N){
    for(int x : res)
      cout << x+1 << " ";
    cout << "\n";
  }
  else
    cout << 0 << "\n";
}