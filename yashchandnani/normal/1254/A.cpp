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
string s[109];
int ans[109][109];
void solve(){
	int r,c,k;cin>>r>>c>>k;
	rep(i,r) cin>>s[i];
	int cnt=0;
	rep(i,r) rep(j,c) if(s[i][j]=='R') cnt++;
	int x1=cnt/k,x2=x1+1;
	int y2=cnt%k,y1=k-y2;
	int cur=0,ix=0;
	bool fg=0;
	rep(i,r) {
		if(i%2==0) rep(j,c){
			if(s[i][j]=='R'&&((cur+1>x1&&y1)||(cur+1>x2))){
				if(y1) y1--,ix++;
				else ix++;
				cur=1;
			}
			else if(s[i][j]=='R') cur++;
			ans[i][j] = ix;
		}
		else repD(j,c-1,0){
			if(s[i][j]=='R'&&((cur+1>x1&&y1)||(cur+1>x2))){
				if(y1) y1--,ix++;
				else ix++;
				cur=1;
			}
			else if(s[i][j]=='R') cur++;
			ans[i][j] = ix;
		}
	}
	rep(i,r){
		rep(j,c){
			if(ans[i][j]<10) cout<<char('0'+ans[i][j]);
			else if(ans[i][j]<36) cout<<char('a'+ans[i][j]-10);
			else cout<<char('A'+ans[i][j]-36);
		}
		cout<<'\n';
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	
	return 0;
}