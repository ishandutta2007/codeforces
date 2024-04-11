#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
template <class T>
struct SubMatrix {
	vector<vector<T>> p;
	SubMatrix(vector<vector<T>>& v) {
		int R = sz(v), C = sz(v[0]);
		p.assign(R+1, vector<T>(C+1));
		rep(r,R) rep(c,C)
			p[r+1][c+1] = v[r][c] + p[r][c+1] + p[r+1][c] - p[r][c];
	}
	T sum(int u, int l, int d, int r) {
		d++,r++;
		return p[d][r] - p[d][l] - p[u][r] + p[u][l];
	}
};
string s[1000009];
vector<vi> a,b;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	rep(i,n) cin>>s[i];
	int lo = 0,hi = 1000;
	a.resize(n,vi(m,0));
	b.resize(n,vi(m,0));
	rep(i,n) rep(j,m) if(s[i][j]=='X') b[i][j]=1;
	SubMatrix<int> S(b);
	rep(i,n) rep(j,m){
		int lo=0,hi=min({i,j,n-1-i,m-1-j});
		while(lo<hi){
			int mi = (lo+hi)/2+1;
			if(S.sum(i-mi,j-mi,i+mi,j+mi)==(2*mi+1)*(2*mi+1)){
				lo=mi;
			}
			else hi=mi-1;
		}
		if(s[i][j]=='X') a[i][j] = lo;
		else a[i][j]=-1;
	}
	while(lo<hi){
		int mi = (lo+hi)/2+1;
		rep(i,n) rep(j,m){
			if(a[i][j]>=mi){
				b[i][j]=1;
			}
			else b[i][j]=0;
		}
		SubMatrix<int> T(b);
		bool fg=0;
		rep(i,n) rep(j,m) if(s[i][j]=='.'){
			if(T.sum(max(0,i-mi),max(0,j-mi),min(n-1,i+mi),min(m-1,j+mi))){
					fg=1;
					break;
				}
		}
		else{
			if(T.sum(max(0,i-mi),max(0,j-mi),min(n-1,i+mi),min(m-1,j+mi))==0){
				fg=1;
				break;
			}
		}
		if(fg) hi=mi-1;
		else lo=mi;
	}
	cout<<lo<<'\n';
	rep(i,n) {
		rep(j,m) if(a[i][j]>=lo) cout<<"X"; else cout<<'.';
		cout<<'\n';
	}
	return 0;
}