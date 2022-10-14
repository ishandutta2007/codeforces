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
typedef long long ll;
typedef vector<ll> VI;
typedef basic_string<int> BI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=5005;
int n,k,p[N],pos[N],dp[N][1<<9],f[N];

void modify(int x,int v) {
	for (int i=x;i<N;i+=i&-i) f[i]+=v;
}
int get(int x) {
	int s=0;
	for (int i=x;i>0;i-=i&-i) s+=f[i];
	return s;
}

int calc(int mn,int mask,int v) {
	int inv=0;
	rep(i,0,k) if (mask>>i&1) {
		if (pos[v]<pos[mn+1+i]) inv++;
	}
	inv+=get(N-1)-get(pos[v]);
	return inv;
}

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%d",&p[i]),pos[p[i]]=i;
	rep(i,0,n+2) rep(j,0,1<<k) dp[i][j]=1e9;
	dp[1][0]=0;
	rep(mn,1,n+1) {
		rep(mask,0,1<<min(n-mn,k)) {
			if (dp[mn][mask]==1e9) continue;
			rep(i,0,min(n-mn,k)) if (!(mask>>i&1)) {
				dp[mn][mask|(1<<i)]=min(dp[mn][mask|(1<<i)],dp[mn][mask]+calc(mn,mask,mn+1+i));
			}
			int new_mn=mn+1,new_mask=mask;
			while (new_mask&1) {
				new_mask>>=1;
				new_mn++;
			}
			new_mask>>=1;
			dp[new_mn][new_mask]=min(dp[new_mn][new_mask],dp[mn][mask]+calc(mn,mask,mn));
		}
		modify(pos[mn],+1);
	}
	printf("%d\n",dp[n+1][0]);
}