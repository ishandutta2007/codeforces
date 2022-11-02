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

const int n = 1e3;
const ll MOD = 1e9 + 7;

int N;
vector<int> G[n];
int D[n];
ll res = 0;
ll p[n][n];
int parent[n];
bool marked[n];
int act;

// return a % b (positive value)
ll mod(ll a, ll b) {
	return ((a % b) + b) % b;
}

// return a^b mod m
ll powmod(ll a, ll b, ll m) {
	ll res = 1;
	while(b > 0)
		if(b & 1) res = (res * a) % m, --b;
		else a = (a * a) % m, b >>= 1;
	return res % m;
}

// computes gcd(a,b)
ll gcd(ll a, ll b) {
	ll tmp;
	while(b) {a %= b; swap(a, b); }
	return a;
}

// computes lcm(a,b)
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

// returns d = gcd(a,b); finds x,y such that d = ax + by
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
	ll xx = y = 0; ll yy = x = 1;
	while (b) {
		ll q = a / b; ll t = b; b = a % b;
		a = t; t = xx; xx = x - q * xx; x = t;
		t = yy; yy = y - q * yy; y = t;
	}
	return a;
}

// computes b such that ab = 1 (mod n), returns -1 on failure
ll inv(ll a, ll n) {
	ll x, y;
	ll d = extended_euclid(a, n, x, y);
	if(d > 1) return -1;
	return mod(x, n);
}

void dfs(int cur, int par){
  parent[cur] = par;
  for(int x : G[cur]){
    if(x != par){
      D[x] = D[cur]+1;
      dfs(x, cur);
    }
  }
}

void dfs2(int cur, int par, int md){
  if(marked[cur])
    md = D[cur];
  if(cur < act){
    int d1 = D[act]-md;
    int d2 = D[cur]-md;
    if(cur > act)
      swap(d1, d2);
    (res += p[d1][d2]) %= MOD;
  }
  for(int x : G[cur]){
    if(x != par){
      dfs2(x, cur, md);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N-1; i++){
    int x, y;
    cin >> x >> y;
    y--; x--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  for(int i=0; i<n; i++){
    p[i][0] = 0;
    p[0][i] = 1;
  }
  ll inv2 = inv(2, MOD);
  for(int i=1; i<n; i++){
    for(int j=1; j<n; j++){
      p[i][j] = inv2*(p[i-1][j] + p[i][j-1])%MOD;
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      D[j] = -1;
    D[i] = 0;
    dfs(i, -1);
    for(int j=0; j<N; j++){
      int cur = j;
      marked[cur] = true;
      while(parent[cur] != -1){
        cur = parent[cur];
        marked[cur] = true;
      }
      act = j;
      dfs2(i, -1, 0);
      for(int k=0; k<N; k++)
        marked[k] = false;
    }
  }
  (res *= inv(N, MOD)) %= MOD;
  cout << res << endl;
}