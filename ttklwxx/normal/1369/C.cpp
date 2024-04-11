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
int a[300001],w[300001];
signed main()
{
    int t,n,k,x,ans=0,sth,nn;
    t=read();
    for(int greg=1;greg<=t;greg++)
    {
    	n=read();
    	k=read();
    	for(int i=1;i<=n;i++)a[i]=read();
    	for(int i=1;i<=k;i++)w[i]=read();
    	sort(a+1,a+n+1);
    	sort(w+1,w+k+1);
    	x=1;
    	ans=0;
    	nn=n;
    	for(sth=1;sth<=k;sth++)
        {
        	if(w[sth]!=1)break;
        	ans+=2*a[nn];
        	nn--;
		}
    	for(int i=k;i>=sth;i--)
    	{
    		ans+=a[x]+a[n-i+1];
    		x+=w[i]-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}