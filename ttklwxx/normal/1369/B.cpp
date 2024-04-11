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
char s[200001];
int main()
{
    int t,n,x;
    t=read();
    for(int greg=1;greg<=t;greg++)
    {
    	n=read();
    	scanf("%s",s+1);
    	for(x=1;x<=n;x++)
		{
		    if(s[x]=='0')printf("0");
		    else break;
		}
    	for(;x<=n;x++)
    	{
    		if(s[x]=='1'&&s[x+1]=='0')
			{
			    printf("0");
			    break;
			}
		}
		for(x=n;x>=1;x--)
		{
			if(s[x]=='0')break;
			printf("1");
		}
		printf("\n");
	}
	return 0;
}