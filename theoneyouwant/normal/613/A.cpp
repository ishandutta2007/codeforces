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

pair<double, double> findFoot(double a, double b, double c, 
                              double x1, double y1) {
// { 	cout<<a<<" "<<b<<" "<<c<<" "<<x1<<" "<<y1<<ln;
    double temp = -1 * (a * x1 + b * y1 + c) / (a * a + b * b); 
    double x = temp * a + x1; 
    double y = temp * b + y1; 
    return make_pair(x, y); 
} 

int main(){
	fastio;

	int n;
	cin>>n;

	ld px, py;
	cin>>px>>py;

	ld v[n+1][2];

	ld maxdist = 0, mindist = 1e18;

	forn(i,n){
		cin>>v[i][0]>>v[i][1];
	}
	v[n][0] = v[0][0];
	v[n][1] = v[0][1];

	forsn(i,1,n+1){
		ld vx1[2][2];
		vx1[0][0] = v[i][0]-v[i-1][0];
		vx1[0][1] = v[i][1]-v[i-1][1];
		vx1[1][0] = v[i][0]-px;
		vx1[1][1] = v[i][1]-py;

		// ld ans = vx1[0][0]*vx1[1][0] + vx1[0][1]*vx1[1][1];
		// ans = abs(ans);
		// ans /= sqrt(vx1[0][0]*vx1[0][0]+vx1[0][1]*vx1[0][1]);
		// ans /= sqrt(vx1[1][0]*vx1[1][0]+vx1[1][1]*vx1[1][1]);
		// ans = abs(ans);
		// ld ang = acos(ans);
		// ang = sin(ang);
		// ld dist = sqrt(vx1[1][0]*vx1[1][0]+vx1[1][1]*vx1[1][1]);
		// dist *= ang;

		// ld slope1[2] = ()

		pair<ld,ld> ans = findFoot(vx1[0][1],-vx1[0][0],-v[i][0]*vx1[0][1]+v[i][1]*vx1[0][0],px,py);
		if(min(v[i][0],v[i-1][0]) <= ans.fi && ans.fi <= max(v[i][0],v[i-1][0])){
			// cout<<ans.fi<<" "<<ans.se<<ln;
			// cout<<"OK "<<v[i][0]<<" "<<v[i][1]<<" "<<v[i-1][0]<<" "<<v[i-1][1]<<ln;
			ld dist = sqrt((ans.fi-px)*(ans.fi-px) + (ans.se-py)*(ans.se-py));
			mindist = min(mindist, dist);
		}
		
	}

	forn(i,n+1){
		ld dist = sqrt((v[i][0]-px)*(v[i][0]-px)+(v[i][1]-py)*(v[i][1]-py));
		maxdist = max(maxdist, dist);
		mindist = min(mindist,dist);
	}

	// cout<<maxdist<<" "<<mindist<<ln;

	cout<<fixed<<setprecision(10);	
	cout<<acos(-1)*(maxdist*maxdist-mindist*mindist)<<ln;

	return 0;
}