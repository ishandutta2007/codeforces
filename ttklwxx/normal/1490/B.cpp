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
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int main()
{
	int t,x,y,z,n,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=y=z=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]%3==0)x++;
			else if(a[i]%3==1)y++;
			else z++;
		}
		ans=0;
		while(x!=n/3||y!=n/3||z!=n/3)
		{
			if(x>n/3&&y<=n/3)
			{
				x--;
				y++;
			}
			else if(y>n/3&&z<=n/3)
			{
				y--;
				z++;
			}
			else if(z>n/3&&x<=n/3)
			{
				z--;
				x++;
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}