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
char s[1001];
int l[1001],r[1001];
bool cz[1001];
int main()
{
	int n,ans=0;
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		l[i]=i-1;
		r[i]=i+1;
		cz[i]=1;
	}
	for(int i=25;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(!cz[k])continue;
				if(s[k]!='a'+i)continue;
				if(s[l[k]]=='a'+i-1||s[r[k]]=='a'+i-1)
				{
					ans++;
					l[r[k]]=l[k];
					r[l[k]]=r[k];
					cz[k]=0;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}