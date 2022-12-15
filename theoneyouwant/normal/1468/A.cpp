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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct Segtree{

    v32 t;

    Segtree(int n) {
        t.assign(4*n, 0);
    }

    void build(int a[], int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
        }
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    void update(int v, int tl, int tr, int l, int r, int addend){
        if(l > r){
            return;
        }
        if(l <= tl && tr <= r){
            t[v] = max(t[v], addend);
        } else {
            int tm = (tl + tr)/2;
            update(v*2, tl, tm, l, min(r, tm), addend);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if(l <= tl && tr <= r){
            return t[v];
        }
        int tm = (tl + tr)/2;
        return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};


int main(){
	fastio;
	int tests = 1;
	cin>>tests;
	
	while(tests--){

		int n; cin>>n;
		int a[n]; forn(i,n) cin>>a[i];
		stack<p32> less;
		int cl_more[n] = {0};
		forn(i,n) cl_more[i] = -1;
		forn(i,n){
			while(!less.empty() && less.top().fi < a[i]){
				less.pop();
			}
			if(!less.empty()){
				cl_more[i] = less.top().se;
			}
			less.push(mp(a[i],i));
		}
		int dummy[n] = {0};
		forn(i,n) dummy[i] = 0;
		Segtree s(n);
		s.build(dummy, 1, 0, n-1);
		vp32 ord;
		forn(i,n){
			ord.pb(mp(a[i],i));
		}
		sort(all(ord));
		forn(i,n){
			int ind = ord[i].se;
			// if(cl_less[ind] == -1) continue;
			// int d1 = cl_less[ind]+1;
			if(cl_more[ind] == -1) cl_more[ind] = 0;
			int mx = 0, mx2 = 0;
			if(ind>0) mx = 1+s.query(1,0,n-1,cl_more[ind],ind-1);
			if(ind>1) mx2 = 2+s.query(1,0,n-1,0,cl_more[ind]-1);
			int atleast = 1;
			if(ind >= 1) atleast = 2;
			s.update(1,0,n-1,ind,ind,max({atleast,mx,mx2}));
			// cout<<ind<<" "<<s.query(1,0,n-1,ind,ind)<<ln;
		}
		// int atleast = 0;
		// if(n>=2) atleast = 2;
		cout<<s.query(1,0,n-1,0,n-1)<<ln;
	}

	return 0;
}