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
char s[10005];
int a[105][105];
int main()
{
	int t,n;
	bool flag,fl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				for(int j=1;j<=n;j++)
				{
					if(i==j)continue;
					a[i][j]=a[j][i]=2;
				}
			}
		}
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='2')
			{
				fl=false;
				for(int j=1;j<=n;j++)
				{
					if(i==j)continue;
					if(a[i][j]!=0)continue;
					a[i][j]=3;
					a[j][i]=1;
					fl=true;
					break;
				}
				if(fl==false)
				{
					flag=true;
					break;
				}
			}
		}
		if(flag==true)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)printf("X");
				else if(a[i][j]==3)printf("+");
				else if(a[i][j]==1)printf("-");
				else printf("=");
			}
			printf("\n");
		}
	}
	return 0;
}