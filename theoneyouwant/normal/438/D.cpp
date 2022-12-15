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
#define int long long int
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

    v32 t, mx;

    Segtree(int n) {
        t.assign(4*n, 0);
        mx.assign(4*n, 0);
    }

    void build(int a[], int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
            mx[v] = a[tl];
        }
        else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
            mx[v] = max(mx[v*2], mx[v*2+1]);
        }
    }

    void update(int v, int tl, int tr, int l, int r, int modify){
    	// cout<<v<<" "<<mx[v]<<" "<<l<<" "<<r<<" "<<modify<<ln;
        if(l > r){
            return;
        }
        if(tl == tr){
        	t[v] = t[v]%modify;
        	mx[v] = t[v];
        	return;
        }
        if(mx[v] < modify) return;
        int tm = (tl + tr)/2;
        update(v*2, tl, tm, l, min(r, tm), modify);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, modify);
        t[v] = t[v*2]+t[v*2+1];
        mx[v] = max(mx[v*2], mx[v*2+1]);
    }

    void point_update(int v, int tl, int tr, int pt, int val){
    	if(tl>tr){
    		return;
    	}
    	if(pt>tr || pt<tl) return;
    	if(tl == tr){
    		t[v] = val;
    		mx[v] = val;
    		return;
    	}
    	int tm = (tl + tr)/2;
    	point_update(v*2, tl, tm, pt, val);
    	point_update(v*2+1, tm+1, tr, pt, val);
    	t[v] = t[v*2]+t[v*2+1];
    	mx[v] = max(mx[v*2], mx[v*2+1]);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if(l <= tl && tr <= r){
            return t[v];
        }
        int tm = (tl + tr)/2;
        return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
};


signed main(){
	fastio;

	int n = read(), m = read();
	int a[n];
	forn(i,n) a[i] = read();
	
	Segtree s(n);
	s.build(a,1,0,n-1);

	forn(i,m){
		int type = read();
		if(type == 1){
			int l = read(), r = read();
			l--; r--;
			cout<<s.query(1, 0, n-1, l, r)<<ln;
		}
		else if(type == 2){
			int l = read(), r = read(), x = read();
			l--; r--;
			s.update(1, 0, n-1, l, r, x);
		}
		else if(type == 3){
			int k = read(), x = read();
			k--;
			s.point_update(1, 0, n-1, k, x);
		}
	}

	return 0;
}