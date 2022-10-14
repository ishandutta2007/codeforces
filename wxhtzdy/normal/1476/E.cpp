#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,m,k,mt[N];
string p[N],s[N];
VI e[N],ans;
int st[N];
map<string,int> pos;
bool cyc;
void dfs(int u) {
	if (cyc) return;
	st[u]=1;
	for (auto x:e[u]) {
		if (!st[x]) dfs(x);
		else if (st[x]==1) cyc=1;
	}
	st[u]=2; ans.pb(u);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>k;
	rep(i,0,n) { cin>>p[i];pos[p[i]]=i; }
	rep(i,0,m) { cin>>s[i]>>mt[i]; --mt[i]; }
	rep(i,0,m) {
		VI v;
		bool ok=0;
		rep(j,0,(1<<k)) {
			string pat="";
			rep(x,0,k) if (j&(1<<x)) pat+='_'; else pat+=s[i][x];
			if (pos.count(pat)) v.pb(pos[pat]),ok=ok|(pos[pat]==mt[i]);
		}
		if (!ok) {
			puts("NO");
			return 0;
		}
		for (auto x:v) if (x!=mt[i]) e[mt[i]].pb(x);
	}
	rep(i,0,n) if (!st[i]) {
		cyc=0; dfs(i);
		if (cyc) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	reverse(all(ans));
	for (auto x:ans) printf("%d ",x+1);
}