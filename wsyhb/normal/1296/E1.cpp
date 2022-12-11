#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=200+5,M=4e4+5;
char s[N];
int End[M],Last[N],Next[M],dis[N];
int cnt;
void add(int x,int y)
{
	End[++cnt]=y;
	Next[cnt]=Last[x];
	Last[x]=cnt;
}
bool flag[N];
bool f;
void dfs(int x)
{
	flag[x]=true;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(flag[y])
		{
			if(dis[x]==dis[y]) f=true;
		}
		else
		{
			dis[y]=dis[x]^1;
			dfs(y);
		}
	}
}
int main()
{
	int n,cnt=0;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(s[i]>s[j]) add(i,j),add(j,i);
	for(int i=1;i<=n;i++)
		if(!flag[i]) dfs(i);
	if(f) printf("NO\n");
	else
	{
		printf("YES\n");
		for(int i=1;i<=n;i++) printf("%d",dis[i]); 
	}
	return 0;
}