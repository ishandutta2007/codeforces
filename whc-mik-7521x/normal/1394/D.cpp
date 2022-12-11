#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,t[N],he[N];
struct edge{
	int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
	cnt++;
	ed[cnt].to=et;
	ed[cnt].nxt=h[st];
	h[st]=cnt;
}
long long dp[N][2];//0 x1++ 1 x2++
void dfs(int x,int fa){
	long long sum=0,a=0,b=0;
	vector<long long>vec;
	for(int i=h[x];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa)continue;
		dfs(v,x);
		if(he[v]==he[x])vec.push_back(dp[v][1]-dp[v][0]),sum+=dp[v][0],a++;
		else if(he[v]>he[x])b++,sum+=dp[v][1];
		else a++,sum+=dp[v][0];
	}
	stable_sort(vec.begin(),vec.end());
	for(int i=0;i<=(int)vec.size();i++){
		dp[x][0]=min(dp[x][0],sum+max(a,b+(x!=1))*t[x]);
		dp[x][1]=min(dp[x][1],sum+max(a+(x!=1),b)*t[x]);
		a--,b++;
		if(i<(int)vec.size())sum+=vec[i]; 
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=n;i++)scanf("%d",&he[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	memset(dp,63,sizeof dp);
	dfs(1,0);
	printf("%lld",min(dp[1][0],dp[1][1]));
	return 0;
}