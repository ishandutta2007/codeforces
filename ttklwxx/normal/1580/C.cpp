#include<iostream>
#include<cstdio>
#include<cmath>
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
int x[200005],y[200005],sj[200005];
int qz[505][505];
int hh[200005];
int main()
{
	int n,m,opt,id,kk,ans=0;
	n=read();
	m=read();
	kk=sqrt(m);
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
		y[i]=read();
		sj[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		opt=read();
		id=read();
		if(x[id]+y[id]<=kk)
		{
			if(opt==1)
			{
				qz[x[id]+y[id]][(i+x[id])%(x[id]+y[id])]++;
				qz[x[id]+y[id]][(i)%(x[id]+y[id])]--;
				ans++;
				sj[id]=i;
			}
			else
			{
				qz[x[id]+y[id]][(sj[id]+x[id])%(x[id]+y[id])]--;
				qz[x[id]+y[id]][(sj[id])%(x[id]+y[id])]++;
				//printf("%d %d\n",qz[2][0],qz[2][1]);
				if((i-sj[id]-1)%(x[id]+y[id])>=x[id])ans--;
			}
		}
		else
		{
			if(opt==1)
			{
				for(int j=i+x[id];j<=m;j+=x[id]+y[id])
				{
					hh[j]++;
					if(j+y[id]<=m)hh[j+y[id]]--;
				}
				sj[id]=i;
			}
			else
			{
				for(int j=sj[id]+x[id];j<=m;j+=x[id]+y[id])
				{
					hh[j]--;
					if(j+y[id]<=m)hh[j+y[id]]++;
				}
				if((i-sj[id]-1)%(x[id]+y[id])>=x[id])ans--;
			}
		}
		for(int j=1;j<=kk;j++)ans+=qz[j][i%j];
		ans+=hh[i];
		printf("%d\n",ans);
	}
	return 0;
}