#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int INF=INT_MAX>>1;
const int mod=1e9+7;
int s,t;
int vis[N],dis[N],dp[2][N];
struct edge{
	int to,nex;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
	cnt++;
	ed[cnt].to=et;
	ed[cnt].nex=h[st];
	h[st]=cnt;
}
int solve(){
	queue<tuple<int,int,int>>q;
	q.push({s,0,0});
	int ans=0,mnd=INF;
	vis[s]=1;
	dp[0][s]=1;
	dis[s]=0;
	while(!q.empty()){
		auto[v,d,x]=q.front();
		q.pop();
		if(v==t){
			if(mnd==INF){
				mnd=d;
			}
			ans=(ans+dp[x][v])%mod;
		}
		if(d==mnd+1)continue;
		for(int i=h[v];i;i=ed[i].nex){
			int to=ed[i].to;
			if(d<=dis[to]){
				dis[to]=min(dis[to],d+1);
				dp[d-dis[to]+1][to]=(dp[d-dis[to]+1][to]+dp[x][v])%mod;
				if(vis[to]==0||(vis[to]==1&&dis[to]==d))q.push({to,d+1,vis[to]++});
			}
		}
	}
	return ans;
}
void init(int x){
	for(int i=0;i<=x;i++)vis[i]=dp[0][i]=dp[1][i]=0,dis[i]=1e9+7;
	cnt=0;
	for(int i=0;i<=x;i++)h[i]=0;
}
int main(){
	int tt;
	scanf("%d",&tt);
	while(tt--){
		int n,m;
		scanf("%d%d%d%d",&n,&m,&s,&t);
		init(n);
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		printf("%d\n",solve());
	}
}