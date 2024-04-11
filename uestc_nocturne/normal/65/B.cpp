#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int pr[1200][2200],t[120],out[1200];
int i,j,k,n,mi,tm,x;
const int oo=100000000;
int main()
{
	memset(pr,-1,sizeof(pr));t[0]=1;
	for(i=1;i<4;i++)t[i]=t[i-1]*10;
	scanf("%d",&n);
	scanf("%d",&x);
	mi=oo;
	if(x>=1000&&x<=2011)mi=x;
	for(i=0;i<4;i++)
	{
		int v=(x/t[i])%10;
		for(j=0;j<=9;j++)
		{
			if(i==3&&j==0)continue;
			int te=x-v*t[i]+j*t[i];
	//		printf("%d %d  ",te,mi);
			if(te>2011||te<1000)continue;
			mi=min(mi,te);
		}
	}int flag=1;
	for(k=2;k<=n;k++)
	{
		scanf("%d",&x);
		if(flag==0)continue;
		int tm=oo;
		if(x>=mi&&x>=1000&&x<=2011){pr[k][x]=mi;tm=x;}
		for(i=0;i<4;i++)
		{
			int v=(x/t[i])%10;
			for(j=0;j<=9;j++)
			{
				if(i==3&&j==0)continue;
				int te=x-v*t[i]+j*t[i];//printf("%d %d %d  ",te,mi,tm);
				if(te>2011||te<1000)continue;
				if(te<mi)continue;
				tm=min(tm,te);pr[k][te]=mi;
			}
		}
		if(tm==oo)flag=0;
		mi=tm;
	}
	if(flag==0)puts("No solution");
	else
	{
		int now=mi;int T=0;
		while(now!=-1)
		{
		//	printf("%d ",now);
			out[T++]=now;
			now=pr[n-T+1][now];
		}
		for(i=T-1;i>=0;i--)printf("%d\n",out[i]);
	}
}