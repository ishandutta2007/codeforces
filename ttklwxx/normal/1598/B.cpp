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
int a[100001][6];
int main()
{
	int t,n,sl1,sl2;
	bool flag; 
	bool tflag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=5;j++)a[i][j]=read();
		}
		flag=false;
		for(int i=1;i<=5;i++)
		{
			for(int j=i+1;j<=5;j++)
			{
				tflag=true;
				sl1=sl2=0;
				for(int sth=1;sth<=n;sth++)
				{
					if(a[sth][i]==0&&a[sth][j]==0)
					{
						tflag=false;
						break;
					}
					if(a[sth][i]==1)sl1++;
					if(a[sth][j]==1)sl2++;
				}
				if(tflag==false)continue;
				if(sl1>=n/2&&sl2>=n/2)
				{
					flag=true;
					break;
				}
			}
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}