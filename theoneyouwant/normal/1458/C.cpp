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
const int LIM=1e3+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[LIM][LIM];

int n, m; 

void perform_i(){

	// cout<<"before"<<ln;
	// forn(i,n){
	// 	forn(j,n){
	// 		cout<<a[i][j]+1<<" ";
	// 	}
	// 	cout<<ln;
	// }
	// cout<<"OK"<<ln;
	forn(i,n){
		int p[n] = {0};
		forn(j,n){
			p[a[i][j]] = j;
		}
		forn(j,n){
			a[i][j] = p[j];
		}
	}

	// cout<<"after"<<ln;
	// forn(i,n){
	// 	forn(j,n){
	// 		cout<<a[i][j]+1<<" ";
	// 	}
	// 	cout<<ln;
	// }
	// cout<<ln;

	return;
}

void perform_c(){
	// cout<<"Ok"<<ln;
	forn(j,n){
		int p[n] = {0};
		forn(i,n){
			p[a[i][j]] = i;
		}
		forn(i,n){
			a[i][j] = p[i];
		}
	}

	return;
}

int main(){
	fastio;
	int tests = 1;
	cin>>tests;
	
	while(tests--){

		cin>>n>>m;
		forn(i,n){
			forn(j,n){
				cin>>a[i][j];
				a[i][j]--;
			}
		}
		int l = 0, r = 0, u = 0, d = 0, plus = 0, minus = 0;
		string s; cin>>s;
		stack<char> st;
		forn(i,m){
			if(s[i] == 'L'){
				l++;
			}
			else if(s[i] == 'U'){
				u++;
			}
			else if(s[i] == 'R'){
				l--;
			}
			else if(s[i] == 'D'){
				u--;
			}
			else if(s[i] == 'I'){
				if(!st.empty() && st.top() == s[i]){
					st.pop();
				}
				else if(st.size()>=11){
					forn(j,11) st.pop();
				}
				else{
					st.push(s[i]);
				}

				int t2 = minus;
				minus = l;
				l = t2;
			}
			else if(s[i] == 'C'){
				if(!st.empty() && st.top() == s[i]){
					st.pop();
				}
				else if(st.size()>=11){
					forn(j,11) st.pop();
				}
				else{
					st.push(s[i]);
				}
				int t2 = minus;
				minus = u;
				u = t2;
			}
		}

		stack<char> q;
		while(!st.empty()){
			auto t = st.top();
			st.pop();
			q.push(t);
		}
		while(!q.empty()){
			auto t = q.top();
			q.pop();
			if(t == 'I') perform_i();
			else if(t == 'C') perform_c();
		}

		// forn(i,n){
		// 	forn(j,n) cout<<a[i][j]+1<<" ";
		// 	cout<<ln;
		// }
		// cout<<"This was before "<<ln;

		// cout<<minus<<ln;
		forn(i,n){
			forn(j,n){
				a[i][j] = ((a[i][j] - minus)%n + n)%n;
			}
		}
		int ans[n][n];
		int left = l, down = u;
		// cout<<left<<" "<<down<<ln;
		forn(i,n){
			forn(j,n){
				int nx = (((i + down) % n) + n) % n;
				int ny = (((j + left) % n) + n) % n;
				ans[i][j] = a[nx][ny];
			}
		}
		forn(i,n){
			forn(j,n){
				cout<<1 + ans[i][j]<<" ";
			}
			cout<<ln;
		}
	}

	return 0;
}