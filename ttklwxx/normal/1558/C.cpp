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
int cz[1000005],cnt;
inline void reverse(int k)
{
	for(int i=1;i<=k/2;i++)swap(a[i],a[k+1-i]);
	cz[++cnt]=k;
}
int main()
{
	int t,n,wk,wj;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2!=i%2)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)
		{
			printf("-1\n");
			continue;
		}
		cnt=0;
		for(int k=n;k>=2;k-=2)
		{
			for(int i=1;i<=n;i++)if(a[i]==k)
			{
				wk=i;
				break;
			}
			reverse(wk);
			for(int i=1;i<=n;i++)if(a[i]==k-1)
			{
				wj=i;
				break;
			}
			reverse(wj-1);
			reverse(wj+1);
			reverse(3);
			reverse(k);
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)printf("%d ",cz[i]);
		printf("\n");
	}
	return 0;
}