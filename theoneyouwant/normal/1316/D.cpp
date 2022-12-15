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
const int LIM=1e3+5,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n; 
p32 dest[LIM][LIM];
map<p32,vp32> m;
int target = -1;
bool visited[LIM][LIM];
int height[LIM][LIM];
int degre[LIM][LIM];

int conv(int a,int b){
	return n*a+b;
}

int conv(p32 a){
	return n*a.fi+a.se;
}

int main(){
	fastio;

	cin>>n;
	forn(i,n){
		forn(j,n){
			int x,y; cin>>x>>y;
			if(x!=-1 && y!=-1){
				x--; y--;
			}
			dest[i][j] = mp(x,y);
		}
	}

	char mat[n][n];

	forn(i,n){
		forn(j,n){
			mat[i][j] = '1';
		}
	}

	bool p = 1;

	priority_queue<pair<int, p32>> q1;

	forn(i,n){
		forn(j,n){
			if(p == 0) continue;
			if(dest[i][j].fi == -1){
				int deg = 0;
				if(i+1<n && dest[i+1][j].fi == -1){
					deg++;
				}
				if(i>0 && dest[i-1][j].fi == -1){
					deg++;
				}
				if(j+1<n && dest[i][j+1].fi == -1){
					deg++;
				}
				if(j>0 && dest[i][j-1].fi == -1){
					deg++;
				}
				degre[i][j] = deg;
				q1.push(mp(-deg,mp(i,j)));
				continue;
			}
			if(dest[i][j] == mp(i,j)){
				mat[i][j] = 'X';
				continue;
			}
			m[dest[i][j]].pb(mp(i,j));
		}
	}

	while(!q1.empty()){
		auto t = q1.top();
		q1.pop();
		if(mat[t.se.fi][t.se.se] != '1') continue;
		int i = t.se.fi, j = t.se.se;
		if(i+1<n && dest[i+1][j].fi == -1 && mat[i+1][j] == '1'){
			mat[i][j] = 'D';
			mat[i+1][j] = 'U';
		}
		else if(i>0 && dest[i-1][j].fi == -1 && mat[i-1][j] == '1'){
			mat[i][j] = 'U';
			mat[i-1][j] = 'D';
		}
		else if(j+1<n && dest[i][j+1].fi == -1 && mat[i][j+1] == '1'){
			mat[i][j] = 'R';
			mat[i][j+1] = 'L';
		}
		else if(j>0 && dest[i][j-1].fi == -1 && mat[i][j-1] == '1'){
			mat[i][j] = 'L';
			mat[i][j-1] = 'R';
		}
		else{
			if(i+1<n && dest[i+1][j].fi == -1){
				mat[i][j] = 'D';
			}
			else if(i>0 && dest[i-1][j].fi == -1){
				mat[i][j] = 'U';
			}
			else if(j+1<n && dest[i][j+1].fi == -1){
				mat[i][j] = 'R';
			}
			else if(j>0 && dest[i][j-1].fi == -1){
				mat[i][j] = 'L';
			}
			else{
				p = 0;
				break;
			}
		}
		if(i+1<n && dest[i+1][j].fi == -1 && mat[i+1][j] == '1'){
			degre[i+1][j]--;
			q1.push(mp(-degre[i+1][j],mp(i+1,j)));
		}
		else if(i>0 && dest[i-1][j].fi == -1 && mat[i-1][j] == '1'){
			degre[i-1][j]--;
			q1.push(mp(-degre[i-1][j],mp(i-1,j)));
		}
		else if(j+1<n && dest[i][j+1].fi == -1 && mat[i][j+1] == '1'){
			degre[i][j+1]--;
			q1.push(mp(-degre[i][j+1],mp(i,j+1)));
		}
		else if(j>0 && dest[i][j-1].fi == -1 && mat[i][j-1] == '1'){
			degre[i][j-1]--;
			q1.push(mp(-degre[i][j-1],mp(i,j-1)));
		}
	}

	forstl(r,m){
		if(p == 0) continue;
		priority_queue<pair<int,p32>> q;
		q.push(mp(0,r.fi));
		visited[r.fi.fi][r.fi.se] = 1;
		int target = conv(r.fi.fi,r.fi.se);
		while(!q.empty()){
			auto t = q.top();
			q.pop();
			int i = t.se.fi;
			int j = t.se.se;
			height[i][j] = -t.fi;
			if(i+1<n){
				if(conv(dest[i+1][j]) == target && visited[i+1][j] == 0){
					visited[i+1][j] = 1;
					q.push(mp(t.fi-1,mp(i+1,j)));
				}
			}
			if(i>0){
				if(conv(dest[i-1][j]) == target && visited[i-1][j] == 0){
					visited[i-1][j] = 1;
					q.push(mp(t.fi-1,mp(i-1,j)));
				}
			}
			if(j+1<n){
				if(conv(dest[i][j+1]) == target && visited[i][j+1] == 0){
					visited[i][j+1] = 1;
					q.push(mp(t.fi-1,mp(i,j+1)));
				}
			}
			if(j>0){
				if(conv(dest[i][j-1]) == target && visited[i][j-1] == 0){
					visited[i][j-1] = 1;
					q.push(mp(t.fi-1,mp(i,j-1)));
				}
			}
		}
		forstl(k,r.se){
			int i = k.fi, j = k.se;
			if(i+1<n){
				if(conv(dest[i+1][j]) == target && height[i+1][j] == height[i][j]-1){
					mat[i][j] = 'D';
				}
			}
			if(i>0){
				if(conv(dest[i-1][j]) == target && height[i-1][j] == height[i][j]-1){
					mat[i][j] = 'U';
				}
			}
			if(j+1<n){
				if(conv(dest[i][j+1]) == target && height[i][j+1] == height[i][j]-1){
					mat[i][j] = 'R';
				}
			}
			if(j>0){
				if(conv(dest[i][j-1]) == target && height[i][j-1] == height[i][j]-1){
					mat[i][j] = 'L';
				}
			}
			if(mat[i][j] == '1') p = 0;
		}
	}

	// p = 1;
	forn(i,n){
		forn(j,n){
			if(mat[i][j] == '1') p = 0;
		}
	}
	// p = 1;	

	if(p){
		cout<<"VALID"<<ln;
		forn(i,n){
			forn(j,n){
				cout<<mat[i][j];
			}
			cout<<ln;
		}
	}
	else{
		cout<<"INVALID"<<ln;
	}

	return 0;
}