#include <iostream>
#include<cstdio>
using namespace std;
inline __int128 read()
{
	__int128 n=0,f=1,ch=getchar();
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
	int ch[2],l,r;
	__int128 gc;
}t[6000004];
int cnt;
__int128 cs[2005];
__int128 gcd(__int128 m,__int128 n)
{
	if(n==0||m==0)return n+m;
	while(m^=n^=m^=n%=m);
	return n;
}
void build(int l,int r,int k)
{
	t[k].l=l;
	t[k].r=r;
	if(l==r)
	{
		t[k].gc=cs[l];
		return;
	}
	t[k].ch[0]=++cnt;
	t[k].ch[1]=++cnt;
	build(l,(l+r)>>1,t[k].ch[0]);
	build(((l+r)>>1)+1,r,t[k].ch[1]);
	t[k].gc=gcd(t[t[k].ch[0]].gc,t[t[k].ch[1]].gc);
}
void change(int x,int k,__int128 y)
{
	if(t[k].l==t[k].r)
	{
		t[k].gc=y;
		return;
	}
	int pre;
	if(x<=t[t[k].ch[0]].r)
	{
		pre=t[t[k].ch[0]].gc;
		change(x,t[k].ch[0],y);
		if(pre==t[t[k].ch[0]].gc)return;
		t[k].gc=gcd(t[t[k].ch[0]].gc,t[t[k].ch[1]].gc);
	}
	else
	{
		pre=t[t[k].ch[1]].gc;
		change(x,t[k].ch[1],y);
		if(pre==t[t[k].ch[1]].gc)return;
		t[k].gc=gcd(t[t[k].ch[0]].gc,t[t[k].ch[1]].gc);
	}
}
int rt[2005];
__int128 a[1005],b[1005];
bool sa[1005],sb[1005];
void output(__int128 n)
{
	if(n>=10)output(n/10);
	putchar(n%10+'0');
}
signed main()
{
	int sjzs,n,m,now;
	bool flag;
	sjzs=read();
	for(int greg=1;greg<=sjzs;greg++)
	{
		n=read();
		m=read();
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			sa[i]=false;
		}
		for(int i=1;i<=m;i++)
		{
			b[i]=read();
			sb[i]=false;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)cs[j]=a[i]/gcd(a[i],b[j]);
			rt[i]=++cnt;
			build(1,m,rt[i]);
			//printf("%lld %lld\n",i,t[rt[i]].gc);
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)cs[j]=b[i]/gcd(b[i],a[j]);
			rt[i+n]=++cnt;
			build(1,n,rt[i+n]);
			//printf("%lld %lld\n",i,t[rt[i+n]].gc);
		}
		flag=false;
		for(int i=1;i<=n+m;i++)
		{
			now=0;
			for(int j=1;j<=n;j++)
			{
				if(t[rt[j]].gc!=1&&sa[j]==false)
				{
					now=j;
					break;
				}
			}
			for(int j=1;j<=m;j++)
			{
				if(t[rt[j+n]].gc!=1&&sb[j]==false)
				{
					now=j+n;
					break;
				}
			}
			if(now==0)
			{
				flag=true;
				break;
			}
			//printf("orz%d\n",now);
			if(now<=n)
			{
				sa[now]=true;
				for(int j=n+1;j<=n+m;j++)
				{
					change(now,rt[j],0);
				}
			}
			else
			{
				sb[now-n]=true;
				for(int j=1;j<=n;j++)
				{
					change(now-n,rt[j],0);
				}
			}
		}
		if(flag==false)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		int asl=0,bsl=0;
		for(int j=1;j<=n;j++)if(sa[j]==false)asl++;
		for(int j=1;j<=m;j++)if(sb[j]==false)bsl++;
		printf("%d",asl);
		printf(" ");
		printf("%d",bsl);
		printf("\n");
		for(int j=1;j<=n;j++)if(sa[j]==false)
		{
			output(a[j]);
			printf(" ");
		}
		printf("\n");
		for(int j=1;j<=m;j++)if(sb[j]==false)
		{
			output(b[j]);
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}