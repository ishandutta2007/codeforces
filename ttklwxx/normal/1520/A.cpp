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
char s[200005];
bool cx[27];
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		scanf("%s",s+1);
		flag=false;
		for(int i=1;i<=26;i++)cx[i]=false;
		for(int i=1;i<=n;i++)
		{
			if(cx[s[i]-'A'+1]==true&&s[i-1]!=s[i])
			{
				flag=true;
				break;
			}
			cx[s[i]-'A'+1]=true;
		}
		if(flag==true)printf("NO\n");
		else printf("YES\n");
	}
}