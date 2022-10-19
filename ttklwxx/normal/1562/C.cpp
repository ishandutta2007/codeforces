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
char str[200005];
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",str+1);
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='0')
			{
				if(i<=n/2)printf("%d %d %d %d\n",i,n,i+1,n);
				else printf("%d %d %d %d\n",1,i,1,i-1);
				flag=true;
				break;
			}
		}
		if(flag==true)continue;
		printf("%d %d %d %d\n",1,n/2*2,1,n/2);
	}
	return 0;
}