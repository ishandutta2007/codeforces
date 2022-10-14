#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=105;
int n,m,_,a[N][N];
char s[N];

void solve() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%s",s);
		rep(j,0,m) a[i][j]=(int)(s[j]-'0');
	}
	vector<VI> ans;
	vector<vector<PII>> v(2);
	auto solve=[&]() {
		vector<vector<PII>> new_v(2);
		if (SZ(v[1])==1) {
			ans.pb({v[1][0].fi,v[1][0].se,v[0][0].fi,v[0][0].se,v[0][1].fi,v[0][1].se});
			new_v[0].pb(v[1][0]);
			new_v[0].pb(v[0][2]);
			new_v[1].pb(v[0][0]);
			new_v[1].pb(v[0][1]);
		} else if (SZ(v[1])==2) {
			ans.pb({v[0][0].fi,v[0][0].se,v[0][1].fi,v[0][1].se,v[1][0].fi,v[1][0].se});
			new_v[0].pb(v[1][0]);
			new_v[1].pb(v[1][1]);
			new_v[1].pb(v[0][0]);
			new_v[1].pb(v[0][1]);
		} else if (SZ(v[1])==3) {
			ans.pb({v[1][0].fi,v[1][0].se,v[1][1].fi,v[1][1].se,v[1][2].fi,v[1][2].se});
			new_v[0].pb(v[1][0]);
			new_v[0].pb(v[1][1]);
			new_v[0].pb(v[1][2]);
			new_v[0].pb(v[0][0]);
		} else {
			assert(SZ(v[1])==4);
			ans.pb({v[1][0].fi,v[1][0].se,v[1][1].fi,v[1][1].se,v[1][2].fi,v[1][2].se});
			new_v[0].pb(v[1][0]);
			new_v[0].pb(v[1][1]);
			new_v[0].pb(v[1][2]);
			new_v[1].pb(v[1][3]);
		}
		auto p=ans.back();
		for (int i=0;i<6;i+=2) {
			a[p[i]][p[i+1]]^=1;
		}
		swap(v,new_v);
	};
	rep(i,0,n-1) rep(j,0,m-1) {
		rep(x,0,2) v[x].clear();
		rep(x,0,2) rep(y,0,2) v[a[i+x][j+y]].pb(mp(i+x,j+y));
		while (SZ(v[1])!=0) {
			solve();
		}
	}
	int s=0;
	rep(i,0,n) rep(j,0,m) s+=a[i][j];
	//printf("%d\n",s);
	assert(s==0);
	printf("%d\n",SZ(ans));
	for (auto&p:ans) {
		rep(i,0,6) printf("%d ",p[i]+1);
		puts("");
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}