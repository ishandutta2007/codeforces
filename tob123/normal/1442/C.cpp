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
typedef tuple<ll,int,int> ti;

const int n = 4e5+10;
const ll INF = 1e8;
const ll MOD = 998244353;

int N, M;
vector<vector<int>> G[2];
int D[n];
int C[n];
int visCnt[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  G[0].resize(N);
  G[1].resize(N);
  for(int i=0; i<M; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[0][u].push_back(v);
    G[1][v].push_back(u);
  }

  int curA = 0;
  for(int i=0; i<N; i++)
    C[i] = INF;
  C[0] = 0;
  int bst = INF;
  for(int it=0; it<23; it++){
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    bst = min(bst, C[N-1]);
    for(int i=0; i<N; i++){
      if(C[i] < INF){
        C[i] += curA;
        Q.push(make_pair(C[i], i));
      }
    }
    while(!Q.empty()){
      auto [c, cur] = Q.top();
      Q.pop();
      if(C[cur] != c)
        continue;
      for(int x : G[it&1][cur]){
        if(C[cur]+1 < C[x]){
          C[x] = C[cur]+1;
          Q.push(make_pair(C[x], x));
        }
      }
    }
    bst = min(bst, C[N-1]);
    if(it)
      curA *= 2;
    else
      curA = 1;
  }
  if(bst < INF){
    //cout << "fin first" << endl;
    cout << bst << endl;
    return 0;
  }

  for(int i=0; i<N; i++)
    D[i] = INF;
  ll res = 1;
  priority_queue<pii, vector<pii>, greater<pii>> q1, q2;
  D[0] = 1;
  q1.push(make_pair(1, 0));
  q2.push(make_pair(1, 0));
  int par = 0;
  while(true){
    swap(q1, q2);
    while(!q1.empty()){
      auto [dst, cur] = q1.top();
      q1.pop();
      if(D[cur] != dst)
        continue;
      if(visCnt[cur] >= 2)
        continue;
      visCnt[cur]++;
      //cout << cur << endl;
      if(cur == N-1)
        goto END;
      for(int x : G[par][cur]){
        if(D[cur]+1 < D[x]){
          q1.push(make_pair(D[cur]+1, x));
          q2.push(make_pair(D[cur]+1, x));
          D[x] = D[cur]+1;
        }
      }
    }
    (res *= 2) %= MOD;
    //cout << "swapped" << endl;
    par = 1-par;
  }
END:
  res += MOD-1;
  res += D[N-1]-1+MOD;
  res %= MOD;
  
  cout << res << endl;
}