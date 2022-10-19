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
int a[2001],col[2001];
int gc[101]={0,2,3,5,7,11,13,17,19,23,29,31};
bool cx[101];
int dy[101];
int gcd(int x,int y)
{
	if(x==0)return y;
	if(y==0)return x;
	while(x^=y^=x^=y%=x);
	return y;
}
int main()
{
	int t,n,co,x;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),col[i]=0;
		for(int i=1;i<=11;i++)cx[i]=false,dy[i]=0;
		co=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=11;j++)
			{
				if(a[i]%gc[j]==0)
				{
					col[i]=j;
					cx[j]=true;
					gc[j]=gcd(gc[j],a[i]);
					break;
				}
			}
		}
		for(int i=1;i<=11;i++)if(cx[i])co++;
		x=0;
		for(int i=1;i<=11;i++)
		{
			if(cx[i])
			{
				x++;
				dy[i]=x;
			}
		}
		printf("%d\n",co);
		for(int i=1;i<=n;i++)printf("%d ",dy[col[i]]);
		printf("\n");
	} 
	return 0;
}