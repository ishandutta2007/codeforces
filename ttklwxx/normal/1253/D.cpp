#include<iostream>
#include<cstdio>
#include<algorithm>
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
int fa[300001],maxn[300001],minn[300001];
bool vis[300001];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
int ans=0,fw=0;
void merge(int x,int l,int r)
{
		int tl=l,tr=r,y;
		for(int j=tl;j<=tr;j++)
		{
			fw++;
			if(findf(j)!=x)
			{
				y=findf(j);
				fa[y]=x;
				maxn[x]=max(maxn[x],maxn[y]);
				minn[x]=min(minn[x],minn[y]);
				ans++;
				if(maxn[y]>r)
				{
					merge(x,r+1,maxn[y]);
					r=maxn[y];
				}
				if(minn[y]<l)
				{
				//merge(x,minn[y],l-1);
					l=minn[y];
				}
			}
		}
}
signed main()
{
    int n,m,x,y;
    n=read();
    m=read();
    for(int i=1;i<=n;i++)fa[i]=i,maxn[i]=i,minn[i]=i;
    for(int i=1;i<=m;i++)
    {
    	x=read();
    	y=read();
    	x=findf(x);
    	y=findf(y);
    	fa[x]=y;
    	maxn[y]=max(maxn[y],maxn[x]);
    	minn[y]=min(minn[y],minn[x]);
	}
	for(int i=1;i<=n;i++)
	{
		x=findf(i);
		if(vis[x])continue;
		vis[x]=true;
		merge(x,minn[x],maxn[x]);
	}
	printf("%d\n",ans);
	return 0;
}