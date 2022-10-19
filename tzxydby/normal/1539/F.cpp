#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,ans[N];
struct nd{int l,r,s;}f[N<<1];
vector<int>v[N];
nd operator+(nd x,nd y){return {max(x.l,x.s+y.l),max(y.r,y.s+x.r),x.s+y.s};}
void upd(int x,int y)
{
	f[N+x]={y,y,y};
	for(int i=(N+x)>>1;i;i>>=1)
		f[i]=f[i<<1]+f[i<<1|1];
}
nd ask(int x,int y)
{
	nd a={0,0,0},b={0,0,0};
	for(int l=N+x-1,r=N+y+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) a=a+f[l^1];
		if(r&1) b=f[r^1]+b;
	}
	return a+b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		upd(i,1);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		v[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		for(auto p:v[i])
			ans[p]=max(ans[p],(ask(1,p-1).r+ask(p+1,n).l+1)/2);
		for(auto p:v[i])
			upd(p,-1);
	}
	for(int i=1;i<=n;i++)
		upd(i,1);
	for(int i=n;i;i--)
	{
		for(auto p:v[i])
			ans[p]=max(ans[p],(ask(1,p-1).r+ask(p+1,n).l)/2);
		for(auto p:v[i])
			upd(p,-1);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}