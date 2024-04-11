#include<iostream>
#include<cstdio>
#include<cstdlib>
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
struct tree
{
    int fa,sz,ls,rs,rnd,siz;
}a[800004];
int cnt=0,g=0;
int random(int x)
{
    static int seed=4242305;
    return seed=seed*seed*1121;
}
int build(int x)
{
    a[++cnt].siz=1;
    a[cnt].sz=x;
    a[cnt].ls=a[cnt].rs=0;
    a[cnt].rnd=rand();
    return cnt;
}
int kth(int gg,int x)
{
    while(1)
    {
        if(x<=a[a[gg].ls].siz)gg=a[gg].ls;
        else

        {
            if(x==a[a[gg].ls].siz+1)return gg;
            x-=a[a[gg].ls].siz+1;
            gg=a[gg].rs;
        }
    }
}
void split(int x,int k,int& l,int& r)
{
    if(x==0)
    {
        l=0;
        r=0;
        return;
    }
    else
    {
        if(k>=a[a[x].ls].siz+1)
        {
            l=x;
            a[a[x].rs].fa=0;
            split(a[x].rs,k-a[a[x].ls].siz-1,a[x].rs,r);
            a[a[x].rs].fa=x;
        }
        else
        {
            r=x;
            a[a[x].ls].fa=0;
            split(a[x].ls,k,l,a[x].ls);
            a[a[x].ls].fa=x;
        }
        a[x].siz=a[a[x].ls].siz+a[a[x].rs].siz+1;
        return;
    }
}
int merge(int x,int y)
{
    if(x==0)return y;
    if(y==0)return x;
    if(a[x].rnd<a[y].rnd)
    {
    	a[a[x].rs].fa=0;
        a[x].rs=merge(a[x].rs,y);
        a[a[x].rs].fa=x;
        a[x].siz=a[a[x].ls].siz+a[a[x].rs].siz+1; 
        return x;
    }
    else
    {
    	a[a[y].ls].fa=0;
        a[y].ls=merge(x,a[y].ls);
        a[a[y].ls].fa=y;
        a[y].siz=a[a[y].ls].siz+a[a[y].rs].siz+1;
        return y;
    }

}
int findrt(int x)
{
	while(a[x].fa!=0)x=a[x].fa;
	return x;
}
int findpm(int x)
{
	int ans=a[a[x].ls].siz+1;
	while(a[x].fa!=0)
	{
		if(a[a[x].fa].rs==x)ans+=a[a[a[x].fa].ls].siz+1;
		x=a[x].fa;
	}
	return ans;
}
int p[200005]; 
bool vis[200005];
void dfs(int x)
{
	vis[x]=true;
	if(vis[p[x]]==true)return;
	merge(findrt(x),p[x]);
	dfs(p[x]);
}
void zxbl(int x)
{
	if(x==0)return;
	zxbl(a[x].ls);
	printf("vis:%d %d\n",a[x].sz,a[x].siz);
	zxbl(a[x].rs);
}
int main()
{
    int n,m,x,y,opt,tx,ty,tz,tw;
    int sx,sy,gx,gy;
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
	{
		a[i].sz=i;
		a[i].siz=1;
		a[i].rnd=rand();
		a[i].ls=a[i].rs=0;
		p[i]=read();
	} 
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])dfs(i);
	}
    for(int i=1;i<=m;i++)
    {
    	opt=read();
        x=read();
        y=read();
        if(opt==1)
        {
        sx=findrt(x);
        sy=findrt(y);
        if(sx!=sy)
        {
        	//printf("orz\n");
        	gx=findpm(x);
        	gy=findpm(y);
        	split(sx,gx,tx,ty);
        	split(sy,gy,tz,tw);
        	merge(merge(merge(tx,tw),tz),ty);
		}
		else
		{
			gx=findpm(x);
			gy=findpm(y);
			if(gx>gy)swap(gx,gy);
			//printf("%d %d\n",gx,gy);
			split(sx,gx,tx,ty);
			split(ty,gy-gx,ty,tz);
			tx=merge(tx,tz);
		}
		}
		else
		{
			sx=findrt(x);
			gx=findpm(x);
			//printf("%d %d %d\n",sx,a[sx].siz,gx);
			//zxbl(sx);
			//printf("\n"); 
			printf("%d\n",kth(sx,(gx+y-1)%a[sx].siz+1));
		}
    }
    return 0;
}