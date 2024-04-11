#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
int a[2000005],pos[2000005];
map<int,int>maq,mah;
bool bi(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	int n;
	n=read();
	if(n>=3000)n=3000;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			if(maq[a[i]+a[j]]!=0)
			{
				if(mah[a[i]+a[j]]==j||mah[a[i]+a[j]]==i||maq[a[i]+a[j]]==j)continue;
				printf("YES\n");
				printf("%d %d %d %d\n",i,j,maq[a[i]+a[j]],mah[a[i]+a[j]]);
				return 0;
			}
			maq[a[i]+a[j]]=j;
			mah[a[i]+a[j]]=i;
		}
	}
	printf("NO\n");
	return 0;
}