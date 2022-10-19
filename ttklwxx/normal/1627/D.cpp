#include<iostream>
#include<cstdio>
#include<vector>
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
int sl[1000005];
int zs[1000005];
int a[1000005];
int main()
{
	int n,ans=0;
	bool flag;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sl[a[i]]++;
	}
	for(int i=1000000;i>=1;i--)
	{
		for(int j=i;j<=1000000;j+=i)zs[i]+=sl[j];
		if(zs[i]==0)continue;
		flag=true;
		for(int j=2*i;j<=1000000;j+=i)
		{
			if(zs[i]==zs[j])
			{
				//printf("%d %d\n",i,j);
				flag=false;
				break;
			}
		}
		if(flag==true)ans++;
	}
	printf("%d\n",ans-n);
	return 0;
}