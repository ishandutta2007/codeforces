#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 300005
int s[N],fa[N*2],val[N*2];
vector<int> b[N];
int n,k;
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void link(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v) return ;
	fa[u]=v;
	val[v]+=val[u];
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
	cout<<"BEG\n";
#endif
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
	for(int i=1;i<=k;i++)
	{
		int x=read();
		for(int j=1;j<=x;j++)
		{
			int u=read();
			b[u].pb(i);
		}
	}
	for(int i=1;i<=k*2;i++) fa[i]=i;
	for(int i=1;i<=k;i++) val[i]=1;
	int ans=0;
	int ban=2*k+1;
	fa[ban]=ban,val[ban]=INF;
	for(int i=1;i<=n;i++)
	{
//		cout<<"**"<<i<<endl;
		if(s[i]==1)
		{
			if(b[i].size()==1)
			{
				int u=find(b[i][0]),v=find(b[i][0]+k);
				ans-=min(val[u],val[v]);
				link(u,ban);
				ans+=val[v];
			}
			if(b[i].size()==2)
			{
				int u=find(b[i][0]),v=find(b[i][0]+k);
				int w=find(b[i][1]),x=find(b[i][1]+k);
				if(u==w||v==x) goto en;
				ans-=min(val[u],val[v]);
				ans-=min(val[w],val[x]);
				link(u,w),link(v,x);
				u=find(u),v=find(v);
				ans+=min(val[u],val[v]);
			}
		}
		else
		{
			if(b[i].size()==1)
			{
				int u=find(b[i][0]),v=find(b[i][0]+k);
				ans-=min(val[u],val[v]);
				link(v,ban);
				ans+=val[u];
			}
			if(b[i].size()==2)
			{
				int u=find(b[i][0]),v=find(b[i][0]+k);
				int w=find(b[i][1]),x=find(b[i][1]+k);
				if(u==x||v==w) goto en;
				ans-=min(val[u],val[v]);
				ans-=min(val[w],val[x]);
				link(u,x),link(v,w);
				u=find(u),v=find(v);
				ans+=min(val[u],val[v]);
			}
		}
		en:;
		printf("%d\n",ans);
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}


//