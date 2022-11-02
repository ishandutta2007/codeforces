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

const int n = 2e5+10;

int N;
int B[n], C[n];
ll A[n];
int cnt[n][2];
ll cost[n];
vector<int> G[n];

void dfs(int cur, int par){
  for(int x : G[cur]){
    if(x != par){
      A[x] = min(A[x], A[cur]);
      dfs(x, cur);
      cost[cur] += cost[x];
      cnt[cur][0] += cnt[x][0];
      cnt[cur][1] += cnt[x][1];
    }
  }
  if(B[cur] != C[cur])
    cnt[cur][B[cur]]++;
  int x = min(cnt[cur][0], cnt[cur][1]);
  cost[cur] += A[cur]*x;
  cnt[cur][0] -= x;
  cnt[cur][1] -= x;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> A[i] >> B[i] >> C[i];
  }
  for(int i=0; i<N-1; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, -1);
  if(cnt[0][0] + cnt[0][1])
    cout << -1 << endl;
  else
    cout << 2*cost[0] << endl;
}