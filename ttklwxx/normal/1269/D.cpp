#include<iostream>
#include<cstdio>
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
int n,x;
int a[300001];
signed main()
{
    int n,k,ans1=0,ans2=0;
    n=read();
    for(int i=1;i<=n;i++)
    {
    	a[i]=read();
    	if(i%2==1)
    	{
    		ans1+=(a[i]+1)/2;
    		ans2+=a[i]/2;
    	}
    	else
    	{
    		ans2+=(a[i]+1)/2;
    		ans1+=a[i]/2;
    	}
    }
    printf("%lld\n",min(ans1,ans2));
	return 0; 
}