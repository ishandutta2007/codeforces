#include<iostream>
#include<cstdio>
#include<cstring>
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
int b[2001],cx[2001],a[2001];
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
	    n=read();
	    for(int i=1;i<=2*n;i++)cx[i]=false;
	    for(int i=1;i<=n;i++)b[i]=read(),cx[b[i]]=true;
	    for(int i=1;i<=n;i++)a[2*i-1]=b[i];
	    for(int i=1;i<=n;i++)
	    {
	    	flag=false;
	    	for(int j=b[i]+1;j<=2*n;j++)if(!cx[j])
	    	{
	    		flag=true;
	    		a[2*i]=j;
	    		cx[j]=true;
	    		break;
			}
			if(flag==false)
			{
				printf("-1\n");
				break;
			}
		}
		if(flag==false)continue;
		for(int i=1;i<=2*n;i++)printf("%d ",a[i]);
		printf("\n");
	} 
	return 0;
}