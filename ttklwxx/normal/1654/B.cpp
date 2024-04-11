#include<iostream>
#include<cstdio>
#include<algorithm>
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
char s[200005];
int sl[200005];
int main()
{
	int t,n,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		//n=read();
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=26;i++)sl[i]=0;
		for(int i=1;i<=n;i++)sl[s[i]-'a'+1]++;
		sth=n;
		for(int i=1;i<=n;i++)
		{
			sl[s[i]-'a'+1]--;
			if(sl[s[i]-'a'+1]==0)
			{
				sth=i;
				break;
			}
		}
		for(int i=sth;i<=n;i++)printf("%c",s[i]);
		printf("\n");
	}
}