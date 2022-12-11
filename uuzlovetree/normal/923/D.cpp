#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,q;
char s[maxn],t[maxn];
int slsta[maxn],ssum[maxn];
int tlsta[maxn],tsum[maxn];
int Ans[maxn],cnt;
int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	int now=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='A')
		{
			ssum[i]=ssum[i-1];
			now++;
			slsta[i]=now;
		}
		else
		{
			ssum[i]=ssum[i-1]+1;
			now=0;
			slsta[i]=now;
		}
	}
	now=0;
	for(int i=1;i<=m;++i)
	{
		if(t[i]=='A')
		{
			tsum[i]=tsum[i-1];
			now++;
			tlsta[i]=now;
		}
		else
		{
			tsum[i]=tsum[i-1]+1;
			now=0;
			tlsta[i]=now;
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int yes=1;
		if(tsum[d]-tsum[c-1]==0)
		{
			if(ssum[b]-ssum[a-1]!=0)yes=0;
			if((d-c+1)>(b-a+1))yes=0;
			if((d-c+1)%3!=(b-a+1)%3)yes=0;
		}
		else if(ssum[b]-ssum[a-1]==0)
		{
			if(tlsta[d]>=b-a+1)yes=0;
			if((tsum[d]-tsum[c-1])%2!=0)yes=0;
		}
		else
		{
			if(tlsta[d]>slsta[b])yes=0;
			int t=slsta[b]-tlsta[d];
			int x=ssum[b]-ssum[a-1],y=tsum[d]-tsum[c-1];
			if(t%3!=0)
			{
				x+=2;
				if(x>y)yes=0;
				if((tsum[d]-tsum[c-1])%2!=(ssum[b]-ssum[a-1])%2)yes=0;
			}
			else
			{
				if(x>y)yes=0;
				if((tsum[d]-tsum[c-1])%2!=(ssum[b]-ssum[a-1])%2)yes=0;
			}
		}
		Ans[++cnt]=yes;
	}
	for(int i=1;i<=cnt;++i)printf("%d",Ans[i]);
}