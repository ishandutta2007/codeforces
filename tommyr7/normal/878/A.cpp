#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[37],n,now;
char op[10];
int main()
{
	n=read();
	for (int i=0;i<=30;i++)
		a[i]=2;
	for (int i=1;i<=n;i++)
	{
		scanf("%s%d",op,&now);
		for (int t=0;t<=10;t++)
		{
			int del=now&(1<<t);
			if (del==0)
			{
				if (op[0]=='&') a[t]=0;
			} else
			{
				if (op[0]=='|') a[t]=1;
				else if (op[0]=='^')
				{
					if (a[t]<=1) a[t]=1-a[t];
					else a[t]=5-a[t];
				}
			}
		}
	}
	int ans1=0,ans2=0,ans3=0;
	for (int t=0;t<10;t++)
	{
		if (a[t]==3) ans1+=(1<<t);
		else if (a[t]==1) ans2+=(1<<t);
		else if (a[t]==0) ans3+=(1<<t);
	}
	printf("%d\n",3);
	printf("^ %d\n",ans1);
	printf("& %d\n",1023-ans3);
	printf("| %d\n",ans2);
	return 0;
}