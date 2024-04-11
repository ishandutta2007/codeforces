#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
typedef long long ll;
int ksm(int a,int n)
{
	int ans=1;
	a%=p;
	while(n)
	{
		if(n&1) ans=(ll)ans*a%p;
		a=(ll)a*a%p;
		n>>=1;
	}
	return ans;
}
const int N=1e5+5,M=2e5+5;
int End[M],Last[N],Next[M],Len[M],flag[N],dis[N];
int cnt;
void add(int x,int y,int z)
{
	End[++cnt]=y;
	Next[cnt]=Last[x];
	Last[x]=cnt;
	Len[cnt]=z;
}
bool f;
void dfs(int x)
{
	flag[x]=true;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(flag[y])
		{
			if(dis[y]==dis[x]^Len[i]) f=true;
		}
		else
		{
			dis[y]=dis[x]^Len[i]^1;
			dfs(y);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c),add(b,a,c);
	}
	int scc=0;
	for(int i=1;i<=n;i++)
		if(!flag[i])
		{
			dfs(i);
			scc++;
		}
	if(f) printf("0");
	else printf("%d",ksm(2,scc-1));
	return 0;
}