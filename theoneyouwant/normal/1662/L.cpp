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

set<p32> lpos[LIM], rpos[LIM];
map<p32, int> mx_right;
map<p32, int> mx_left;
int n, v;
ll t[LIM], a[LIM];

void pr(p32 p){
	cout << "{" << p.fi << ", " << p.se << "}" << ln;
	return;
}

bool check(int cpos, int val, int t){
	if(val==0) return 1;
	// check positions with val - 1 to see if they work

	auto r = lpos[val-1].lower_bound({cpos, t});
	auto l = rpos[val-1].lower_bound({cpos, t});

	if(r != lpos[val-1].end()){
		p32 rp = (*r);
		if(t * v - mx_left[rp] + cpos >= 0){
			return 1;
		}
	}
	if(l != rpos[val-1].begin()){
		l--;
		p32 lp = (*l);
		if(t * v + mx_right[lp] - cpos >= 0){
			return 1;
		}
	}

	return 0;
}

signed main(){
	fastio;

	int tests = 1;
	// cin >> tests;

	while(tests--){

		cin >> n >> v;

		// forn(i,n+1){
		// 	lpos[i].clear();
		// 	rpos[i].clear();
		// 	t[i] = 0;
		// 	a[i] = 0;
		// }
		// mx_right.clear();
		// mx_left.clear();

		forn(i, n){
			cin >> t[i];
		}
		forn(i, n){
			cin >> a[i];
		}

		lpos[0].insert({0, 0});
		rpos[0].insert({0, 0});
		mx_right[{0, 0}] = 0;
		mx_left[{0, 0}] = 0;

		int mx = 0;

		forn(i, n){

			int l = 0;
			int r = mx+1;

			while(l<r){
				int mid = (l+r+1)/2;
				if(check(a[i], mid, t[i])){
					l=mid;
				}
				else{
					r=mid-1;
				}
			}

			int mid = l;

			if(mid == 0){
				continue;
			}

			auto ri = lpos[mid].lower_bound({a[i], t[i]});
			auto le = rpos[mid].lower_bound({a[i], t[i]});

			ll c_left = a[i] + v * t[i];
			ll c_right = a[i] - v * t[i];

			pair<int,int> rp = (*ri);
			pair<int,int> lp = (*le);

			if(ri != lpos[mid].end()){
				while((ri != lpos[mid].end()) && (mx_right[(*ri)] <= c_right)){
					auto x = ri;
					x++;
					lpos[mid].erase(ri);
					swap(x, ri);
				}
			}

			if(le != rpos[mid].begin()){
				le--;
				bool b = 1;
				while((mx_left[(*le)] >= c_left)){
					auto x = le;
					if(x == rpos[mid].begin()) b = 0;
					x--;
					rpos[mid].erase(le);
					swap(x, le);
					if(b == 0) break;
				}
			}

			mx_left[{a[i], t[i]}] = c_left;
			mx_right[{a[i], t[i]}] = c_right;

			lpos[mid].insert({a[i], t[i]});
			rpos[mid].insert({a[i], t[i]});

			mx = max(mx, mid);
		}

		cout << mx << ln;
	}

	return 0;
}