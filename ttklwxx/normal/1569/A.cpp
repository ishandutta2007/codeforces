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
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		flag=false;
		for(int i=1;i<=n-1;i++)
		{
			if(s[i]!=s[i+1])
			{
				printf("%d %d\n",i,i+1);
				flag=true;
				break; 
			}
		} 
		if(flag==false)printf("-1 -1\n");
	 } 
	return 0;
}