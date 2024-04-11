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
char s[100001];
int main()
{
    int n,len;
    n=read();
    for(int i=1;i<=n;i++)
    {
    	scanf("%s",s+1);
    	len=strlen(s+1);
    	if(s[len]=='o'&&s[len-1]=='p')printf("FILIPINO\n");
    	else if(s[len]=='u'&&s[len-1]=='s'&&s[len-2]=='e'&&s[len-3]=='d')printf("JAPANESE\n");
    	else if(s[len]=='u'&&s[len-1]=='s'&&s[len-2]=='a'&&s[len-3]=='m')printf("JAPANESE\n");
    	else printf("KOREAN\n");
	}
    return 0;
}