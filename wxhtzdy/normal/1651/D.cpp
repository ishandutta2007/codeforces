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

const int N=200050;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,x[N],y[N],g[N],dis[N];
map<PII,int> is;
PII ans[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d%d",&x[i],&y[i]);
		is[mp(x[i],y[i])]=i;
	}
	rep(i,1,n+1) rep(d,0,4) {
		int nx=x[i]+dx[d];
		int ny=y[i]+dy[d];
		if (!is.count(mp(nx,ny))) g[i]=1,ans[i]=mp(nx,ny);
	}
	deque<int> que;
	rep(i,1,n+1) if (g[i]==1) que.push_back(i),dis[i]=1;
	while (!que.empty()) {
		int i=que[0];
		que.pop_front();
		rep(d,0,4) {
			int nx=x[i]+dx[d];
			int ny=y[i]+dy[d];
			int j=is[mp(nx,ny)];
			if (j!=0&&!dis[j]) {
				dis[j]=dis[i]+1;
				ans[j]=ans[i];
				que.push_back(j);
			}
		}
	}
	rep(i,1,n+1) printf("%d %d\n",ans[i].fi,ans[i].se);
}