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

const int n = 1e6+10;

bool visE[n], vis[n];
vector<vector<pair<int,int>>> G;
vector<pii> R;

void dfs(int cur, int par){
  vis[cur] = true;
  int ePar = -1;
  vector<int> E;
  for(auto [x,ind] : G[cur]){
    if(!vis[x]){
      dfs(x, cur);
    }
    if(!visE[ind] && x != par){
      E.push_back(ind);
    }
    if(x == par)
      ePar = ind;
  }
  if(ePar != -1)
    E.push_back(ePar);
  for(int i=1; i<sz(E); i+=2){
    R.emplace_back(E[i-1], E[i]);
    visE[E[i-1]] = visE[E[i]] = true;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  G.resize(4*N);
  map<pair<ll,ll>, int> toI;
  int curI = 0;
  auto getI = [&](ll a, ll b){
    //cout << "-> " << a << " " << b << endl;
    ll g = __gcd(a, b);
    a /= g; b /= g;
    auto p = make_pair(a, b);
    if(toI.count(p) == 0){
      toI[p] = curI++;
    }
    return toI[p];
  };
  for(int i=0; i<N; i++){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    //cout << i << ":\n";
    int x = getI(b*(c+d), a*d);
    int y = getI(b*c, d*(a+b));
    G[x].push_back({y, i});
    G[y].push_back({x, i});
  }
  N *= 4;
  for(int i=0; i<N; i++){
    if(not sz(G[i])) continue;
    /*
    cout << i << ": ";
    for(auto [x, ind] : G[i]){
      cout << ind << " ";
    }
    cout << endl;
    */
  }
  for(int i=0; i<N; i++){
    if(!vis[i]){
      dfs(i, -1);
    }
  }
  cout << sz(R) << "\n";
  for(auto [a,b] : R){
    cout << a+1 << " " << b+1 << "\n";
  }
}