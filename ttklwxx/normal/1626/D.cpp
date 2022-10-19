#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#define int long long
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
int a[400005];
int qz[400005];
int cal(int k)
{
	int sth=1;
	while(sth<k)sth*=2;
	return sth-k;
}
signed main()
{
	int t,n,x,y,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)qz[i]=0;
		for(int i=1;i<=n;i++)a[i]=read(),qz[a[i]]++;
		for(int i=1;i<=n;i++)qz[i]+=qz[i-1];
		ans=1000000000;
		for(int i=0;i<=18;i++)
		{
			x=0;
			while(x<=n-1&&qz[x+1]<=(1<<i))x++;
			if(x==0)continue;
			for(int j=0;j<=18;j++)
			{
				y=n+1;
				while(y>=x+2&&qz[n]-qz[y-2]<=(1<<j))y--;
				ans=min(ans,(1<<i)-qz[x]+(1<<j)-qz[n]+qz[y-1]+cal(qz[y-1]-qz[x]));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}