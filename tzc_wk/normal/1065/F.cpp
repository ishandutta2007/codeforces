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
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
int n,k;
struct graph{
	int head[1000005],nxt[1000005],to[1000005],ecnt;
	graph(){ecnt=0;fill0(head);fill0(nxt);fill0(to);}
	void adde(int u,int v){
		to[++ecnt]=v;nxt[ecnt]=head[u];head[u]=ecnt;
	}
} t;
int dep[1000005],deg[1000005],dp[1000005],mn[1000005];
void dfs(int x){
	if(deg[x]==0){mn[x]=dep[x];dp[x]=1;return;}
	mn[x]=0x3f3f3f3f;
	for(int e=t.head[x];e;e=t.nxt[e]){
		int y=t.to[e];dep[y]=dep[x]+1;dfs(y);
		mn[x]=min(mn[x],mn[y]);
		if(mn[y]-dep[x]<=k){
			dp[x]+=dp[y];dp[y]=0;
		}
	}
}
int mxsum(int x){
	int mx=0;
	for(int e=t.head[x];e;e=t.nxt[e]){
		mx=max(mx,mxsum(t.to[e]));
	} return mx+dp[x];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n;i++){
		int fa;scanf("%d",&fa);t.adde(fa,i);deg[fa]++;
	} dfs(1);printf("%d\n",mxsum(1));
	return 0;
}
/*1
7 1
1 1 3 3 4 4
*/ 
/*2
8 2
1 1 2 3 4 5 5
*/
/*3
17 1
1 2 3 3 2 1 1 8 9 9 8 12 12 14 14 1
*/
/*4
30 2
1 28 16 24 19 15 15 22 27 28 18 2 17 22 2 1 28 23 23 15 1 7 29 20 24 7 8 15 15
*/