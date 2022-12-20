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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main(){
	fastio;

	int n, m;
	cin >> n >> m;

	ll p[n], x[m];
	ll pos[n];

	forn(i, n){
		pos[i] = i * 100;
		cin >> p[i];
	}
	forn(i, m){
		cin >> x[i];
	}

	vector<tuple<ll,ll,ll>> dist_left;
	vector<tuple<ll, ll, ll>> dist_right;

	forn(i,n){
		// 1 is hut for dist_left
		dist_left.pb({100*i, 1, i});
		dist_right.pb({100*i, -1, i});
	}

	forn(i,m){
		// 0 for ice cream
		dist_left.pb({x[i], 0, i});
		dist_right.pb({x[i], 0, i});
	}

	sort(all(dist_left));
	sort(all(dist_right), greater<>());

	ll dl[n] = {0};
	ll dr[n] = {0};

	forn(i,n){
		dl[i] = 1e18;
		dr[i] = 1e18;
	}

	ll last = -1e18;

	forstl(r, dist_left){
		ll pos, type, curr;
		tie(pos, type, curr) = r;

		if(type == 0){
			last = pos;
			continue;
		}
		dl[curr] = min(dl[curr], pos - last);
	}

	last = 2e18;

	forstl(r, dist_right){
		ll pos, type, curr;
		tie(pos, type, curr) = r;

		if(type == 0){
			last = pos;
			continue;
		}
		dr[curr] = min(dr[curr], last - pos);
	}

	// forn(i, n){
	// 	cout << i << " " << dl[i] << " " << dr[i] << ln;
	// }

	// start from leftmost hut
	// go to rightmost hut

	int curr_r = -1;
	ll num_p = 0;
	ll mx = 0;

	for(int curr_l = 0; curr_l < n; curr_l++){
		if(curr_r < curr_l){
			if((dl[curr_l] == 0) || (dr[curr_l] == 0)){
				num_p = 0;
				continue;
			}
			curr_r = curr_l;
			num_p += p[curr_r];
		}
		while((curr_r<n-1) && (pos[curr_r+1]<pos[curr_l]+dr[curr_l]) && (pos[curr_l]+dl[curr_l]>pos[curr_r+1]-dr[curr_r+1])){
			num_p += p[curr_r+1];
			curr_r++;
		}
		mx = max(mx, num_p);
		num_p -= p[curr_l];
	}

	cout << mx << ln;


	return 0;
}