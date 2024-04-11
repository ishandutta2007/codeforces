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
char s[400005];
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		flag=true;
		for(int i=n;i>=2;i--)
		{
			if(s[i]-'0'+s[i-1]-'0'>=10)
			{
				for(int j=1;j<=i-2;j++)printf("%c",s[j]);
				printf("%d",s[i-1]-'0'+s[i]-'0');
				for(int j=i+1;j<=n;j++)printf("%c",s[j]);
				printf("\n");
				flag=false;
				break;
			}
		}
		if(flag==false)continue;
		printf("%d",s[1]-'0'+s[2]-'0');
		for(int j=3;j<=n;j++)printf("%c",s[j]);
		printf("\n");
	}
	return 0;
}