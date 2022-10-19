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
int n,x;
int a[200001];
int main()
{
	int t,ans=0,nans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
	    n=read();
	    x=read();
	    for(int i=1;i<=n;i++)a[i]=(a[i-1]+read())%x;
	    ans=-1;
	    nans=1000000000;
	    for(int i=1;i<=n;i++)
	    {
	    	if(a[i]%x!=0)
	    	{
	    		ans=max(ans,i);
	    		if(nans==1000000000)nans=i;
			}
			else
			{
				ans=max(ans,i-nans);
			}
		}
		if(ans>0)printf("%d\n",ans);
		else printf("-1\n");
	} 
	return 0;
}