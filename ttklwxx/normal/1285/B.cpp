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
int n[300001],a[300001];
signed main()
{
    int t,n,s=0,flag;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	for(int j=1;j<=n;j++)a[j]=read();
    	s=0;
    	flag=true;
    	for(int j=1;j<=n-1;j++)
    	{
    		s+=a[j];
    		if(s<=0)
			{
				printf("NO\n");
    			flag=false;
    			break;
			}
		}
		if(flag==false)continue;
		s=0;
		for(int j=n;j>=2;j--)
		{
			s+=a[j];
    		if(s<=0)
			{
				printf("NO\n");
    			flag=false;
    			break;
			}
		}
		if(flag==true)
		{
			printf("YES\n");
		}
	}
    return 0;
}