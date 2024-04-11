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
char s[100005]; 
int main()
{
    int t,n;
    t=read();
    bool flag;
    for(int i=1;i<=t;i++)
    {
    	scanf("%s",s+1);
    	n=strlen(s+1);
    	flag=false;
    	for(int i=1;i<=n;i++)if(s[i]!='?'&&s[i]==s[i+1])
    	{
    		printf("-1\n");
    		flag=true;
    		break;
		}
		if(flag==true)
		{
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]!='?')printf("%c",s[i]);
			else if(s[i-1]!='a'&&s[i+1]!='a')printf("%c",'a'),s[i]='a';
			else if(s[i-1]!='b'&&s[i+1]!='b')printf("%c",'b'),s[i]='b';
			else if(s[i-1]!='c'&&s[i+1]!='c')printf("%c",'c'),s[i]='c';
		}
		printf("\n");
	}
    return 0;
}