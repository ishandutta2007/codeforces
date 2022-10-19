#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define tll long long
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
const int N=1e5+10;
int L,R,a[N],nex[N],las[N];
tll ans;
tll cal(int l,int r)
{
	while(L<l)
	{
		if(nex[L]<=R)ans-=nex[L]-L;
		L++;
	}
	while(L>l)
	{
		L--;
		if(nex[L]<=R)ans+=nex[L]-L;
	}
	while(R<r)
	{
		R++;
		if(las[R]>=L)ans+=R-las[R];
	}
	while(R>r)
	{
		if(las[R]>=L)ans-=R-las[R];
		R--;
	}
	return ans;
}
tll dp[105][N]; int cur;
void solve(int lb,int rb,int l,int r)
{
	if(lb>rb||l>r) return; int mid=l+r>>1;
	int d=0; tll res=1e18;
	for(int i=lb;i<=rb;++i)
	{
		tll tmp=cal(i+1,mid);
		if(res>dp[cur-1][i]+tmp) res=dp[cur-1][i]+tmp,d=i;
	}
	dp[cur][mid]=res;
	solve(lb,d,l,mid-1),solve(d,rb,mid+1,r);
}
int to[N];
int main()
{
	memset(dp,0x3f,sizeof(dp)); dp[0][0]=0;
	int n,m;n=read();
	m=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		las[i]=to[a[i]];
		to[a[i]]=i;
	}
	for(int i=1;i<=n;i++)to[a[i]]=n+1;
	for(int i=n;i>=1;i--)
	{
		nex[i]=to[a[i]];
		to[a[i]]=i;
	}
	L=1;
	R=0;
	for(cur=1;cur<=m;++cur) solve(0,n-1,1,n);
	printf("%lld",dp[m][n]);
	return 0;
}