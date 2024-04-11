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

	int a[n][n];
	forn(i,n){
		forn(j,n){
			a[i][j] = -1;
		}
	}
	a[0][0] = 1;
	a[n-1][n-1] = 0;

	forn(i,n){
		forn(j,n){
			if((i+j)%2 != 0) continue;
			if(a[i][j] != -1) continue;	
			if(i >= 2){
				cout<<"? "<<i-1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<ln;
				int x;
				cin>>x;
				if(x == 1){
					a[i][j] = a[i-2][j];
				}
				else{
					a[i][j] = 1-a[i-2][j];
				}
			}
			else if(j >= 2){
				cout<<"? "<<i+1<<" "<<j-1<<" "<<i+1<<" "<<j+1<<ln;
				int x;
				cin>>x;
				if(x == 1){
					a[i][j] = a[i][j-2];
				}
				else{
					a[i][j] = 1-a[i][j-2];
				}
			}
			else if(i>=1 && j>=1){
				cout<<"? "<<i<<" "<<j<<" "<<i+1<<" "<<j+1<<ln;
				int x;
				cin>>x;
				if(x == 1){
					a[i][j] = a[i-1][j-1];
				}
				else{
					a[i][j] = 1-a[i-1][j-1];
				}
			}
		}
	}

	p32 p1, p2;
	bool f = 0;

	forn(i,n){
		forn(j,n){
			if(a[i][j] == -1) continue;
			if(i >= 2 && j >= 2){
				if(a[i-2][j-2] == 1-a[i][j]){
					p1 = mp(i-2,j-2);
					p2 = mp(i,j);
					f = 1;
					break;
				}
			}
		}
	}

	int p3;
	int ans;

	cout<<"? "<<p1.fi+1<<" "<<p1.se+2<<" "<<p2.fi+1<<" "<<p2.se+1<<ln;
	int ok;
	cin>>ok;
	if(ok == 1){
		p3 = p1.fi*n+p1.se+1;
		ans = a[p2.fi][p2.se];
	}
	else{
		cout<<"? "<<p1.fi+1<<" "<<p1.se+1<<" "<<p2.fi<<" "<<p2.se+1<<ln;
		cin>>ok;
		if(ok == 1){
			p3 = (p2.fi-1)*n+p2.se;
			ans = a[p1.fi][p1.se];
		}
		else{
			if(a[p1.fi][p1.se] == a[p1.fi+2][p1.se]){
				p3 = (p2.fi-1)*n+p2.se;
				ans = 1-a[p1.fi][p1.se];
			}
			else{
				p3 = p1.fi*n+p1.se+1;
				ans = 1-a[p2.fi][p2.se];
			}
		}
	}	

	v32 adj[n*n];

	forn(i,n){
		forn(j,n){
			if((i+j)%2 == 0) continue;
			if(a[i][j]!=-1) continue;
			if(i >= 2){
				adj[(i)*n+j].pb((i-2)*n+j);
				adj[(i-2)*n+j].pb(i*n+j);
			}
			if(j >= 2){
				adj[(i)*n+j].pb((i)*n+j-2);
				adj[(i)*n+j-2].pb(i*n+j);
			}
			if(i + 2 < n){
				adj[(i)*n+j].pb((i+2)*n+j);
				adj[(i+2)*n+j].pb(i*n+j);
			}
			if(j + 2 < n){
				adj[(i)*n+j].pb((i)*n+j+2);
				adj[(i)*n+j+2].pb(i*n+j);
			}
			if(i >= 1 && j >= 1){
				adj[(i)*n+j].pb((i-1)*n+j-1);
				adj[(i-1)*n+j-1].pb(i*n+j);
			}
			if(i+1 <n && j+1<n){
				adj[(i)*n+j].pb((i+1)*n+j+1);
				adj[(i+1)*n+j+1].pb(i*n+j);
			}
		}
	}

	bool visited[n*n] = {0};

	a[p3/n][p3%n] = ans;

	visited[p3] = 1;
	queue<pair<int,int> > q;
	q.push(mp(p3, -1));

	while(!q.empty()){
		int t = q.front().fi;
		int par = q.front().se;
		q.pop();

		if(par != -1){
			if(t < par) cout<<"? "<<(t/n) +1<<" "<<(t%n) + 1<<" "<<(par/n) +1<<" "<<(par%n)+1<<ln;
			else cout<<"? "<<(par/n)+1<<" "<<(par%n)+1<<" "<<(t/n)+1<<" "<<(t%n)+1<<ln;
			int x;
			cin>>x;
			if(x == 0)  a[t/n][t%n] = 1-a[par/n][par%n];
			else a[t/n][t%n] = a[par/n][par%n];
		}

		forstl(r,adj[t]){
			if(visited[r]) continue;
			visited[r] = 1;
			q.push(mp(r,t));
		}
	}

	cout<<"!"<<ln;
	forn(i,n){
		forn(j,n){
			cout<<a[i][j];
		}
		cout<<ln;
	}

	return 0;
}