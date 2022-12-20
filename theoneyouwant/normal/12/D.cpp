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
const int LIM=5e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct SegTree{
	int n, t[4*LIM];
	SegTree(int n){
		this-> n = n;
		forn(i,4*LIM) t[i] = 0;
	}
	void update(int v, int tl, int tr, int l, int r, int val){
		if(l>r) return;
		if(tl == l && r == tr){
			t[v] = max(t[v],val);
		}
		else{
			int tm = (tl+tr)>>1;
			update(v*2,tl,tm,l,min(tm,r),val);
			update(v*2+1,tm+1,tr,max(tm+1,l),r,val);
			t[v] = max(t[v*2],t[v*2+1]);
		}
	}
	int mx(int v, int tl, int tr, int l, int r) {
	    if (l > r) return 0;
	    if (l == tl && r == tr) return t[v];
	    int tm = (tl + tr) / 2;
	    return max(mx(v*2, tl, tm, l, min(r, tm)), mx(v*2+1, tm+1, tr, max(l, tm+1), r));
	}
};


int main(){
	fastio;

	int n;
	cin>>n;

	SegTree s(n);
	vector<pair<int,p32>> v;
	set<int> mapped;
	m32 m;
	int inp[n][3];
	forn(j,3){
		forn(i,n){
			cin>>inp[i][j];
		}
	}
	forn(i,n){
		v.pb(mp(inp[i][0],mp(inp[i][1],inp[i][2])));
		mapped.insert(inp[i][1]);
	}
	sort(v.begin(),v.end(),greater<pair<int,p32>>());
	int cnt = 0;
	forstl(r,mapped){
		m[r] = cnt;
		cnt++;
	}
	cnt = 0;
	int curr = MOD;
	vector<p32> updates;
	forn(i,n){
		// cout<<i<<" "<<v[i]<<endl;
		if(v[i].fi<curr){
			curr = v[i].fi;
			forstl(r,updates){
				s.update(1,0,n-1,r.fi,r.fi,r.se);
			}
			updates.clear();
		}
		if(v[i].se.se<s.mx(1,0,n-1,m[v[i].se.fi]+1,n-1)){
			cnt++;
		}
		// cout<<updates<<ln;
		// cout<<"NOW "<<cnt<<" "<<s.mx(1,0,n-1,m[v[i].se.fi]+1,n-1)<<" "<<m[v[i].se.fi]<<endl;
		updates.pb(mp(m[v[i].se.fi],v[i].se.se));
		// cout<<"OK"<<endl;
		// s.update(1,0,n-1,m[v[i].se.fi],m[v[i].se.fi],v[i].se.se);
	}
	cout<<cnt<<ln;

	return 0;
}