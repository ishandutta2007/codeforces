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
#define ln endl
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


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int q = 0;

bool askq(v32 x){

	q++;

	if(q>82){
		// TLE
		forn(i, MOD){
			cerr << "OOPS" << ln;
		}
	}

	cout << "? " << x.size() << " ";
	forstl(r, x) cout << r << " ";
	cout << ln;

	string ans;
	cin >> ans;
	if(ans=="YES") return 1;
	return 0;
}

bool check(int val){

	cout << "! " << val << ln;
	string s; cin >> s;
	if(s == ":)") return 1;
	return 0;
}

void solve(v32 a){
	if(a.size()<=2){
		forstl(r, a){
			if(check({r})) return;
		}
		return;
	}
	if(a.size()<=3){
		bool ch = askq({a[0], a[1]});
		if(ch==0){
			// answered NO for {0, 1}
			if(check({a[2]})) return;
			// must be truthful
			bool ch1 = askq({a[0]});
			if(ch1) check({a[0]});
			else check({a[1]});
			return;
		}
		bool ch2 = askq({a[2]});
		if(ch2==1){
			// answered YES for {2}
			if(check({a[2]})) return;
			// must be truthful
			bool ch1 = askq({a[0]});
			if(ch1) check({a[0]});
			else check({a[1]});
			return;
		}
		// answered YES for {0, 1} and NO for {2}
		if(check({a[0]})) return;
		check({a[1]});
		return;
	}

	v32 v[4];

	forn(i, a.size()){
		v[i%4].pb(a[i]);
	}

	v32 ask1, ask2;

	forstl(r, v[0]) ask1.pb(r);
	forstl(r, v[1]) ask1.pb(r);
	forstl(r, v[0]) ask2.pb(r);
	forstl(r, v[3]) ask2.pb(r);

	bool ch1 = askq(ask1);
	bool ch2 = askq(ask2);

	v32 na;

	if((ch1==1) && (ch2==1)){
		forn(i, 4){
			if(i==2) continue;
			forstl(r, v[i]) na.pb(r);
		}
	}
	if((ch1==1) && (ch2==0)){
		forn(i, 4){
			if(i==3) continue;
			forstl(r, v[i]) na.pb(r);
		}
	}
	if((ch1==0) && (ch2==1)){
		forn(i, 4){
			if(i==1) continue;
			forstl(r, v[i]) na.pb(r);
		}
	}
	if((ch1==0) && (ch2==0)){
		forn(i, 4){
			if(i==0) continue;
			forstl(r, v[i]) na.pb(r);
		}
	}
	return solve(na);
}


int main(){
	fastio;

	int n;
	cin >> n;

	v32 a;
	forsn(i,1,n+1) a.pb(i);

	solve(a);

	return 0;
}