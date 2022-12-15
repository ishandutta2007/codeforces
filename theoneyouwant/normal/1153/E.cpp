//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define leadzero(a) __builtin_clz(a) // count leading zeroes
#define trailzero(a) __builtin_ctz(a) // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln endl
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it<<ln;} cerr<<endl
#define dbgstlp32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cerr<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
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
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const ll MOD = 1e9+7, LIM = 1e5+5;
const ld EPS = 1e-9;
ll t,n,m,k,x,y;
int main(){
	fastio;
	
	cin>>n;

	v32 rows, columns;

	forn(i,n){
		cout<<"? "<<i+1<<" "<<1<<" "<<i+1<<" "<<n<<ln;
		int x;
		cin>>x;
		if(x%2==1) rows.pb(i+1);
		if(i==n-2 && rows.size()==0) break;
	}
	forn(i,n){
		cout<<"? "<<1<<" "<<i+1<<" "<<n<<" "<<i+1<<ln;
		int x;
		cin>>x;
		if(x%2==1) columns.pb(i+1);
		if(i==n-2 && columns.size()==0) break;
	}


	if(rows.size()==2 && columns.size()==0){
	
		int r1 = 1, r2 = n;
		int mid;
		while(true){
			mid = (r1+r2)/2;
			if(r1==r2) break;
			cout<<"? "<<rows[0]<<" "<<r1<<" "<<rows[0]<<" "<<mid<<ln;
			int x;
			cin>>x;
			if(x%2==0) r1 = mid+1;
			else r2 = mid;
		} 
		int ans1 = mid;

		r1 = 1; r2 = n;
		while(true){
			mid = (r1+r2)/2;
			if(r1==r2) break;
			cout<<"? "<<rows[1]<<" "<<r1<<" "<<rows[1]<<" "<<mid<<ln;
			int x;
			cin>>x;
			if(x%2==0) r1 = mid+1;
			else r2 = mid;
		} 
		int ans2 = mid;
		cout<<"! "<<rows[0]<<" "<<ans1<<" "<<rows[1]<<" "<<ans2<<ln;
	}

	else if (rows.size()==0 && columns.size()==2){

		int r1 = 1, r2 = n;
		int mid;
		while(true){
			mid = (r1+r2)/2;
			if(r1==r2) break;
			cout<<"? "<<r1<<" "<<columns[0]<<" "<<mid<<" "<<columns[0]<<ln;
			int x;
			cin>>x;
			if(x%2==0) r1 = mid+1;
			else r2 = mid;
		} 
		int ans1 = mid;

		r1 = 1; r2 = n;
		while(true){
			mid = (r1+r2)/2;
			if(r1==r2) break;
			cout<<"? "<<r1<<" "<<columns[1]<<" "<<mid<<" "<<columns[1]<<ln;
			int x;
			cin>>x;
			if(x%2==0) r1 = mid+1;
			else r2 = mid;
		} 
		int ans2 = mid;
		cout<<"! "<<ans1<<" "<<columns[0]<<" "<<ans2<<" "<<columns[1]<<ln;

	}

	else if(rows.size()==2 && columns.size()==2){

		vp32 answs;
		forstl(r,rows){
			forstl(k,columns){
				cout<<"? "<<r<<" "<<k<<" "<<r<<" "<<k<<ln;
				int x;
				cin>>x;
				if(x%2==1) answs.pb(mp(r,k));
			}
		}
		cout<<"! ";
		cout<<answs[0].fi<<" "<<answs[0].se<<" "<<answs[1].fi<<" "<<answs[1].se<<ln;
	}

	return 0;
}