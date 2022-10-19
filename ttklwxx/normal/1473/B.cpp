#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
char a[105],b[105];
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
int main()
{
	int t,na,nb,sth;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s%s",a+1,b+1);
		na=strlen(a+1);
		nb=strlen(b+1);
		sth=na*nb/gcd(na,nb);
		flag=false;
		for(int i=0;i<sth;i++)
		{
			if(a[i%na+1]!=b[i%nb+1])
			{
				flag=true;
				break;
			}
		}
		if(flag==true)printf("-1\n");
		else
		{
			for(int i=0;i<sth;i++)printf("%c",a[i%na+1]);
			printf("\n");
		}
	}
	return 0;
}