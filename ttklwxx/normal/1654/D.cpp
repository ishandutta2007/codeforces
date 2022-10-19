#include<bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
struct bbian
{
	int u,v,bx,by,nex;
}a[800004];
int head[200005],tmp;
void addb(int x,int y,int z,int h)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].bx=z;
	a[tmp].by=h;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
int pri[200005],cnt;
bool vis[20005];
int cj[200005],ny[200005];
vector<int>ys[200005],tsl[200005];
vector<int>cz[200005],gx[200005];
int nid[200005],siz[200005],ttt;
int qz[200005];
int bu[200005],bv[200005];
void dfs(int x,int f)
{
	nid[x]=++ttt;
	siz[x]=1;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		qz[a[i].v]=1LL*qz[x]*a[i].by%mod*ny[a[i].bx]%mod;
		dfs(a[i].v,x);
		siz[x]+=siz[a[i].v];
	}
}
struct querycz
{
	int k,x;
}q[5000005];
bool bi(struct querycz c,struct querycz d)
{
	return c.k<d.k;
}
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	return ans;
}
int tll;
signed main()
{
	vis[1]=true;
	for(int i=2;i<=200000;i++)
	{
		if(vis[i]==false)
		{
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=200000;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
	for(int i=2;i<=200000;i++)
	{
		int gre=i;
		for(int j=2;j*j<=gre;j++)
		{
			if(gre%j==0)
			{
				ys[i].push_back(j);
				tsl[i].push_back(0);
				while(gre%j==0)
				{
					gre/=j;
					tsl[i][tsl[i].size()-1]++;
				}
			}
		}
		if(gre>1)
		{
			ys[i].push_back(gre);
			tsl[i].push_back(1);
		}
	}
	ny[1]=1;
	for(int i=2;i<=200000;i++)ny[i]=1LL*(mod-mod/i)*ny[mod%i]%mod;
	int t,n,sth,x,y,z,h,het=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		ttt=0;
		n=read();
		for(int i=1;i<=n;i++)cz[i].clear(),head[i]=0,gx[i].clear();
		tmp=0;
		for(int i=1;i<=n-1;i++)
		{
			x=read();
			y=read();
			z=read();
			h=read();
			sth=gcd(z,h);
			bu[i]=x;
			bv[i]=y;
			z/=sth;
			h/=sth;
			for(int j=0;j<ys[z].size();j++)cz[ys[z][j]].push_back(2*i+1),gx[ys[z][j]].push_back(tsl[z][j]);
			for(int j=0;j<ys[h].size();j++)cz[ys[h][j]].push_back(2*i),gx[ys[h][j]].push_back(tsl[h][j]);
			addb(x,y,z,h);
			addb(y,x,h,z);
		}
		qz[1]=1;
		dfs(1,0);
		int fm=1;
		for(int i=1;i<=n;i++)
		{
			if(cz[i].empty())continue;
			tll=0;
			for(int j=0;j<cz[i].size();j++)
			{
				int gre=cz[i][j]/2;
				if(cz[i][j]%2==1)
				{
					if(siz[bu[gre]]>siz[bv[gre]])
					{
						q[++tll].k=nid[bv[gre]];
						q[tll].x=gx[i][j];
						q[++tll].k=nid[bv[gre]]+siz[bv[gre]];
						q[tll].x=-gx[i][j];
					}
					else
					{
						q[++tll].k=nid[bu[gre]];
						q[tll].x=-gx[i][j];
						q[++tll].k=nid[bu[gre]]+siz[bu[gre]];
						q[tll].x=gx[i][j];
					}
				}
				else
				{
					if(siz[bu[gre]]>siz[bv[gre]])
					{
						q[++tll].k=nid[bv[gre]];
						q[tll].x=-gx[i][j];
						q[++tll].k=nid[bv[gre]]+siz[bv[gre]];
						q[tll].x=gx[i][j];
					}
					else
					{
						q[++tll].k=nid[bu[gre]];
						q[tll].x=gx[i][j];
						q[++tll].k=nid[bu[gre]]+siz[bu[gre]];
						q[tll].x=-gx[i][j];
					}
				}
			}
			//printf("%lld\n",tll);
			sort(q+1,q+tll+1,bi);
			int now=0,maxn=0;
			for(int j=1;j<=tll;j++)
			{
				//printf("%lld %lld\n",q[j].k,q[j].x);
				now+=q[j].x;
				if(j==tll||(q[j].k!=q[j+1].k))maxn=max(maxn,now);
			}
			//printf("orz%lld %lld\n",i,maxn);
			fm=1LL*fm*ksm(i,maxn)%mod;
		}
		int het=0;
		for(int i=1;i<=n;i++)het=(het+qz[i])%mod;
		printf("%lld\n",1LL*het*fm%mod);
	}
}