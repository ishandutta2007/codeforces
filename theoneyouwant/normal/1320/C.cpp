//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int ll
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
const int MAXN = 2*1e5+5;

int n;
p64 t[4*MAXN];

void build(ll a[], int v, int tl, int tr) { 

//Call this with original array a, v=1, tl=0, tr=n-1

    if (tl == tr) {
        t[v].fi = a[tl];
        t[v].se = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v].fi = t[v*2].fi + t[v*2+1].fi;
        t[v].se = max(t[v*2].se,t[v*2].fi+t[v*2+1].se);
        // CHANGE TO t[v] = 0 if using lazy propagation
    }
}

p64 sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return mp(-MOD,-MOD);
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    auto t1 = sum(v*2, tl, tm, l, min(r, tm));
   	auto t2 = sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    return mp(t1.fi+t2.fi,max(t1.se,t1.fi+t2.se));
}

void update(ll v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v].fi += new_val;
        t[v].se += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v].fi = t[v*2].fi + t[v*2+1].fi;
        t[v].se = max(t[v*2].se,t[v*2].fi+t[v*2+1].se); 	
    }
}


signed main(){
	fastio;

	int n,m,p; cin>>n>>m>>p;

	ll cos1 = MOD, cos2 = MOD;

	map<int,int> w;
	forn(i,n){
		int a,c; 
		cin>>a>>c;
		if(w[a] == 0) w[a] = MOD;
		w[a] = min(w[a],c);
		cos1 = min(cos1,c);
	}
	vp64 temp;
	forstl(r,w){
		temp.pb(r);
	}
	sort(temp.begin(),temp.end(),greater<p64>());
	ll last = MOD;
	vp64 att;
	int upd[n] = {0};
	int cnt = 0;
	forstl(r,temp){
		if(r.se>last) continue;
		att.pb(mp(r.fi,r.se));
		last = r.se; 
	}
	sort(att.begin(),att.end());
	int diff = 0;
	forn(i,att.size()){
		upd[i] = diff-att[i].se;
		diff = att[i].se;
	}
	build(upd,1,0,n-1);
	
	w.clear();
	vp64 def;
	ll cst = 0;

	forn(i,m){
		ll b,c; 
		cin>>b>>c;
		if(w[b] == 0) w[b] = MOD;
		w[b] = min(w[b],c);
		cos2 = min(cos2,c);
	}
	temp.clear();
	forstl(r,w){
		temp.pb(r);
	}
	sort(temp.begin(),temp.end(),greater<p64>());
	last = MOD;
	forstl(r,temp){
		if(r.se>last) continue;
		def.pb(mp(r.fi,r.se));
		last = r.se;
	}
	sort(def.begin(),def.end());

	vector<pair<p64,ll>> monster;
	forn(i,p){
		ll x,y,z;
		cin>>x>>y>>z;
		monster.pb(mp(mp(y,x),z));
	}
	sort(monster.begin(),monster.end());
	ll ans = -(cos1+cos2);
	ll mx = 0;
	// cout<<att<<ln;
	forn(i,p){
		// cout<<monster[i]<<ln;
		ll cost = 0;
		auto t = upper_bound(def.begin(),def.end(),mp(monster[i].fi.fi,MOD));
		if(t == def.end()) continue;
		// cout<<(*t)<<ln;
		cost = -(*t).se;
		mx = monster[i].fi.se;
		auto t2 = upper_bound(att.begin(),att.end(),mp(mx,MOD))-att.begin();
		if(t2<att.size()){
			// cout<<"OK"<<ln;
			update(1,0,n-1,t2,monster[i].se);
		}
		// cout<<sum(1,0,n-1,0,n-1).se<<ln;
		cost += sum(1,0,n-1,0,n-1).se;
		ans = max(ans,cost);

	}

	cout<<ans<<ln;

	return 0;
}