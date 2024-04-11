#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
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
int a,b,c,d;
char str[200001];
signed main()
{
	int t,len;
	t=read();
	for(int i=1;i<=t;i++)
	{
		scanf("%s",str+1);
		len=strlen(str+1);
		a=0;
		b=0;
		c=0;
		d=0;
		for(int j=1;j<=len;j++)
		{
			if(str[j]=='L')a++;
			else if(str[j]=='U')b++;
			else if(str[j]=='R')c++;
			else d++;
		}
		if(min(b,d)==0&&min(a,c)==0)
		{
		   printf("0\n\n");
		   continue;
	    }  
		if(b==0||d==0)
		{
			printf("2\n");
			printf("LR\n");
			continue;
		}
		else if(a==0||c==0)
		{
			printf("2\n");
			printf("UD\n");
			continue;
		}
		printf("%lld\n",2*min(a,c)+2*min(b,d));
		for(int j=1;j<=min(a,c);j++)printf("L");
		for(int j=1;j<=min(b,d);j++)printf("U");
		for(int j=1;j<=min(a,c);j++)printf("R");
		for(int j=1;j<=min(b,d);j++)printf("D");
		printf("\n");
	}
	return 0;
}