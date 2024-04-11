#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=2005;
const LL INF=0X3F3F3F3F3F3F3F3FLL;
int n,m,s,t,p[N],cnt[N][N],ns[N][N],nt[N][N];
LL sum[N][N],f[2][N][N];
LL diss[N],dist[N];
int pp,lnk[100005],nxt[200005],to[200005],we[200005];
void ae(int k1,int k2,int k3){to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dij(int st,LL*dis){
	assert(st<=n);
	rep(i,1,n)dis[i]=INF;
	dis[st]=0;
	priority_queue<pair<LL,int> >q;
	q.emplace(-dis[st],st);
	vector<bool>vis(n+1);
	while(!q.empty()){
		LL k2;int k1;
		tie(k2,k1)=q.top();
		q.pop();
		k2=-k2;
		if(k2!=dis[k1])continue;
		if(vis[k1])continue;
		vis[k1]=1;
		for(int i=lnk[k1];i;i=nxt[i])if(dis[k1]+we[i]<dis[to[i]]){
			dis[to[i]]=dis[k1]+we[i];
			q.emplace(-dis[to[i]],to[i]);
		}
	}
	vector<LL>num(dis+1,dis+1+n);
	sort(num.begin(),num.end());
	rep(i,1,n)dis[i]=lower_bound(num.begin(),num.end(),dis[i])-num.begin()+1;
}
signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
	rep(i,1,n)scanf("%lld",p+i);
	rep(i,1,m){
		int k1,k2,k3;scanf("%lld%lld%lld",&k1,&k2,&k3);
		ae(k1,k2,k3),ae(k2,k1,k3);
	}
	dij(s,diss),dij(t,dist);
	rep(i,1,n){
		assert(diss[i]<=n);
		assert(dist[i]<=n);
		++cnt[diss[i]][dist[i]],sum[diss[i]][dist[i]]+=p[i];
	}
	per(i,n,1)per(j,n,1){
		sum[i][j]-=sum[i+1][j+1]-sum[i][j+1]-sum[i+1][j];
		ns[i][j]=min(i==n?n:ns[i+1][j],j==n?n:ns[i][j+1]);
		nt[i][j]=min(i==n?n:nt[i+1][j],j==n?n:nt[i][j+1]);
		if(cnt[i][j])ns[i][j]=i,nt[i][j]=j;
		f[0][i][j]=sum[i][j]-f[1][ns[i][j]+1][j];
		f[1][i][j]=sum[i][j]-f[0][i][nt[i][j]+1];
		if(i==1&&j==1)continue;
		f[0][i][j]=min(f[0][i][j],f[0][i][j+1]);
		f[1][i][j]=min(f[1][i][j],f[1][i+1][j]);
	}
	LL ans=sum[1][1]-2*f[0][1][1];
	puts(ans<0?"Break a heart":ans==0?"Flowers":"Cry");
	return 0;
}