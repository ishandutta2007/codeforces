#include<iostream>
#include<cstdio>
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
char str[200001];
int sta[200001],tmp;
signed main()
{
    int n,sl=0;
    n=read();
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)
    {
    	if(str[i]=='B')sl++;
    }
	if(sl%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='B')
			{
				sta[++tmp]=i;
				str[i]='W';
				if(str[i+1]=='B')str[i+1]='W';
				else str[i+1]='B';
			}
		}
		printf("%d\n",tmp);
		for(int i=1;i<=tmp;i++)printf("%d\n",sta[i]);
	}
	else if((n-sl)%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='W')
			{
				sta[++tmp]=i;
				str[i]='B';
				if(str[i+1]=='B')str[i+1]='W';
				else str[i+1]='B';
			}
		}
		printf("%d\n",tmp);
		for(int i=1;i<=tmp;i++)printf("%d\n",sta[i]);
	}
	else printf("-1\n");
    return 0;
}