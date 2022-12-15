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

int main(){
	fastio;
	
	int n, k;
	cin>>n>>k;

	bool done[k] = {0};
	bool taken[n] = {0};
	int f1[k], f2[k];

	v32 v[n];
	forn(i,k){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		f1[i] = x;
		f2[i] = y;
		v[x].pb(i);
		v[y].pb(i);
	}

	int ans = 0;

	// cout<<"OK"<<endl;

	forn(i,k){
		if(!done[i]){
			queue<int> q;
			q.push(i);
			done[i] = 1;
			while(!q.empty()){
				bool b = 0;
				int t = q.front();
				q.pop();
				if(taken[f1[t]] == 0){
					taken[f1[t]] = 1;
					b = 1;
					forstl(r,v[f1[t]]){
						if(done[r]) continue;
						done[r] = 1;
						q.push(r);
					}
				}
				if(taken[f2[t]] == 0){
					taken[f2[t]] = 1;
					b = 1;
					forstl(r,v[f2[t]]){
						if(done[r]) continue;
						done[r] = 1;
						q.push(r);
					}
				}
				if(b == 0) {
					ans++;
				}
			}

		}
	}

	cout<<ans<<ln;

	return 0;
}