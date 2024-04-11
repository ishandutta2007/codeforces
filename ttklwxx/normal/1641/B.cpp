#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
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
map<int,int>ma;
int a[200005];
int now[200005],ql,qr;
int gre[200005];
int ansc[200005],ansp[200005],cnt;
int cd[200005],tmp;
signed main()
{
	int t,n,x,y,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ma.clear();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			ma[a[i]]++;
		}
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(ma[a[i]]%2==1)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)
		{
			printf("-1\n");
			continue;
		}
		cnt=0;
		tmp=0;
		ql=1;
		qr=n;
		while(ql<=qr)
		{
			x=a[ql];
			for(int i=ql+1;i<=qr;i++)
			{
				if(a[i]==x)
				{
					y=i;
					break;
				}
			}
			//printf("%lld %lld\n",ql,y);
			for(int i=ql+1;i<=y-1;i++)
			{
				ansc[++cnt]=a[i];
				ansp[cnt]=y+i-ql-1;
			}
			for(int i=y-1;i>=ql+1;i--)gre[y-i]=a[i];
			for(int i=y+1;i<=qr;i++)gre[i-ql-1]=a[i];
			qr+=2*(y-ql-1);
			cd[++tmp]=2*(y-ql);
			ql+=2*(y-ql);
			for(int i=ql;i<=qr;i++)a[i]=gre[i-ql+1];
			//printf("orz");
			//for(int i=ql;i<=qr;i++)printf("%lld ",a[i]);
			//printf("\n");
		}
		printf("%lld\n",cnt);
		for(int i=1;i<=cnt;i++)printf("%lld %lld\n",ansp[i],ansc[i]);
		printf("%lld\n",tmp);
		for(int i=1;i<=tmp;i++)printf("%lld ",cd[i]);
		printf("\n");
	}
	return 0;
}