#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
int S=333;
int fa[N],tag[N],maxn[N],top[N],bl[N],br[N],bel[N],n,Q;
void rebuild(int id)
{
	int L=bl[id],R=br[id];
	for(int i=L;i<=R;i++) fa[i]=max(1,fa[i]-tag[id]);
	tag[id]=0;
	for(int i=L;i<=R;i++)
	{
		if(fa[i]<L) top[i]=fa[i];
		else top[i]=top[fa[i]];
	}
	maxn[id]=0; for(int i=L;i<=R;i++) maxn[id]=max(maxn[id],fa[i]);
}
signed main()
{
	cin>>n>>Q;
	for(int i=2;i<=n;i++) fa[i]=read();
	for(int i=1;i<=n;i++) bel[i]=(i+S-1)/S;
	for(int i=1,j=1;i<=n;i+=S,j++) bl[j]=i,br[j]=min(i+S-1,n);
	bel[1]=0,bl[1]=2;
	int m=bel[n];
	for(int i=1;i<=m;i++) rebuild(i);
	while(Q--)
	{
		int opt=read();
		if(opt==1)
		{
			int l=read(),r=read(),val=read();
			if(bel[l]==bel[r])
			{
				for(int i=l;i<=r;i++) fa[i]-=val;
				rebuild(bel[l]);
			}
			else
			{
				for(int i=l;i<=br[bel[l]];i++) fa[i]-=val;
				rebuild(bel[l]);
				for(int i=bl[bel[r]];i<=r;i++) fa[i]-=val;
				rebuild(bel[r]);
				for(int i=bel[l]+1;i<=bel[r]-1;i++)
				{
					tag[i]+=val; tag[i]=min(tag[i],n);
					if(maxn[i]>=bl[i]) rebuild(i);
				}
			}
		}
		else
		{
			int u=read(),v=read();
			while(u!=v)
			{
				int tpu=max(top[u]-tag[bel[u]],1),tpv=max(top[v]-tag[bel[v]],1);
				if(u==1) tpu=0;
				if(v==1) tpv=0;
				if(tpu!=tpv)
				{
					if(tpu<tpv) v=tpv;
					else u=tpu;
				}
				else
				{
					tpu=max(fa[u]-tag[bel[u]],1),tpv=max(fa[v]-tag[bel[v]],1);
					if(u==1) tpu=0;
					if(v==1) tpv=0;
					if(tpu<tpv) v=tpv;
					else u=tpu;
				}
			}
			printf("%d\n",u);
		}
	}
	return 0;
}