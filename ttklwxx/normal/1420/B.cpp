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
int a[100001];
int sl[101]; 
signed main()
{
	int t,n;
	int ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=0;i<=30;i++)sl[i]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
		    a[i]=read();
		    for(int j=30;j>=0;j--)
		    {
		    	if((a[i]&(1<<j))!=0)
		    	{
		    		ans+=sl[j];
		    		sl[j]++;
		    		break; 
				}
			}
	    }
	    printf("%lld\n",ans);
	} 
	return 0;
}