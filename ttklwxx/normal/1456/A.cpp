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
char str[200005];
int sl[200005];
int main()
{
	int t,n,p,k,ans,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		p=read();
		k=read();
		scanf("%s",str+1);
		for(int i=0;i<k;i++)sl[i]=0;
		for(int i=p;i<=n;i++)
		{
			if(str[i]=='1')continue;
			sl[(i-p)%k]++;
		}
		x=read();
		y=read();
		ans=2000000000;
		for(int i=0;i<=n-p;i++)
		{
			ans=min(ans,y*i+x*sl[i%k]);
			if(str[i+p]=='0')sl[i%k]--;
		}
		printf("%d\n",ans);
	}
	return 0;
}