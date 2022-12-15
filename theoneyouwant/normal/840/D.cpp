//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
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
const int LIM=3e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

v32 top[4*LIM], occ[LIM];
int sz[4*LIM];
bool cons[LIM];
v32 chked;
v32 ans;

struct Segtree{
    v32 merge(v32 a, v32 b, int l, int r, int sz){
    	v32 canditates;
    	forstl(r,a) canditates.pb(r);
    	forstl(r,b) canditates.pb(r);
    	sort(all(canditates));
    	canditates.erase(unique(all(canditates)), canditates.end());
    	v32 ans;
    	forstl(iter, canditates){
    		int t2 = upper_bound(all(occ[iter]), r) - occ[iter].begin();
    		int t1 = lower_bound(all(occ[iter]), l) - occ[iter].begin();
    	 	if((t2-t1) > sz/5) ans.pb(iter);
    	}
    	assert(ans.size() <= 5);
    	return ans;
    }

    void build(int a[], int v, int tl, int tr){
        if(tl == tr){
            top[v].pb(a[tl]);
            sz[v] = 1;
        }
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            sz[v] = sz[v*2] + sz[v*2+1];
            top[v] = merge(top[v*2], top[v*2+1], tl, tr, sz[v]);
        }
    }
	void query(int v, int tl, int tr, int l, int r, int ogl, int ogr, int k) {
        if(l>r){
        	return;
        }
        if(l <= tl && tr <= r){
        	// v32 fin;
        	forstl(iter, top[v]){
        		if(cons[iter]) continue;
        		cons[iter] = 1;
        		chked.pb(iter);
        		int t2 = upper_bound(all(occ[iter]), ogr) - occ[iter].begin();
    			int t1 = lower_bound(all(occ[iter]), ogl) - occ[iter].begin();
    			if(t2-t1 > (ogr-ogl+1)/k) ans.pb(iter);
        	}
            return;
        }
        int tm = (tl + tr)/2;
        query(v*2, tl, tm, l, min(r, tm), ogl, ogr, k);
        return  query(v*2+1, tm+1, tr, max(l, tm+1), r, ogl, ogr, k);
    }
};


int main(){
	fastio;

	int n, q;
	cin >> n >> q;
	int a[n];
	forn(i,n){
		cin >> a[i];
		occ[a[i]].pb(i);
	}

	Segtree s;
	s.build(a, 1, 0, n-1);

	bool tc = 0;

	forn(qq, q){
		int l, r, k;
		cin >> l >> r >> k;
		l--; r--;
		s.query(1, 0, n-1, l, r, l, r, k);
		forstl(r, chked) cons[r] = 0;
		chked.clear();
		int mi = MOD;
		forn(iter, ans.size()){
			mi = min(mi, ans[iter]);
		}
		ans.clear();
		if(!tc){
			if(mi < MOD) cout << mi << ln;
			else cout << -1 << ln;
		}
	}

	return 0;
}