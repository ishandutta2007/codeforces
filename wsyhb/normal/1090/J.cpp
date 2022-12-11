#include<bits/stdc++.h>
using namespace std;
int n,m;
const int max_len=2e5+5;
int End[max_len],Last[max_len],Next[max_len],E;
inline void add_edge(int x,int y)
{
	End[++E]=y;
	Next[E]=Last[x];
	Last[x]=E;
}
int dfn[max_len][2],Time;
void dfs_init(int x)
{
	dfn[x][0]=++Time;
	for(int i=Last[x];i;i=Next[i])
		dfs_init(End[i]);
	dfn[x][1]=Time;
}
inline bool check(int x,int y) // whether x is an ancestor of y
{
	return dfn[y][0]>=dfn[x][0]&&dfn[y][0]<=dfn[x][1];
}
const int max_n=1e5+5;
int mat[max_n];
long long ans;
void dfs(int x,int mx,int se)
{
	if(x<=m+1)
	{
		if(mat[x]>mat[mx])
			se=mx,mx=x;
		else if(mat[x]>mat[se])
			se=x;
	}
	else
	{
		if(mx==x-m-1)
			ans+=m-mat[se];
		else
			ans+=m-mat[mx];
	}
	for(int i=Last[x];i;i=Next[i])
		dfs(End[i],mx,se);
}
char s[max_n],t[max_n],str[max_len];
int fail[max_len];
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=m;++i)
		str[i]=t[i];
	str[m+1]='*';
	for(int i=1;i<=n;++i)
		str[m+1+i]=s[i];
	int len=n+m+1;
	fail[1]=0;
	add_edge(0,1);
	for(int i=2,j=0;i<=len;++i)
	{
		while(j>0&&str[j+1]!=str[i])
			j=fail[j];
		j+=(str[j+1]==str[i]);
		fail[i]=j;
		add_edge(j,i);
	}
	dfs_init(0);
	for(int i=1;i<=m-1;++i)
	{
		int l=1,r=m-i,res=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i+mid))
				res=mid,l=mid+1;
			else
				r=mid-1;
		}
		mat[i]=res;
	}
	dfs(0,m+1,m+1);
	printf("%lld\n",ans);
	return 0;
}