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
int hz[100005][27];
char s[100005],t[100005];
int main()
{
	int zs,ns,nt,ans=0,now,cl;
	zs=read();
	for(int i=1;i<=zs;i++)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		ns=strlen(s+1);
		nt=strlen(t+1);
		for(int i=1;i<=26;i++)hz[ns][i]=0;
		for(int i=ns-1;i>=0;i--)
		{
			 for(int j=1;j<=26;j++)
			 {
			 	if(s[i+1]==j+'a'-1)
			 	{
			 		hz[i][j]=i+1;
				}
				else hz[i][j]=hz[i+1][j];
			 }
		}
		ans=1;
		cl=0;
		for(now=1;now<=nt;now++)
		{
			if(hz[cl][t[now]-'a'+1]==0)
			{
				ans++;
				cl=hz[0][t[now]-'a'+1];
				if(cl==0)
				{
					ans=-1;
					break;
				}
			}
			else cl=hz[cl][t[now]-'a'+1];
		}
		printf("%d\n",ans);
	}
	return 0;
}