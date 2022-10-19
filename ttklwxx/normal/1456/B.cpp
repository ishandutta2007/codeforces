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
int a[200005]; 
int main()
{
	int n,ans=1000000000;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read()^a[i-1];
	if(n>=100)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			for(int k=i;k<=n;k++)
			{
				if((a[i-1]^a[j-1])>(a[i-1]^a[k]))
				{
					ans=min(ans,k-j-1);
				}
			}
		}
	}
	if(ans!=1000000000)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}