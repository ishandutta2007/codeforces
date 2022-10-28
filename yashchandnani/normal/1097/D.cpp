#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1e9+7;
ll modpow(ll a, ll e) {
		if (e == 0) return 1;
			ll x = modpow(a * a % mod, e >> 1);
				return e & 1 ? x * a % mod : x;
}
ll in[100],cmp[100][100][2];
void pre(int k){
	rep(i,70) in[i] = modpow(i,mod-2);
	rep(i,50){
		cmp[i][i][0]=1;
		rep(tt,k){
			int cur = tt%2;
			rep(j,i+1) cmp[i][j][1-cur]=0;
			repD(j,i,0){
				cmp[i][j][1-cur] = cmp[i][j+1][1-cur]+cmp[i][j][cur]*in[j+1]%mod;
				cmp[i][j][1-cur]%=mod;
			}
		}
	}
}

void solve(){


}
vector<ll> divs,pr;
int cnt[100009];
ll inv[100009];
const int MAX_PR = 40000000;
bitset<MAX_PR> isprime;
vi qq;
vi eratosthenes_sieve(int lim=MAX_PR) {
		isprime.set(); isprime[0] = isprime[1] = 0;
			for (int i = 4; i < lim; i += 2) isprime[i] = 0;
				for (int i = 3; i*i < lim; i += 2) if (isprime[i])
							for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
					vi pr;
						repA(i,2,lim-1) if (isprime[i]) pr.push_back(i);
							return pr;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n;int k;cin>>n>>k;
	pre(k);
	repA(i,1,100000000){
		if(1ll*i*i>n) break;
		if(n%i==0){
			divs.pb(i);
			if(1ll*i*i!=n) divs.pb(n/i);
		}
	}
	sort(all(divs));
	int s  = sz(divs);
	qq = eratosthenes_sieve();
	ll nn = n;
	trav(i,qq){
		if(nn%i==0){
			pr.pb(i);
			while(nn%i==0) nn/=i;
			if(nn==1) break;
		}
	}
	if(nn>1) pr.pb(nn);
	rep(i,sz(pr)){
		while(n%pr[i]==0) n/=pr[i],inv[i]++;
	}
	int cur = k%2;
	ll ans =0;
	rep(i,s){
		ll pb = 1,cc=divs[i];
		rep(j,sz(pr)){
			int ct = 0;
			while(divs[i]%pr[j]==0) divs[i]/=pr[j],ct++;
			pb = pb*cmp[inv[j]][ct][cur]%mod;
		}
		ans += pb*(cc%mod)%mod;
	}
	cout<<(ans%mod+mod)%mod;
	return 0;
}