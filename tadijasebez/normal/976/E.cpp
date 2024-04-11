#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
bool ckmax(int &a, int b){ int c=a;a=max(a,b);return c!=a;}
bool ckmin(int &a, int b){ int c=a;a=min(a,b);return c!=a;}
bool ckmax(ll &a, ll b){ ll c=a;a=max(a,b);return c!=a;}
bool ckmin(ll &a, ll b){ ll c=a;a=min(a,b);return c!=a;}
const int N=200050;
ll d[N],h[N];int id[N];
bool comp(int a, int b){ return h[a]-d[a]>h[b]-d[b];}
int main()
{
	int n,a,b,i;
	scanf("%i %i %i",&n,&a,&b);
	for(i=1;i<=n;i++) scanf("%lld %lld",&h[i],&d[i]),id[i]=i;
	if(b==0)
	{
		ll sol=0;
		for(i=1;i<=n;i++) sol+=d[i];
		printf("%lld\n",sol);
		return 0;
	}
	sort(id+1,id+1+n,comp);
	ll sol=0;b=min(b,n);bool br=0;
	for(i=1;i<=b;i++)
	{
		if(h[id[i]]<d[id[i]]){ b=i-1;br=1;break;}
		sol+=h[id[i]];
	}
	for(i=b+1;i<=n;i++) sol+=d[id[i]];
	ll tmp=sol;//printf("tmp:%lld\n",tmp);
	for(i=1;i<=b;i++)
	{
		ll ans=(h[id[i]]<<a)-h[id[i]];
		ckmax(sol,tmp+ans);
	}
	if(!br) tmp-=h[id[b]]-d[id[b]];//printf("tmp:%lld\n",tmp);
	for(i=b+1;i<=n;i++)
	{
		ll ans=(h[id[i]]<<a)-d[id[i]];
		ckmax(sol,tmp+ans);
	}
	printf("%lld\n",sol);
	return 0;
}