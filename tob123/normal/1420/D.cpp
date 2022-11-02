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

ll MOD = 998244353;
const int n = 1e6;

ll f[n], fi[n];
ll inv[n];
void precompute_inverse(ll n, ll mod) {
	inv[1]=1;
	for (int i=2; i<=n; i++)
		inv[i] = (mod - (mod/i)*1LL*inv[mod%i] % mod) % mod;
}

ll ch(int a, int b){
  if(a < b)
    return 0;
  return f[a]*fi[b]%MOD*fi[a-b]%MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int> S, E;
  for(int i=0; i<N; i++){
    int l, r;
    cin >> l >> r;
    S.push_back(l);
    E.push_back(r+1);
  }
  sort(S.begin(), S.end());
  sort(E.begin(), E.end());
  precompute_inverse(2*N, MOD);
  f[0] = fi[0] = 1;
  for(int i=1; i<2*N; i++){
    f[i] = f[i-1]*i%MOD;
    fi[i] = fi[i-1]*inv[i]%MOD;
  }
  int old=0, ne=0;
  int si=0, ei=0;
  ll r = 0;
  while(si<sz(S) || ei < sz(E)){
    old += ne;
    ne = 0;
    int nxt = si < sz(S) ? (ei < sz(E) ? min(S[si], E[ei]) : S[si]) : E[ei];
    while(si < sz(S) && S[si] == nxt){
      ne++;
      si++;
    }
    while(ei < sz(E) && E[ei] == nxt){
      old--;
      ei++;
    }
    (r += ch(old+ne, K) - ch(old, K) + MOD) %= MOD;
    //cout << old << " " << ne << " -> " << r << endl;
  }
  cout << r << "\n";
}