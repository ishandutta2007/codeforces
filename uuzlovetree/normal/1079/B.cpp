#include<bits/stdc++.h>
#define maxn 105
using namespace std;
char s[maxn];
int a,b,c;
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	if(1<=n&&n<=20)
	{
		a=1;b=n;c=1;
	}
	else if(21<=n&&n<=40)
	{
		a=2;
		if(n%2)
		{
			b=n/2+1;c=n-(n/2)*2;
		}
		else
		{
			b=n/2;c=2;
		}
	}
	else if(41<=n&&n<=60)
	{
		a=3;
		if(n%3)
		{
			b=n/3+1;c=n-(n/3)*3;
		}
		else
		{
			b=n/3;c=3;
		}
	}
	else if(61<=n&&n<=80)
	{
		a=4;
		if(n%4)
		{
			b=n/4+1;c=n-(n/4)*4;
		}
		else
		{
			b=n/4;c=4;
		}
	}
	else
	{
		a=5;
		if(n%5)
		{
			b=n/5+1;c=n-(n/5)*5;
		}
		else
		{
			b=n/5;c=5;
		}
	}
	printf("%d %d\n",a,b);
	int cnt=0;
	for(int i=1;i<=a;++i)
	{
		if(i<=c)
		{
			for(int j=1;j<=b;++j)printf("%c",s[++cnt]);
			puts("");
		}
		else
		{
			for(int j=1;j<b;++j)printf("%c",s[++cnt]);
			printf("*");
			puts("");
		}
	}
	return 0;
}