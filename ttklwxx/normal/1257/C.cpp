#include<iostream>
#include<cstdio>
#include<cmath>
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
int a[300001],pre[300001];
int main()
{
    int t,x,y,n,ans;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		ans=1000000000;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(pre[a[i]]!=0)ans=min(ans,i-pre[a[i]]+1);
			pre[a[i]]=i;
		}
		if(ans!=1000000000)printf("%d\n",ans);
		else printf("-1\n");
		for(int i=1;i<=n;i++)pre[a[i]]=0;
	} 
    return 0;
}