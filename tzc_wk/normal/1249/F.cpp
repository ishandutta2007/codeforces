#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
int n,k,a[5005],dp[5005][5005],suf[5005][5005];
vector<int> g[5005];
inline void dfs(int x,int f){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];if(y==f) continue;
		dfs(y,x);dp[x][0]+=dp[y][k-1];
	}
	dp[x][0]+=a[x];
//	printf("%d %d %d\n",x,0,dp[x][0]);
	for(int i=1;i<=k;i++){
		for(int j=0;j<g[x].size();j++){
			int y=g[x][j];if(y==f) continue;
			dp[x][i]+=suf[y][max(k-i,i)-1];
		}
		int mx=0;
		for(int j=0;j<g[x].size();j++){
			int y=g[x][j];if(y==f) continue;
			mx=max(mx,dp[y][i-1]-suf[y][max(k-i,i)-1]);
		}
		dp[x][i]+=mx;
//		printf("%d %d %d\n",x,i,dp[x][i]);
	}
	for(int i=k;~i;i--) suf[x][i]=max(dp[x][i],suf[x][i+1]);
}
int main(){
//	freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	scanf("%d%d",&n,&k);k++;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1,0);
	int mx=0;
	for(int i=0;i<=k;i++) mx=max(mx,dp[1][i]);
	printf("%d\n",mx);
	return 0;
}