//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long int
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int n, m, seed, vmax;

int rnd(){
	int ret = seed;
	// cout << "start " << ret << endl;
	seed = (seed * 7 + 13) % MOD;
	// cout << "returning " << ret << endl;
	return ret;
}

ll fastpow(ll a, ll p, ll y){
	if(a==0) return 0;
	if(p==0) return 1;
	ll z = fastpow(a, p/2, y);
	z = (z*z)%y;
	if(p%2) z = (a*z)%y;
	return z;
}

signed main(){
	fastio;

	cin >> n >> m >> seed >> vmax;
	int a[n+3];

	set<pair<int, p64>> s;

	forsn(i,1,n+1){
		a[i] = rnd() % vmax + 1;
		s.insert({i, {1, a[i]}});
	}

	forsn(i,1,m+1){
		int op = rnd() % 4 + 1;
		int l = rnd() % n + 1;
		int r = rnd() % n + 1;
		int x, y;

		if(l > r) swap(l, r);

		if(op == 3){
			x = rnd() % (r-l+1) + 1;
		}
		else{
			x = rnd() % vmax + 1;
		}
		if(op == 4){
			y = rnd() % vmax + 1;
		}

		vector<pair<int, p32>> to_add, to_rem;

		if(op == 1){
			auto it = s.lower_bound(mp(l, mp(0ll, 0ll)));
			if(it != s.begin()) it--;
			while(true){
				if(it == s.end()) break;
				if((*it).fi > r) break;
				auto k = (*it);
				k.se.fi--;
				// cout << op << " " << l << " " << r << " " << x << " " << y << endl;
				// cout << k.fi << " " << k.se << endl;
				if((k.fi >= l) && (k.fi+k.se.fi <= r)){
					int start_seg = k.fi;
					int len_seg = k.se.fi;
					int val_seg = k.se.se;
					auto it2 = it;
					to_rem.pb(*it);
					it++;
					to_add.pb(mp(start_seg, mp(len_seg+1, val_seg+x)));
					continue;
				}
				if((k.fi >= l) && (k.fi+k.se.fi > r)){
					int start_seg = k.fi;
					int len_seg = k.se.fi;
					int val_seg = k.se.se;
					to_rem.pb(*it);
					to_add.pb((mp(start_seg, mp(r-start_seg+1, val_seg+x))));
					to_add.pb((mp(r+1, mp(start_seg+len_seg-r-1+1, val_seg))));
					break;
				}
				if(k.fi < l && (k.fi+k.se.fi >= l) && (k.fi+k.se.fi <= r)){
					int start_seg = k.fi;
					int len_seg = k.se.fi;
					int val_seg = k.se.se;
					to_rem.pb(*it);
					to_add.pb((mp(start_seg, mp(l-1-start_seg+1, val_seg))));
					to_add.pb((mp(l, mp(start_seg+len_seg-l+1, val_seg+x))));
					it++;
					continue;
				}
				if(k.fi < l && (k.fi+k.se.fi >= l) && (k.fi+k.se.fi > r)){
					int start_seg = k.fi;
					int len_seg = k.se.fi;
					int val_seg = k.se.se;
					to_rem.pb(*it);
					to_add.pb((mp(start_seg, mp(l-1-start_seg+1, val_seg))));
					to_add.pb((mp(l, mp(r-l+1, val_seg+x))));
					to_add.pb((mp(r+1, mp(start_seg+len_seg-r-1+1, val_seg))));
					break;
				}
				it++;
			}
		}

		if(op == 2){
			auto it = s.lower_bound(mp(l, mp(0ll, 0ll)));
			if(it != s.begin()) it--;
			to_add.pb(mp(l, mp(r-l+1, x)));
			while(true){
				if(it == s.end()) break;
				if((*it).fi > r) break;
				auto k = (*it);
				k.se.fi--;
				if(k.fi >= l && k.fi+k.se.fi <= r){
					to_rem.pb(*it);
				}
				if(k.fi >= l && k.fi+k.se.fi > r){
					int start_seg = k.fi;
					int len_seg = k.se.fi;
					int val_seg = k.se.se;
					to_rem.pb(*it);
					to_add.pb((mp(r+1, mp(start_seg+len_seg-r-1+1, val_seg))));
					break;
				}
				if(k.fi < l && (k.fi+k.se.fi >= l) && (k.fi+k.se.fi <= r)){
					int start_seg = k.fi;
					int len_seg = k.se.fi;
					int val_seg = k.se.se;
					to_rem.pb(*it);
					to_add.pb((mp(start_seg, mp(l-1-start_seg+1, val_seg))));
					it++;
					continue;
				}
				if(k.fi < l && (k.fi+k.se.fi >= l) && (k.fi+k.se.fi > r)){
					int start_seg = k.fi;
					int len_seg = k.se.fi;
					int val_seg = k.se.se;
					to_rem.pb(*it);
					to_add.pb((mp(start_seg, mp(l-1-start_seg+1, val_seg))));
					to_add.pb((mp(r+1, mp(start_seg+len_seg-r-1+1, val_seg))));
					break;
				}
				it++;
			}
		}

		if(op == 3){
			vp32 v;
			auto it = s.lower_bound(mp(l, mp(0ll, 0ll)));
			if(it != s.begin()) it--;
			while(true){
				if(it == s.end()) break;
				if((*it).fi > r) break;
				auto k = (*it);
				k.se.fi--;
				int st = max(l, k.fi);
				int end = min(r, k.fi+k.se.fi);
				if(end-st+1>0) v.pb({k.se.se, end-st+1});
				it++;
			}
			sort(all(v));
			int ans = 0;
			int curr = 0;
			forstl(r, v){
				curr += r.se;
				if(curr>=x){
					ans = r.fi;
					break;
				}
			}
			cout << ans << endl;
		}

		if(op == 4){
			ll sum = 0;
			auto it = s.lower_bound(mp(l, mp(0ll, 0ll)));
			if(it != s.begin()) it--;
			while(true){
				if(it == s.end()) break;
				if((*it).fi > r) break;
				auto k = (*it);
				k.se.fi--;
				int st = max(l, k.fi);
				int end = min(r, k.fi+k.se.fi);
				sum = (sum + (end-st+1) * fastpow(k.se.se%y, x, y)) % y;
				it++;
			}
			cout << sum << endl;
		}

		forstl(r, to_rem){
			s.erase(r);
		}
		forstl(r, to_add){
			if(r.se.fi<=0) continue;
			s.insert(r);
		}
		// cout << "QUERY " << op << " " << l << " " << r << " " << x << " " << y << endl;

		// cout << "TIME " << i << endl;
		// forstl(r, s){
		// 	cout << r.fi << " " << r.se.fi << " " << r.se.se << endl;
		// }
	}


	

	return 0;
}