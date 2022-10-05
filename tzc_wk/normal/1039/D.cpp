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
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5;
int n,blk_sz;
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dp[MAXN+5],fa[MAXN+5],seq[MAXN+5],tim=0,ans[MAXN+5];
void dfs0(int x,int f){
	fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;dfs0(y,x);
	} seq[++tim]=x;
}
int solve(int mid){
	int ret=0;
	for(int i=1;i<=n;i++) dp[i]=1;
	for(int i=1;i<=n;i++){
		int x=seq[i];
		if(fa[x]&&(~dp[fa[x]])&&(~dp[x])){
			if(dp[x]+dp[fa[x]]>=mid) ret++,dp[fa[x]]=-1;
			else chkmax(dp[fa[x]],dp[x]+1);
		}
	} return ret;
}
int main(){
	scanf("%d",&n);blk_sz=(int)pow(n,0.6);
	for(int i=1;i<n;i++){int u,v;scanf("%d%d",&u,&v);adde(u,v);adde(v,u);}
	dfs0(1,0);ans[1]=n;for(int i=2;i<=blk_sz;i++) ans[i]=solve(i);
	int cur=blk_sz+1;
	for(int i=ans[blk_sz];i;i--){
		int l=cur,r=n,x=cur-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(solve(mid)==i) x=mid,l=mid+1;
			else r=mid-1;
		} for(int j=cur;j<=x;j++) ans[j]=i;
		cur=x+1;
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}