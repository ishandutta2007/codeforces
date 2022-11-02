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

const int MAXN = 4e5;

int N, Q;
vector<int> G[MAXN], path[MAXN];
vector<tuple<int,char,char>> diff[MAXN];
int anc[MAXN], lev[MAXN], X[MAXN], Y[MAXN];
char label[MAXN];
string S[MAXN];
bool used[MAXN];

vector<int> labelChange, usedChange;

void dfs(int cur){
  for(int x : G[cur]){
    if(x != anc[cur]){
      anc[x] = cur;
      lev[x] = lev[cur]+1;
      dfs(x);
    }
  }
}

bool tryPath(int p, bool rev){
  if(rev)
    reverse(path[p].begin(), path[p].end());
  bool pos = true;
  used[p] = true;
  usedChange.push_back(p);
  for(int i=0; pos && i<sz(path[p]); i++){
    int n = path[p][i];
    if(label[n] != 0 && label[n] != S[p][i]){
      pos = false;
    }
    else if(label[n] == 0){
      label[n] = S[p][i];
      labelChange.push_back(n);
      for(auto [x,c1,c2] : diff[n]){
        if(!used[x]){
          if(label[n] == c1)
            pos &= tryPath(x, 0);
          else
            pos &= tryPath(x, 1);
        }
      }
    }
  }
  if(rev)
    reverse(path[p].begin(), path[p].end());
  return pos;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q;
  for(int i=0; i<N-1; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  anc[0] = -1;
  dfs(0);
  for(int i=0; i<Q; i++){
    cin >> X[i] >> Y[i] >> S[i];
    X[i]--; Y[i]--;
    if(lev[X[i]] < lev[Y[i]]){
      swap(X[i], Y[i]);
      reverse(S[i].begin(), S[i].end());
    }
    int x=X[i], y=Y[i];
    while(lev[x] > lev[y]){
      path[i].push_back(x);
      x = anc[x];
    }
    vector<int> ys;
    while(x != y){
      path[i].push_back(x);
      ys.push_back(y);
      x = anc[x];
      y = anc[y];
    }
    path[i].push_back(x);
    path[i].insert(path[i].end(), ys.rbegin(), ys.rend());
    for(int j=0; j<sz(S[i]); j++){
      if(S[i][j] == S[i][sz(S[i])-j-1]){
        if(label[path[i][j]]!=0 && label[path[i][j]]!=S[i][j]){
          cout << "NO\n";
          return 0;
        }
        else
          label[path[i][j]] = S[i][j];
      }
      else
        diff[path[i][j]].emplace_back(i, S[i][j], S[i][sz(S[i])-j-1]);
    }
  }

  for(int i=0; i<Q; i++){
    if(!used[i]){
      int usedCnt = sz(usedChange), labelCnt = sz(labelChange);
      if(!tryPath(i, 0)){
        for(int j=usedCnt; j<sz(usedChange); j++)
          used[usedChange[j]] = false;
        for(int j=labelCnt; j<sz(labelChange); j++){
          label[labelChange[j]] = 0;
        }
        usedChange.resize(usedCnt);
        labelChange.resize(labelCnt);
        if(!tryPath(i, 1)){
          cout << "NO\n";
          return 0;
        }
      }
    }
  }
  cout << "YES\n";
  for(int i=0; i<N; i++){
    if(label[i]==0)
      cout << 'z';
    else
      cout << label[i];
  }
  cout << endl;
}