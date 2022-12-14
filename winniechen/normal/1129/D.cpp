#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define B 355
#define ll long long
#define mod 998244353
int size,block,pos[N],L[B],R[B],n,K;
int f[B][N],s[N],tag[B],mx[B],v[N],p[N],las[N],g[N];
void build(int x)
{
	int maxx=-1<<30,mn=1<<30;
	for(int i=L[x];i<=R[x];i++)maxx=max(maxx,s[i]),mn=min(mn,s[i]);
		// printf("%d %d\n",maxx,mn);
	mx[x]=maxx-mn;tag[x]+=mn;memset(f[x],0,sizeof(int)*(mx[x]+1));
	for(int i=L[x];i<=R[x];i++)s[i]-=mn,(f[x][s[i]]+=g[i])%=mod;
	for(int i=1;i<=mx[x];i++)(f[x][i]+=f[x][i-1])%=mod;
}
void change(int l,int r,int val)
{
	int c=val-v[l],p=pos[l],q=pos[r];v[l]=val;
	if(p==q){for(int i=l;i<=r;i++)s[i]+=c;return ;}
	for(int i=l;i<=R[p];i++)s[i]+=c;build(p);
	for(int i=p+1;i<q;i++)tag[i]+=c;
	for(int i=L[q];i<=r;i++)s[i]+=c;
}
int query(int x,int val)
{
	val-=tag[x];
	if(val>mx[x])return 0;if(val<=0)return f[x][mx[x]];
	return (f[x][mx[x]]-f[x][val-1])%mod;
}
int main()
{
	scanf("%d%d",&n,&K);size=sqrt(n);block=n/size+1;
	for(int i=1;i<=block;i++)
	{
		L[i]=R[i-1]+1,R[i]=min(n,i*size);
		for(int j=L[i];j<=R[i];j++)pos[j]=i;
	}
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);s[i]=s[i-1]+tag[pos[i-1]];
		if(p[x])change(p[x],i,-1);if(las[x])change(las[x],i,0);
		las[x]=p[x];p[x]=i;v[i]=1;s[i]++;
		for(int j=1;j<pos[i];j++)(g[i]+=query(j,s[i]+tag[pos[i]]-K))%=mod;
		for(int j=L[pos[i]];j<i;j++)if(s[j]>=s[i]-K)(g[i]+=g[j])%=mod;if(s[i]<=K)g[i]++;
		if(i==R[pos[i]])build(pos[i]);
	}
	printf("%d\n",(g[n]+mod)%mod);
}
// 