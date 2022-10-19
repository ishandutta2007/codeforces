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
char s[200005];
int ans[200005];
int main()
{
	int t,n,k,sth,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		sth=k;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)ans[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(k%2==0&&s[i]=='0'&&sth>0)
			{
				sth--;
				ans[i]=1;
			}
			else if(k%2==1&&s[i]=='1'&&sth>0)
			{
				sth--;
				ans[i]=1;
			}
		}
		if(sth%2==0)ans[1]+=sth;
		else ans[n]+=sth;
		for(int i=1;i<=n;i++)
		{
			x=s[i]-'0';
			if(k%2==1)x^=1;
			if(ans[i]%2==1)x^=1;
			printf("%d",x);
		}
		printf("\n");
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");
	}
}