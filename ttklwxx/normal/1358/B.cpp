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
int sl[300001];
int main()
{
    int t,n,x,ans;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	for(int j=1;j<=n;j++)
    	{
    		x=read();
    		if(x>n)continue;
    		sl[x]++;
		}
		for(int j=2;j<=n;j++)sl[j]+=sl[j-1];
		ans=0;
		for(int j=1;j<=n;j++)if(sl[j]>=j)ans=sl[j];
		for(int j=1;j<=n;j++)sl[j]=0;
		printf("%d\n",ans+1);
	}
	return 0;
}