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
const int LIM=5e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool basis[LIM];
int nxt[LIM];
pair<p32,int> all_vec[LIM];

int find(int x){
	if(nxt[x] == -1) return x;
	if(x == nxt[x]) return x;
	return nxt[x] = find(nxt[x]);
}

ll fastpow(ll a, ll p){
	if(p == 0) return 1;
	ll z = fastpow(a,p/2);
	z = (z*z)%MOD;
	if(p%2) z = (a*z)%MOD;
	return z;
}

int main(){
	fastio;

	int n, m;
	cin>>n>>m;
	
	// vv32 all_vec;

	forn(i,n){
		v32 v;
		int k; 
		cin>>k;
		forn(i,k){
			int pos;
			cin>>pos;
			v.pb(pos);
		}
		sort(all(v));
		if(k == 1) v.pb(MOD);
		v.pb(i+1);
		// all_vec.pb(v);
		all_vec[i] = mp(mp(v[0],v[1]),v[2]);
	}
	// sort(all_vec,all_vec+n);
	// reverse(all_vec,all_vec+n);

	forn(i,LIM){
		basis[i] = 0; // nothing here so far
		nxt[i] = i; // go to this position if this is occupied
					// if this is -1, this bit is done for
	}
	v32 inc;
	forn(i,n){
		int bit_1 = all_vec[i].fi.fi;
		int bit_2 = all_vec[i].fi.se;
		int ind = all_vec[i].se;
		int n1 = find(bit_1);
		int n2 = MOD;
		if(bit_2<MOD) n2 = find(bit_2);
		if(n1 == n2) continue;
		if(n1>n2) swap(n1,n2);
		if(basis[n1]==0){
			basis[n1] = 1;
			if(n2<MOD) nxt[n1] = n2;
			else nxt[n1] = -1;
			inc.pb(ind);
			continue;
		}
		// n1 removed
		// only n2 left
		if(n2 == MOD) continue;
		if(basis[n2]==0){
			basis[n2] = 1;
			nxt[n2] = -1;
			inc.pb(ind);
			continue;
		}
	}

	int num = inc.size();
	cout<<fastpow(2,num)<<" "<<num<<ln;
	sort(all(inc));
	forstl(r,inc) cout<<r<<" ";
	cout<<ln;

	// cout<<all_vec<<ln;

	return 0;
}