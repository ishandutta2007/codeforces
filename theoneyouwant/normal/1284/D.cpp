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
const int LIM=1e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Segtree{
	int n, t[4*LIM];
	Segtree(int n){
		this-> n = n;
		forn(i,4*LIM) t[i] = 0;
	}
	void update(int v, int tl, int tr, int l, int r, int add) {
	    if (l > r)
	        return;
	    if (l == tl && r == tr) {
	        t[v] += add;
	    } else {
	        int tm = (tl + tr) / 2;
	        update(v*2, tl, tm, l, min(r, tm), add);
	        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
	    }
	}
	int get(int v, int tl, int tr, int pos) {
	    if (tl == tr)
	        return t[v];
	    int tm = (tl + tr) / 2;
	    if (pos <= tm)
	        return t[v] + get(v*2, tl, tm, pos);
	    else
	        return t[v] + get(v*2+1, tm+1, tr, pos);
	}
};

int main(){
	fastio;

	int n;
	cin>>n;
	priority_queue<pair<int,p32>> q;
	vector<pair<p32,int>> a, b;
	priority_queue<p32> storesmin, storesmax;
	forn(i,n){
		int sa,sb,ea,eb;
		cin>>sa>>ea>>sb>>eb;
		a.pb(mp(mp(sa,ea),i));
		b.pb(mp(mp(sb,eb),i));
		q.push(mp(-a[i].fi.fi,mp(1,i)));
		q.push(mp(-a[i].fi.se,mp(0,i)));
	}
	stack<int> minc;
	int mi = 1e9, ma = 0;
	bool p = 1;
	int done[n] = {0};
	while(!q.empty()){
		auto t = q.top();
		q.pop();
		if(t.se.fi == 0){
			done[t.se.se] = 1;
			while(storesmin.size()>0){
				auto t = storesmin.top();
				if(done[t.se] == 0) break;
				storesmin.pop();
			}
			if(storesmin.size()>0){
				auto t = storesmin.top();
				mi = -t.fi;
			}
			else{
				mi = 1e9;
			}
			while(storesmax.size()>0){
				auto t = storesmax.top();
				if(done[t.se] == 0) break;
				storesmax.pop();
			}
			if(storesmax.size()>0){
				auto t = storesmax.top();
				ma = t.fi;
			}
			else{
				ma = 0;
			}
			if(ma > mi) p = 0;
		}
		else{
			int ind = t.se.se;
			storesmin.push(mp(-b[ind].fi.se,ind));
			storesmax.push(mp(b[ind].fi.fi,ind));
			ma = storesmax.top().fi;
			mi = -storesmin.top().fi;
			if(ma>mi) p = 0;
		}
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	v32 v1,v2;
	forn(i,n){
		v1.pb(a[i].fi.fi);
		v2.pb(b[i].fi.fi);
	}
	Segtree s1(n),s2(n);
	int a1[n] = {0}, a2[n] = {0};

	forn(i,n){
		a1[a[i].se] = s1.get(1,0,n-1,i);
		auto it = upper_bound(v1.begin(),v1.end(),a[i].fi.se)-v1.begin();
		if(it == 0) continue;
		it--;
		a1[a[i].se] += it-i;
		s1.update(1,0,n-1,0,it,1);
	}
	forn(i,n){
		a2[b[i].se] = s2.get(1,0,n-1,i);
		auto it = upper_bound(v2.begin(),v2.end(),b[i].fi.se)-v2.begin();
		if(it == 0) continue;
		it--;
		a2[b[i].se] += it-i;
		s2.update(1,0,n-1,0,it,1);
	}

	forn(i,n){
		// cout<<i<<" "<<a1[i]<<" "<<a2[i]<<ln;
		if(a1[i] != a2[i]) p = 0;
	}
	if(p) cout<<"YES"<<ln;
	else cout<<"NO"<<ln;

	return 0;
}