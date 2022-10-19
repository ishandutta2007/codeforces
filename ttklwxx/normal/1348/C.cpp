#include<iostream>
#include<cstdio>
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
char str[200001];
int main()
{
	int n,t,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		scanf("%s",str+1);
		sort(str+1,str+n+1);
		printf("%c",str[k]);
		if(str[k]==str[1]&&str[k+1]==str[n])for(int i=1;i<=(n-1)/k;i++)printf("%c",str[k+1]); 
	    else if(str[k]==str[1])for(int i=k+1;i<=n;i++)printf("%c",str[i]);
	    printf("\n");
	}
	return 0;
}