#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN=2e5+5;
const int MOD=998244353;
int n,hd[MAXN],to[MAXN],nxt[MAXN],ec=0,deg[MAXN];
void adde(int u,int v){
	to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;
}
ll dp[MAXN][3];
void dfs(int x){
	if(!deg[x]){dp[x][2]=1;return;}
	dp[x][0]=1; 
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dfs(y);
		dp[x][2]=(dp[x][2]*(dp[y][0]+dp[y][1]+2*dp[y][2])%MOD+dp[x][1]*(dp[y][1]+dp[y][2])%MOD)%MOD;
		dp[x][1]=(dp[x][0]*(dp[y][1]+dp[y][2])%MOD+dp[x][1]*(dp[y][0]+dp[y][2])%MOD)%MOD;
		dp[x][0]=dp[x][0]*(dp[y][0]+dp[y][2])%MOD;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int fa;scanf("%d",&fa);adde(fa,i);deg[fa]++;
	} dfs(1);printf("%lld\n",(dp[1][0]+dp[1][2])%MOD);
	return 0;
}