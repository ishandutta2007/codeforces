#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[15][15],x[15][10005],top[15],size[1<<15];
ll ans[1<<15],f[1<<15][15],s[1<<15],g[1<<15];
int len[15],num,llen[1005][15],nnum[1005],tot;
ll res[1005];
int calc(int s)
{
	if(size[s]!=-1)return size[s];
	int ss=s;
	int ans=0;
	while(s)
	{
		ans+=s&1;
		s>>=1;
	}
	return size[ss]=ans;
}
void calc()
{
	memset(g,0,sizeof(g));
	tot++;
	nnum[tot]=num;
	for(int i=1;i<=num;i++)
	  llen[tot][i]=len[i];
	g[0]=1;
	int nows=0;
	for(int i=1;i<=num;i++)
	{
		for(int j=1;j<=top[nows];j++)
		for(int k=((1<<n)-1)^x[nows][j];k;k=(k-1)&(((1<<n)-1)^x[nows][j]))
		{
			if(size[k]!=len[i])continue;
			g[x[nows][j]|k]+=g[x[nows][j]]*s[k];
		}
		nows+=len[i];
	}
	res[tot]=g[(1<<n)-1];
//	for(int i=1;i<=num;i++)printf("%d ",len[i]);
//	printf("\n%lld\n",res[tot]);
}
bool cmp(int a,int b)
{
	return a>b;
}
ll solve(int s)
{
	num=0;
	int last=-1;
	for(int i=0;i<n-1;i++)
	{
		if((1<<i)&s)continue;
		else
		{
			len[++num]=i-last;
			last=i;
		}
	}
	len[++num]=n-1-last;
	sort(len+1,len+num+1,cmp);
	int k=0;
	for(int i=1;i<=tot;i++)
	{
		bool flag=1;
		for(int j=1;j<=num;j++)
		{
			if(len[j]!=llen[i][j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			k=i;
			break;
		}
	}
	return res[k];
}
void dfs(int rest,int last)
{
	if(rest==0)return calc();
	for(int i=1;i<=min(rest,last);i++)
	{
		len[++num]=i;
		dfs(rest-i,i);
		num--;
	}
}
char ss[25];
int main()
{
	memset(size,-1,sizeof(size));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",ss);
		for(int j=0;j<n;j++)
		  a[i][j]=ss[j]-'0';
	}
	for(int i=0;i<n;i++)
	  f[1<<i][i]=1;
	for(int s=0;s<(1<<n);s++)
	{
		for(int i=0;i<n;i++)
		{
			if(!((1<<i)&s))continue;
			for(int j=0;j<n;j++)
			{
				if((1<<j)&s)continue;
				if(a[i][j])f[s|(1<<j)][j]+=f[s][i];
			}
		}
	}
	for(int x=0;x<(1<<n);x++)
	  for(int i=0;i<n;i++)
	    s[x]+=f[x][i];
	for(int i=0;i<(1<<n);i++)x[calc(i)][++top[calc(i)]]=i;
	dfs(n,n);
	for(int i=0;i<(1<<(n-1));i++)
	{
		ans[i]=solve(i);
	}
	for(int i=(1<<(n-1))-1;i>=0;i--)
	{
		for(int j=((1<<(n-1))-1)^i;j;j=(j-1)&(((1<<(n-1))-1)^i))
		{
			ans[i]-=ans[j|i];
		}
	}
	for(int i=0;i<(1<<(n-1));i++)printf("%lld ",ans[i]);
	printf("\n");
}