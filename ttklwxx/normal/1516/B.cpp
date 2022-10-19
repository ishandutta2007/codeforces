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
int a[114514],qz[114514];
int main()
{
	int t,n,k;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			qz[i]=qz[i-1]^a[i];
			k^=a[i];
		}
		if(k==0)
		{
			printf("YES\n");
			continue;
		}
		flag=false;
		for(int i=1;i<=n-2;i++)
		{
			if(qz[i]!=k)continue;
			for(int j=i+1;j<=n-1;j++)
			{
				if(qz[j]^qz[i]!=k)continue;
				flag=true;
				break;
			}
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
}