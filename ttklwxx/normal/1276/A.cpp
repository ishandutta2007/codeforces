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
char str[200001];
int sta[200001],tmp;
int main()
{
    int t,n;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	scanf("%s",str+1);
    	n=strlen(str+1);
    	for(int j=1;j<=n;j++)
    	{
    		if(j>=3&&j<=n-2&&str[j-2]=='t'&&str[j-1]=='w'&&str[j]=='o'&&str[j+1]=='n'&&str[j+2]=='e')sta[++tmp]=j;
    		else if(j>=3&&str[j-2]=='t'&&str[j-1]=='w'&&str[j]=='o')sta[++tmp]=j-1;
    		else if(j<=n-2&&str[j]=='o'&&str[j+1]=='n'&&str[j+2]=='e')sta[++tmp]=j+1;
		}
		printf("%d\n",tmp);
		for(int j=1;j<=tmp;j++)printf("%d ",sta[j]);
		printf("\n");
		tmp=0;
	}
    return 0;
}