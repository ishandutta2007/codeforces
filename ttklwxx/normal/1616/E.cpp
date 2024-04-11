#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<cstdlib>
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
char s[200005],t[200005];
/*int f[200005],n;
void insert(int k,int x)
{
	while(k<=n)
	{
		f[k]+=x;
		k+=((k)&(-k));
	}
}
int query(int k)
{
	int ans=0;
	while(k>=1)
	{
		ans+=f[k];
		k-=((k)&(-k));
	} 
	return ans;
}*/
struct tree
{
    int sz,ls,rs,rnd,siz;
}a[800004];
int cnt=0,g=0;
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
        if(a[x].sz<=k)
        {
            l=x;
            split(a[x].rs,k,a[x].rs,r);
        }
        else
        {
            r=x;
            split(a[x].ls,k,l,a[x].ls);
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
        a[x].rs=merge(a[x].rs,y);
        a[x].siz=a[a[x].ls].siz+a[a[x].rs].siz+1; 
        return x;
    }
    else
    {
        a[y].ls=merge(x,a[y].ls);
        a[y].siz=a[a[y].ls].siz+a[a[y].rs].siz+1;
        return y;
    }

}
int findpm(int x)
{
	int tx,ty;
	split(g,x-1,tx,ty);
    int ans=a[tx].siz+1;
    g=merge(tx,ty);
    return ans;
}
int del(int x)
{
	int tx,ty,tz;
	split(g,x,tx,tz);
    split(tx,x-1,tx,ty);
    ty=merge(a[ty].ls,a[ty].rs);
    g=merge(merge(tx,ty),tz);
}
int hz[200005];
int tid[105];
signed main()
{
	int n,ttt,ans=0,now=0,sth=0,l,r,mid;
	int nmax;
	int x,y;
	ttt=read();
	for(int greg=1;greg<=ttt;greg++)
	{
		n=read();
		//printf("hello\n");
		scanf("%s",s+1);
		//printf("2\n");
		scanf("%s",t+1);
		//printf("what\n");
		for(int i=1;i<=26;i++)tid[i]=1121131433448687LL;
		cnt=0;
		g=0;
		for(int i=n;i>=1;i--)
		{
			hz[i]=tid[s[i]-'a'+1];
			tid[s[i]-'a'+1]=i;
		}
		for(int i=1;i<=n;i++)g=merge(g,build(i)); 
		ans=1121131433448687LL;
		//se.insert(1121131433448687LL);
		now=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=t[i]-'a';j++)
			{
				if(tid[j]>n)continue;
				//printf("have\n");
				sth=now+abs(findpm(tid[j])-1);
				//printf("???%lld\n",sth);
				ans=min(ans,sth);
			}
			//printf("at\n");
			if(tid[t[i]-'a'+1]>n)break;
			//printf("%lld %lld\n",tid[t[i]-'a'+1],tid[t[i]-'a'+1]+query(tid[t[i]-'a'+1]));
			now+=abs(findpm(tid[t[i]-'a'+1])-1);
			//printf("%d\n",now);
			del(tid[t[i]-'a'+1]);
			tid[t[i]-'a'+1]=hz[tid[t[i]-'a'+1]];
			//printf("nex:%lld\n",tid[t[i]-'a'+1]);
		}
		if(ans>=1121131433448687LL)printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}