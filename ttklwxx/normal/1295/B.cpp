#include<iostream>
#include<cstdio>
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
char s[200001];
int main()
{
    int t,n,x,sl,nsl,ans;
    bool flag;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	x=read();
    	scanf("%s",s+1);
    	sl=0;
    	for(int j=1;j<=n;j++)
    	{
    		if(s[j]=='0')sl++;
    		else sl--;
		}
		nsl=0;
		ans=0;
		if(sl==0)
		{
			if(0==x)
			{
				printf("-1\n");
				continue;
			}
		}
		else if((x)%sl==0&&(x)/sl>=0)ans++;
		flag=false;
		for(int j=1;j<n;j++)
		{
			if(s[j]=='0')nsl++;
			else nsl--;
			if(sl==0)
			{
				if(nsl==x)
				{
					printf("-1\n");
					flag=true;
					break;
				}
			}
			else if((x-nsl)%sl==0&&(x-nsl)/sl>=0)ans++;
		}
		if(flag==false)printf("%d\n",ans);
	}
	return 0;
}