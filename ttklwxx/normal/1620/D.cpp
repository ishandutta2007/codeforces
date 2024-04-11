#include<iostream>
#include<cstdio>
#include<cstring>
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
int a[200005];
bool kd[8];
signed main()
{
	int t,n,sth,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=1000000000;
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=2;j++)
			{
				for(int k=0;k<=5;k++)kd[k]=false;
				kd[0]=kd[i]=true;
				if(j>=1)kd[i+2]=kd[2]=true;
				if(j>=2)kd[i+4]=kd[4]=true;
				sth=0;
				flag=true;
				for(int ti=1;ti<=n;ti++)
				{
					for(int tj=5;tj>=0;tj--)
					{
						if(a[ti]>=tj&&kd[tj]==true&&a[ti]%3==tj%3)
						{
							sth=max(sth,(a[ti]-tj)/3);
							break;
						}
						if(tj==0)flag=false;
					}
					if(flag==false)break;
				}
				if(flag==false)continue;
				//printf("?\n");
				ans=min(ans,sth+i+j);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}