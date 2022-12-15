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

void query_dist(int val){
	vp32 v;
	forsn(i,1,201){
		if(i%val!=0) continue;
		forsn(j,1,201){
			v.pb({i,j});
		}
	}
	cout << "? " << v.size() << ln;
	forstl(r,v) cout << r.fi << " " << r.se << ln;
}

int main(){
	fastio;

	query_dist(1);

	int tot;
	cin >> tot;

	v32 div;	
	forsn(i,2,tot){
		if(tot%i==0) div.pb(i);
	}

	// div are the possible side values (x+1)
	// also need (y+1); (x+1) * (y+1) = tot
	// answer will be 2x+2y
	
	int l = 1, r = 7;
	int keep[8] = {0};
	int mdiv = 0;

	forn(iter, 3){
		int mid = (l + r) / 2;
		query_dist(1<<mid);
		int ans; cin >> ans;
		keep[mid] = ans;
		if(ans*(1<<mid) == tot){
			mdiv = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}

	// cout << mdiv << ln;

	v32 chk;

	int m1 = (1<<mdiv);
	int m2 = (1<<(mdiv+1));

	forstl(r,div){
		if(r%m1 == 0){
			if(r%m2 != 0){
				chk.pb(r);
			}
		}
	}

	int ans;

	forstl(r, chk){
		int oth = tot / r;
		if(keep[mdiv+1] == oth * (r / m2)){
			ans = r;
		}
		if(keep[mdiv+1] == oth * ((r / m2) + 1)){
			ans = r;
		}
	}

	int oth = tot / ans;

	// cout << ans << " " << oth << ln;

	if(mdiv == 7){
		// one side is just 128
		ans = 128;
		oth = tot / ans;
	}

	cout << "! " << (oth + ans - 2) * 2 << ln;

	return 0;
}