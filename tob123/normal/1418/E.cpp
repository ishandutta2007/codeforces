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
typedef tuple<int,int,int> ti;

const ll MOD = 998244353;
const ll n = 1e6;

ll inv[n];
void precompute_inverse(int n, ll mod) {
	inv[1]=1;
	for (int i=2; i<=n; i++)
		inv[i] = (mod - (mod/i)*1LL*inv[mod%i] % mod) % mod;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> D(N);
  precompute_inverse(N+M, MOD);
  ll stot = 0;
  for(int i=0; i<N; i++){
    cin >> D[i];
    stot += D[i];
  }
  stot %= MOD;
  sort(D.rbegin(), D.rend());
  vector<ll> res(M);
  vector<ti> A;
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    A.emplace_back(b, a, i);
  }
  sort(A.rbegin(), A.rend());
  ll s=0, di = 0;
  for(auto [b, a, i] : A){
    while(di < sz(D) && D[di] >= b){
      (s += D[di++]) %= MOD;
    }
    if(di < a){
      res[i] = 0;
    }
    else{
      //cout << i << ": " << s << " " << stot << " " << di << endl;
      res[i] = inv[di] * (di-a) % MOD * s % MOD;
      (res[i] += inv[di+1] * (di-a+1) % MOD * (stot-s+MOD)) %= MOD;
    }
  }
  for(int i=0; i<M; i++){
    cout << res[i] << "\n";
  }
}