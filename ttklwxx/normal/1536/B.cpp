#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
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
char s[10000];
struct sth
{
	char zf[20];
}now;
bool operator<(struct sth x,struct sth y)
{
	for(int i=0;i<20;i++)if(x.zf[i]!=y.zf[i])return x.zf[i]<y.zf[i];
	return 0; 
}
map<struct sth,int>ma;
int len;
char ans[20];
bool dfs(int k)
{
	//printf("%d ",k);
	//printf("vis:");
	//cout<<now<<endl;
	if(k==len)
	{
		now.zf[k]=0;
		if(ma[now]==0)
		{
			for(int i=0;i<=len;i++)ans[i]=now.zf[i];
			return true;
		}
		return false;
	}
	for(int i=1;i<=26;i++)
	{
		now.zf[k]='a'+i-1;
		if(dfs(k+1)==true)return true;
	}
	now.zf[k]=0;
	return false;
}
int main()
{
	int t,n;
	bool flag1=false,flag2=false;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		ma.clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=i+3&&j<=n;j++)
			{
				for(int k=i;k<=j;k++)now.zf[k-i]=s[k];
				for(int k=j-i+1;k<20;k++)now.zf[k]=0;
				ma[now]=1;
			}
		}
		for(int i=1;i<=4;i++)
		{
			len=i;
			if(dfs(0)==true)
			{
				cout<<ans<<endl;
				break;
			}
		}
	} 
	return 0;
}