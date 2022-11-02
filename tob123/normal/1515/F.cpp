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

const int n = 4e5;

vector<pii> G[n];
vector<pii> T[n];
bool vis[n];
ll A[n];
int N, M;
ll X;
ll cnt[n], sum[n];
vector<int> res;

void dfs(int cur){
  vis[cur] = true;
  cnt[cur] = 1;
  sum[cur] = A[cur];
  for(auto[x,i] : G[cur]){
    if(!vis[x]){
      T[cur].push_back({x,i});
      dfs(x);
      sum[cur] += sum[x];
      cnt[cur] += cnt[x];
    }
  }
  auto cmp = [&](pii i, pii j){
    return sum[i.first]-cnt[i.first]*X > sum[j.first]-cnt[j.first]*X;
  };
  sort(T[cur].begin(), T[cur].end(), cmp);
}

ll dfs2(int cur){
  for(auto [x,ei] : T[cur]){
    if(A[cur] >= X){
      A[x] += A[cur]-X;
      res.push_back(ei);
      dfs2(x);
      A[cur] = A[x];
    }
    else{
      dfs2(x);
      assert(A[x]+A[cur] >= X);
      A[cur] += A[x]-X;
      res.push_back(ei);
    }
  }
  return A[cur];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> X;
  ll s = 0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    s += A[i];
  }
  for(int i=0; i<M; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    G[x].push_back({y, i});
    G[y].push_back({x, i});
  }
  if(s < (N-1)*X){
    cout << "NO\n";
    return 0;
  }
  dfs(0);
  dfs2(0);
  cout << "YES\n";
  for(int x : res)
    cout << x+1 << "\n";
}