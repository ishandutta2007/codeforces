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
char str[100001];
int main()
{
	int t,n,m,x,y,lx,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
	    m=read();
	    x=read();
	    y=read();
	    y=min(y,2*x);
	    ans=0;
	    for(int i=1;i<=n;i++)
	    {
	    	scanf("%s",str+1);
	    	lx=0;
	    	for(int j=1;j<=m;j++)
	    	{
	    		if(str[j]=='*')
	    		{
	    		    ans+=(lx/2)*y+(lx%2)*x;
	    		    lx=0;
				}
				else lx++;
			}
			ans+=(lx/2)*y+(lx%2)*x;
		}
		printf("%d\n",ans);
	} 
	return 0;
}