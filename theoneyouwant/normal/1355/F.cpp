//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln endl
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=801,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool prime[LIM];
v32 primes;

void precompute(){
	prime[0] = 0;
	prime[1] = 0;
	forsn(i,2,LIM){
		if(prime[i] == 0){
			primes.pb(i);
			int j = 2;
			while(i*j<LIM){
				prime[i*j] = 1;
				j++;
			}
		}
	}
}

ll fastpow(ll a, ll p){
	if(p == 0) return 1;
	ll z = fastpow(a,p/2);
	z = z*z;
	if(p%2) z = a*z;
	return z;
}

int main(){
	fastio;

	int t; cin>>t;
	forn(i,t){
		primes.clear();
		precompute();
		ll mul = 1;
		v64 query;
		map<ll,ll> div;
		// shuffle(primes.begin(),primes.end(),rng);
		forstl(r,primes){
			if(mul < 1e18/r){
				mul *= r;
			}
			else{
				query.pb(mul);
				mul = 1;
			}
		}
		ll done = 0;
		if(mul>1) query.pb(mul);
		v32 toc;
		forstl(r,query){
			cout<<"? "<<r<<ln;
			ll x; cin>>x;
			forstl(k,primes){
				if(x%k == 0) div[k] = 1;
				if(x%k == 0	) toc.pb(k);
			}
			done += 1;
		}

		v64 check;
		ll chk = 1;
		shuffle(toc.begin(),toc.end(),rng);

		// forstl(r,toc) cout<<"check "<<r<<ln;

		v64 tc;

		forstl(r,toc){
			if(chk < 1e18/(r*r)){
				chk *= r*r;
				continue;
			}
			if(done<21){
				done += 1;
				cout<<"? "<<chk<<ln;
				ll x; cin>>x;
				forstl(k,primes){
					ll tot = 0;
					while(x%k == 0){
						tot++;
						x /= k;
					}
					if(tot == 2) tc.pb(k);
					div[k] = max(div[k],tot);
				}
			}
			chk = 1;
		}
		if(chk>1 && done<21){
			done += 1;
			cout<<"? "<<chk<<ln;
				ll x; cin>>x;
				forstl(k,primes){
					ll tot = 0;
					while(x%k == 0){
						tot++;
						x /= k;
					}
					if(tot == 2) tc.pb(k);
					div[k] = max(div[k],tot);
				}
		}
		ll x = 1;
		forstl(r,tc){
			if(x == 1){
				while(x < 1e9/r) x *= r;
				continue;
			}
			while(x < 1e18/r) x *= r;
			if(done<22){
				done += 1;
				cout<<"? "<<x<<ln;
				ll in; cin>>in;
				forstl(k,primes){
					if(in%k == 0){
						ll tot = 0;
						while(in%k == 0){
							tot++;
							in /= k;
						}
						div[k] = max(div[k],tot);
					}
				}
			}
		}
		if(x>1 && done < 22){
			cout<<"? "<<x<<ln;
				ll in; cin>>in;
				forstl(k,primes){
					if(in%k == 0){
						ll tot = 0;
						while(in%k == 0){
							tot++;
							in /= k;
						}
						div[k] = max(div[k],tot);
					}
				}
		}
		// cout<<"queries asked "<<done<<ln;
		ll ans = 1;
		forstl(r,div){
			// cout<<"ans "<<r.fi<<" "<<r.se<<ln;
			ans *= (r.se+1);
		}

		cout<<"! "<<max(ans*2,ans+7)<<ln;

		// cout<<"Query size is "<<query.size()<<ln;
		// forstl(r,query) cout<<r<<ln;
	}

	



	return 0;
}