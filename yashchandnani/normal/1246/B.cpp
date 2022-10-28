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
vi divs[100009];
int p[100009];
int x[100009];
int r[100009];
bool poss[100009];
int n,k;
void pre(){
	repA(i,2,100000){
		if(!p[i]){
			for(int j=i;j<=100000;j+=i) divs[j].pb(i),p[j]=1;
		}
	}
	x[1] = 1;
	r[1] = 1;
	repA(i,2,100000){
		r[i] = 1;
		x[i] = 1;
		int kk = i;
		trav(j,divs[i]){
			int cnt = 0;
			while(kk%j==0) cnt++,kk/=j;
			rep(q,cnt%k) r[i]*=j;
			rep(q,(k-cnt%k)%k) if(1ll*x[i]*j<=1e5) x[i]*=j; else poss[i] = 1;
		}
	}
}

void solve(){


}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>k;
	pre();
	map<int,int> m;
	ll ans = 0;
	rep(i,n){
		int a;cin>>a;
		if(poss[a]) continue;
		ans+=m[x[a]];
		m[r[a]]++;
	}
	cout<<ans;
	return 0;
}