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
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

//nice aliens trick tutorial: https://www.youtube.com/watch?v=dQw4w9WgXcQ

const int N=1010000;
int n,k,l,a[N],dp[N],ch[N];
char s[N];

bool check(int x) {
	rep(i,1,n+1) {
		dp[i]=dp[i-1]+a[i]; ch[i]=ch[i-1];
		int j=max(0,i-l);
		if (dp[j]+x<dp[i]) dp[i]=dp[j]+x,ch[i]=ch[j]+1;
	}
	return ch[n]<=k;
}

int gao() {
	int l=0,r=n;
	while (l<r) {
		int md=(l+r)>>1;
		if (check(md)) r=md;
		else l=md+1;
	}
	check(r);
	return dp[n]-k*r;
}

int main() {
	scanf("%d%d%d",&n,&k,&l);
	scanf("%s",s);
	int ans=1e9;
	rep(i,0,n) a[i+1]=(s[i]>='A'&&s[i]<='Z'?1:0);
	ans=min(ans,gao());
	rep(i,0,n) a[i+1]=(s[i]>='a'&&s[i]<='z'?1:0);
	ans=min(ans,gao());
	printf("%d\n",ans);
}