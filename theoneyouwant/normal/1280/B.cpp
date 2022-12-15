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

int link[LIM] = {0};
int sz[LIM] = {0};
int r,c;

int conv(int a, int b){
	return a*c+b;
}

int find(int x){
	if(x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(sz[a]<sz[b]) swap(a,b);
	if(a == b) return;
	sz[a]+=sz[b];
	link[b] = a;
}

int main(){
	fastio;
	int tests;
	cin>>tests;
	
	while(tests--){

		cin>>r>>c;

		forn(i,r*c) link[i] = i;
		forn(i,r*c) sz[i] = 1;

		int mat[r][c];
		bool p = 0;
		forn(i,r){
			forn(j,c){
				char k;
				cin>>k;
				if(k == 'P') mat[i][j] = 0;
				else mat[i][j] = 1;
				if(mat[i][j] == 1) p=1;
			}
		}

		forn(i,r){
			forn(j,c){
				if(mat[i][j] == 1){
					if(i+1<r && mat[i+1][j] == 1){
						unite(conv(i,j),conv(i+1,j));
					}
					if(j+1<c && mat[i][j+1] == 1){
						unite(conv(i,j+1),conv(i,j));
					}
				}
			}
		}

		bool ok = 0;
		int sum1 = 0, sum2 = 0;
		
		forn(i,c){
			if(mat[0][i] == 1) sum1++;
			if(mat[r-1][i] == 1) sum2++;
		}
		
		if(sum1 == c || sum2 == c) ok = 1;
		sum1 = 0, sum2 = 0;
		
		forn(j,r){
			if(mat[j][0] == 1) sum1++;
			if(mat[j][c-1] == 1) sum2++;
		}
		if(sum1 == r || sum2 == r) ok = 1;
		// cout<<ok<<ln;
		if(p == 0){
			cout<<"MORTAL"<<ln;
		}
		else if(sz[find(0)] == r*c){
			cout<<0<<ln;
		}
		else if(r>1 && c>1 && ok == 1){
			cout<<1<<ln;
		}
		else if(r == 1 && mat[0][0] == 1){
			cout<<1<<ln;
		}
		else if(r == 1 && mat[0][c-1] == 1){
			cout<<1<<ln;
		}
		else if(c == 1 && mat[0][0] == 1){
			cout<<1<<ln;
		}
		else if(c == 1 && mat[r-1][0] == 1){
			cout<<1<<ln;
		}
		else{

			bool ch = 0;
			forn(i,r){
				int tot = 0;
				forn(j,c){
					tot += mat[i][j];
				}
				if(tot == c) ch = 1;
			}
			forn(j,c){
				int tot = 0;
				forn(i,r){
					tot += mat[i][j];
				}
				if(tot == r) ch = 1;
			}

			if(ch) cout<<2<<ln;
			else if(mat[0][0] == 1 || mat[0][c-1] == 1 || mat[r-1][0] == 1 || mat[r-1][c-1] == 1) cout<<2<<ln;
			else{
				bool done = 0;
				forn(i,c){
					if(mat[0][i] == 1) done = 1;
					if(mat[r-1][i] == 1) done = 1;
				}
				forn(j,r){
					if(mat[j][0] == 1) done = 1;
					if(mat[j][c-1] == 1) done = 1;
				}
				if(done) cout<<3<<ln;
				else cout<<4<<ln;
			}
		}

	}

	return 0;
}