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

int main(){
	fastio;
	int n;
	cin>>n;
	int sz = n*n;
	int a[sz];
	v32 fours,twos,ones;
	forn(i,sz) cin>>a[i];
	map<int,int> m;
	forn(i,sz) m[a[i]]++;
	vp32 v;
	forstl(r,m){
		//cout<<r.fi<<" "<<r.se<<ln;
		v.pb(mp(r.se,r.fi));
	}
	bool possible=1;
	forn(i,sz) a[i]=0;
	sort(v.begin(),v.end(),greater<p32>());
	int curr = 0;
	forstl(r,v){
		//cout<<r.fi<<" "<<r.se<<ln;
		while(r.fi%2!=0){
			ones.pb(r.se);
			r.fi--;
		}
		while(r.fi%4!=0){
			twos.pb(r.se);
			r.fi--;
			r.fi--;
		}
		while(r.fi!=0){
			fours.pb(r.se);
			r.fi-=4;
		}
	}
	//cout<<fours.size()<<ln;
	//sort(a,a+sz);
	//forn(i,sz) cout<<a[i]<<" ";
	int mat[n][n]={0};
	forn(i,n) forn(j,n) mat[i][j]=0;
	int p1=0,p2=0,p4=0;
	forn(i,n){
		forn(j,n){
			//cout<<i<<" "<<j<<" "<<p<<ln;
			if(mat[i][j]!=0) continue;
			if(i==n-1-i && j==n-1-j){
				if(p1!=ones.size()){
					mat[i][j] = ones[p1];
					p1++;
				}
				else possible=0;
				continue;
			}
			if(i==n-1-i){
				if(p2!=twos.size()){
					mat[i][j] = twos[p2];
					mat[i][n-1-j] = twos[p2];
					p2++;
				}
				else if(p4!=fours.size()){
					mat[i][j] = fours[p4];
					mat[i][n-1-j] = fours[p4];
					twos.pb(fours[p4]);
					p4++;
				}
				else possible=0;
				continue;
			}
			else if(j==n-1-j) {
				if(p2!=twos.size()){
					mat[i][j] = twos[p2];
					mat[n-1-i][j] = twos[p2];
					p2++;
				}
				else if(p4!=fours.size()){
					mat[i][j] = fours[p4];
					mat[n-1-i][j] = fours[p4];
					twos.pb(fours[p4]);
					p4++;
				}
				else possible=0;
				continue;
			}
			else{
				if(p4!=fours.size()){
					mat[i][j] = fours[p4];
					mat[n-1-i][j] = fours[p4];
					mat[i][n-1-j] = fours[p4];
					mat[n-1-i][n-1-j] = fours[p4];
					p4++;
				}
				else possible=0;
				continue;
			}
		}
	}
	if(possible){
		cout<<"YES"<<ln;
		forn(i,n){
			forn(j,n){
				cout<<mat[i][j]<<" ";
			}
			cout<<ln;
		}
	}
	else{
		cout<<"NO"<<ln;
	}
	return 0;
}