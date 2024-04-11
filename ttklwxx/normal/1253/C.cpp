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
int a[300001],ans[300001];
signed main()
{
    int m,n;
    n=read();
    m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)a[i]=a[i]+a[i-1];
    for(int i=1;i<=n;i++)
    {
    	if(i<=m)printf("%lld ",ans[i]=a[i]);
    	else printf("%lld ",ans[i]=ans[i-m]+a[i]);
	}
	return 0;
}