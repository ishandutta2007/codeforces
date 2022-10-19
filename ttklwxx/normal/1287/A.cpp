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
    int t,ans,n,x,nans;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		scanf("%s",str+1);
		ans=0;
		for(x=1;x<=n&&str[x]=='P';x++);
		nans=0;
		for(;x<=n;x++)
		{
			if(str[x]=='P')nans++;
			else ans=max(ans,nans),nans=0;
		}
		ans=max(ans,nans);
		printf("%d\n",ans);
	}
    return 0;
}