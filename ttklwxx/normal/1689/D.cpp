#include<iostream>
#include<cstdio>
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
int mx1,mn1,mx2,mn2;
char s[1050][1050];
int dis(int i,int j)
{
	int x=i+j,y=i-j;
	return max(max(abs(x-mx1),abs(x-mn1)),max(abs(y-mx2),abs(y-mn2)));
}
signed main()
{
    int n,m,t,ansx,ansy;
    t=read();
    for(int greg=1;greg<=t;greg++)
	{
    	n=read();
    	m=read();
    	mx1=mx2=-1000000000;
    	mn1=mn2=1000000000;
    	ansx=ansy=-1000000000;
    	for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
    		for(int j=1;j<=m;j++)
			{
    			if(s[i][j]=='B')
				{
    				mx1=max(mx1,i+j);
					mn1=min(mn1,i+j);
    				mx2=max(mx2,i-j);
					mn2=min(mn2,i-j);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(dis(i,j)<=dis(ansx,ansy))
				{
					ansx=i;
					ansy=j;
				}
			}
		}
		printf("%lld %lld\n",ansx,ansy);
	}
}