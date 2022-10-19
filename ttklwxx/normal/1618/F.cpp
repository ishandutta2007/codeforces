#include<iostream>
#include<cstdio>
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
int sx[105],cx;
int sy[105],cy;
int gre[105];
signed main()
{
	int x,y,tx;
	bool flag;
	x=read();
	tx=x;
	y=read();
	if(x==y)
	{
		printf("YES\n");
		return 0;
	}
	while(x>0)
	{
		sx[++cx]=x%2;
		x/=2;
	}
	while(y>0)
	{
		sy[++cy]=y%2;
		y/=2;
	} 
	for(int i=2;i<=cy-cx+1;i++)
	{
		flag=true;
		for(int j=1;j<=cx;j++)
		{
			if(sx[j]!=sy[i+j-1])
			{
				flag=false;
				break;
			}
		}
		if(flag==false)continue;
		for(int j=1;j<=i-1;j++)
		{
			if(sy[j]!=1)
			{
				flag=false;
				break;
			}
		}
		for(int j=i+cx;j<=cy;j++)
		{
			if(sy[j]!=1)
			{
				flag=false;
				break;
			}
		}
		if(flag==false)continue;
		printf("YES\n");
		return 0;
	}
	for(int i=1;i<=cx;i++)gre[i]=sx[i];
	for(int i=1;i<=cx;i++)sx[i]=gre[cx+1-i];
	for(int i=1;i<=cy-cx;i++)
	{
		flag=true;
		for(int j=1;j<=cx;j++)
		{
			if(sx[j]!=sy[i+j-1])
			{
				flag=false;
				break;
			}
		}
		if(flag==false)continue;
		for(int j=1;j<=i-1;j++)
		{
			if(sy[j]!=1)
			{
				flag=false;
				break;
			}
		}
		for(int j=i+cx;j<=cy;j++)
		{
			if(sy[j]!=1)
			{
				flag=false;
				break;
			}
		}
		if(flag==false)continue;
		printf("YES\n");
		return 0;
	}
	cx=0;
	while(tx%2==0)tx/=2;
	while(tx>0)
	{
		sx[++cx]=tx%2;
		tx/=2;
	}
	for(int i=1;i<=cy-cx+1;i++)
	{
		flag=true;
		for(int j=1;j<=cx;j++)
		{
			if(sx[j]!=sy[i+j-1])
			{
				flag=false;
				break;
			}
		}
		if(flag==false)continue;
		for(int j=1;j<=i-1;j++)
		{
			if(sy[j]!=1)
			{
				flag=false;
				break;
			}
		}
		for(int j=i+cx;j<=cy;j++)
		{
			if(sy[j]!=1)
			{
				flag=false;
				break;
			}
		}
		if(flag==false)continue;
		printf("YES\n");
		return 0;
	}
	for(int i=1;i<=cx;i++)gre[i]=sx[i];
	for(int i=1;i<=cx;i++)sx[i]=gre[cx+1-i];
	for(int i=1;i<=cy-cx+1;i++)
	{
		flag=true;
		for(int j=1;j<=cx;j++)
		{
			if(sx[j]!=sy[i+j-1])
			{
				flag=false;
				break;
			}
		}
		if(flag==false)continue;
		for(int j=1;j<=i-1;j++)
		{
			if(sy[j]!=1)
			{
				flag=false;
				break;
			}
		}
		for(int j=i+cx;j<=cy;j++)
		{
			if(sy[j]!=1)
			{
				flag=false;
				break;
			}
		}
		if(flag==false)continue;
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}