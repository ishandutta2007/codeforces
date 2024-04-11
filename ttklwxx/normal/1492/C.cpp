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
char s[500005],t[500005];
int pp[500005],maxp[500005];
int main()
{
	int n,m,ans=0;
	n=read();
	m=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	pp[n+1]=m+1;
	for(int i=n;i>=1;i--)
	{
		if(pp[i+1]>1&&t[pp[i+1]-1]==s[i])
		{
			pp[i]=pp[i+1]-1;
			maxp[pp[i]]=i;
		}
		else pp[i]=pp[i+1];
	}
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		if(t[pos+1]==s[i])pos++;
		if(pos==m)break;
		if(pos!=0)ans=max(ans,maxp[pos+1]-i);
	}
	printf("%d\n",ans);
	return 0;
}