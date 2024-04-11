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

const int N=1010000;
const int M=1<<13;
int n,a[N],mn[M];
VI pos[M];
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i),pos[a[i]].pb(i);
	rep(i,1,M) mn[i]=1e9;
	mn[0]=-1;
	rep(i,0,M) if (SZ(pos[i])) rep(xr,0,M) if (mn[xr]!=1e9) {
		int x=xr^i;
		auto it=lower_bound(all(pos[i]),mn[xr]+1)-pos[i].begin();
		if (it!=SZ(pos[i])) mn[x]=min(mn[x],pos[i][it]);
	}
	VI ans;
	rep(i,0,M) if (mn[i]!=1e9) ans.pb(i);
	printf("%d\n",SZ(ans));
	rep(i,0,SZ(ans)) printf("%d ",ans[i]); puts("");
}