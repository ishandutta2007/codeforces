#include<iostream>
#include<cstdio>
#include<cstring>
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
char str[300001]; 
int main()
{
	int t,r,p,s,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		r=p=s=0;
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='R')p++;
			else if(str[i]=='S')r++;
			else s++;
		}
		if(r>=p&&r>=s)
		{
			for(int i=1;i<=n;i++)printf("R");
			printf("\n");
			continue;
		}
		if(s>=p&&s>=r)
		{
			for(int i=1;i<=n;i++)printf("S");
			printf("\n");
			continue;
		}
		if(p>=r&&p>=s)
		{
			for(int i=1;i<=n;i++)printf("P");
			printf("\n");
			continue;
		}
	} 
	return 0;
}