#pragma GCC optimize("O3")
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
void printBin(int x){
  bitset<10> b(x);
  cout << b << endl;
}

const int n = 4e5;
const ll MOD = 998244353;

int N, Ms;
int L[n], R[n];
vector<int> G[50];
vector<int> S[n], E[n];
int M[n];
int dp[n];
ll f[n], f2[n];
vector<ll> res;
int asz;
ll bin2[50][50];

ll bin(int n, int k){
  return f[n] * f2[k] % MOD * f2[n-k] % MOD;
}

void calcRes(ll act, ll fst){
  for(int i=0; i<sz(res); i++){
    res[i] = 0;
  }
  fst &= act;
  for(ll m = fst; m>=0; m = (m-1)&fst){
    ll ri = act & (~fst);
    int cnt = 0, cnt2 = 0;
    for(int i=0; i<asz; i++){
      if(m & (1ll<<i)){
        for(int x : G[i]){
          if(m & (1ll<<x))
            goto NXT;
          ri &= ~(1ll<<x);
        }
      }
    }
    cnt = __builtin_popcountll(ri);
    cnt2 = __builtin_popcountll(m);
    for(int i=0; i<=cnt; i++){
      res[cnt2+i] += bin2[cnt][i];
    }
NXT: ;
    if(m == 0)
      break;
  }
  for(int i=0; i<sz(res); i++)
    res[i] %= MOD;
}

ll inv[n];
void precompute_inverse(ll n, ll mod) {
	inv[1]=1;
	for (int i=2; i<=n; i++)
		inv[i] = (mod - (mod/i)*1LL*inv[mod%i] % mod) % mod;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Ms;
  for(int i=0; i<N; i++){
    cin >> L[i] >> R[i];
    M[i] = -1;
  }
  precompute_inverse(N, MOD);
  f[0] = f2[0] = 1;
  for(ll i=1; i<=N; i++){
    f[i] = f[i-1]*i%MOD;
    f2[i] = f2[i-1]*inv[i]%MOD;
  }
  vector<int> A;
  vector<pii> P;
  for(int i=0; i<Ms; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    A.push_back(a);
    A.push_back(b);
    P.emplace_back(a,b);
  }
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  asz = sz(A);
  for(int i=0; i<sz(A); i++){
    M[A[i]] = i;
    S[L[A[i]]].push_back(M[A[i]]);
    E[R[A[i]]+1].push_back(M[A[i]]);
  }
  ll fst = 0;
  for(auto[a,b] : P){
    fst |= 1ll<<M[a];
    G[M[a]].push_back(M[b]);
    G[M[b]].push_back(M[a]);
  }
  for(int i=0; i<N; i++){
    if(M[i] == -1){
      dp[L[i]]++;
      dp[R[i]+1]--;
    }
  }
  ll act = 0;
  res.resize(42);
  ll erg = 0;
  for(int i=0; i<=45; i++){
    for(int j=0; j<=i; j++)
      bin2[i][j] = bin(i, j);
  }
  calcRes(0, 0);
  for(int i=1; i<=N; i++){
    dp[i] += dp[i-1];
    bool ch = false;
    for(int ind : S[i]){
      //cout << "start: " << A[ind] << endl;
      act |= 1ll<<ind;
      ch = true;
    }
    for(int ind : E[i]){
      act ^= 1ll<<ind;
      //cout << "end: " << A[ind] << endl;
      ch = true;
    }
    if(ch)
      calcRes(act, fst);
    //print(res);
    //cout << dp[i] << endl;
    //printBin(act);
    for(int j=0; j<=min(sz(res)-1, i); j++){
      if(dp[i] >= i-j)
        (erg += bin(dp[i], i-j) * res[j]) %= MOD;
    }
    //cerr << erg << endl << endl;
  }
  cout << erg << endl;
}