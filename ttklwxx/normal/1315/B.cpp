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
char s[200001];
int main()
{
	int t,p,a,b,n,cos,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
	    a=read();
	    b=read();
	    p=read();
	    scanf("%s",s+1);
	    n=strlen(s+1);
	    cos=0;
	    ans=1;
	    s[n]='C';
	    for(int i=n;i>=1;i--)
	    {
	    	if(s[i-1]!=s[i])
	    	{
	    		if(s[i-1]=='A')cos+=a;
	    		else cos+=b;
			}
			if(cos>p)
			{
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}