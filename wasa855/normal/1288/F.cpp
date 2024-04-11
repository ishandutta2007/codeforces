#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 505
#define M 50005
struct Edge
{
	int u,v,w,nxt,cap;
};
Edge edge[M];
int fir[N],ss=1;
void adde(int u,int v,int w,int x)
{
	ss++;
	edge[ss].u=u,edge[ss].v=v,edge[ss].cap=w,edge[ss].w=x;
	edge[ss].nxt=fir[u]; fir[u]=ss;
	ss++;
	edge[ss].u=v,edge[ss].v=u,edge[ss].cap=0,edge[ss].w=-x;
	edge[ss].nxt=fir[v]; fir[v]=ss;
}
int n1,n2,m,R,B;
char s1[N],s2[N];
int s,t,S,T,sum,ans;
int d1[N],d2[N],d[N];
int id1[N],id2[N];
int dis[N],vis[N],fr[N];
bool spfa(int s,int t)
{
	for(int i=1;i<=T;i++) dis[i]=inf;
	dis[s]=0;
	queue<int> q; q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop(); vis[u]=0;
		for(int i=fir[u];i!=0;i=edge[i].nxt)
		{
			if(!edge[i].cap) continue;
			int v=edge[i].v;
			if(dis[v]>dis[u]+edge[i].w)
			{
				dis[v]=dis[u]+edge[i].w;
				fr[v]=i;
				if(!vis[v]) vis[v]=1,q.push(v);
			}
		}
	}
	// for(int i=1;i<=t;i++) printf("%d ",dis[i]); cout<<"\n";
	if(dis[t]==inf) return 0;
	// cout<<"Passed\n";
	sum--;
	if(sum<0) return 0;
	for(int i=fr[t];i!=0;i=fr[edge[i].u])
	{
		edge[i].cap--,edge[i^1].cap++;
		ans+=edge[i].w;
	}
	return 1;
}
signed main()
{
	cin>>n1>>n2>>m>>R>>B;
	scanf("%s%s",s1+1,s2+1);
	s=n1+n2+1,t=n1+n2+2,S=n1+n2+3,T=n1+n2+4;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		d1[u]++,d2[v]++;
		d[u]++,d[v+n1]--;
		adde(u,v+n1,1,R); id1[i]=ss;
		adde(v+n1,u,1,B); id2[i]=ss;
	}
	for(int i=1;i<=n1;i++)
	{
		if(!d1[i]&&s1[i]!='U')
		{
			cout<<"-1\n";
			return 0;
		}
		if(s1[i]!='U')
		{
			adde(s,i,d1[i]-1,0);
			if(s1[i]=='R') d[i]-=d1[i]+1,d[s]+=d1[i]+1;
		}
		else
		{
			adde(s,i,2*d1[i],0);
		}
	}
	for(int i=1;i<=n2;i++)
	{
		if(!d2[i]&&s2[i]!='U')
		{
			cout<<"-1\n";
			return 0;
		}
		if(s2[i]!='U')
		{
			adde(i+n1,t,d2[i]-1,0);
			if(s2[i]=='R') d[i+n1]+=d2[i]+1,d[t]-=d2[i]+1;
		}
		else
		{
			adde(i+n1,t,2*d2[i],0);
		}
	}
	for(int i=1;i<=T;i++)
	{
		if(d[i]>0) sum+=d[i],adde(i,T,d[i],0);
		else if(d[i]<0) adde(S,i,-d[i],0);
	}
	adde(t,s,inf,0);
	// cout<<sum<<endl;
	while(spfa(S,T));
	// cout<<sum<<endl;
	// DEBUG;
	if(sum)
	{
		cout<<"-1\n";
		return 0;
	}
	cout<<ans<<endl;
	for(int i=1;i<=m;i++)
	{
		if(edge[id1[i]].cap) printf("R");
		else if(edge[id2[i]].cap) printf("B");
		else printf("U");
	}
	return 0;
}