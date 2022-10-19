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
char a[2000005],b[2000005];
int n;
int c[2000005];
int get(int x)
{
	int cur=0,res=0;
	for(int i=1;i<=n;i++)
	{
		cur+=x*c[i];
		res=max(res,cur);
		if(cur<0)cur = 0;
	}
	return res;
}
int main()
{
	int s1=0,s2=0;
	n=read();
	scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i]&&a[i]=='0')c[i]=-1,s1++;
		else if(a[i]!=b[i]&&a[i]=='1')c[i]=1,s2++;
	}
	if(s1!=s2)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",max(get(1),get(-1)));
	return 0;
}