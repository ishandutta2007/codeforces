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
char str1[1005],str2[1005];
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",str1+1);
		scanf("%s",str2+1);
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(str1[i]=='1'&&str2[i]=='1')
			{
				flag=true;
				break;
			}
		} 
		if(flag==true)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}