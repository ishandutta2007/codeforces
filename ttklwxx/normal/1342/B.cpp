#include<iostream>
#include<cstdio>
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
char str[1001];
signed main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		flag=false;
		for(int i=1;i<=n-1;i++)
		{
			if(str[i]!=str[i+1])
			{
				flag=true;
				break;
		    }
		}
		if(flag==false)
		{
			printf("%s\n",str+1);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			printf("10");
		}
		printf("\n");
	}
	return 0;
}