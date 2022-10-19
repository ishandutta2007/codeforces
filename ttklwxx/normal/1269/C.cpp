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
char a[300001];
int b[300001];
signed main()
{
    int n,k,ans1=0,ans2=0;
    n=read();
    k=read();
    scanf("%s",a+1);
    bool flag=false;
    for(int i=1;i<=n-k;i++)
    {
    	if(a[i]<a[i+k])
    	{
    		flag=true;
    		break;
    	}
    	if(a[i]>a[i+k])break;
    }
    if(flag==false)
    {
    	printf("%lld\n",n);
    	for(int i=1;i<=k;i++)
    	{
    		printf("%c",a[i]);
    	}
    	for(int i=k+1;i<=n;i++)
    	{
    		printf("%c",a[(i-1)%k+1]);
    	}
    }
    else
    {
    	printf("%lld\n",n);
    	for(int i=k;i>=1;i--)
    	{
    		a[i]++;
    		if(a[i]!='9'+1)break;
    		else a[i]='0';
    	}
    	for(int i=1;i<=k;i++)
    	{
    		printf("%c",a[i]);
    	}
    	for(int i=k+1;i<=n;i++)
    	{
    		printf("%c",a[(i-1)%k+1]);
    	}
    }
	return 0; 
}