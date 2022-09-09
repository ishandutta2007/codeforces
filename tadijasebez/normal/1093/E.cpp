#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
vector<int> ids[N],sum[N];
void Add(int x, int y){ for(;x<N;x+=x&-x) ids[x].pb(y);}
void Build()
{
	for(int i=1;i<N;i++)
	{
		sort(ids[i].begin(),ids[i].end());
		ids[i].resize(unique(ids[i].begin(),ids[i].end())-ids[i].begin());
		sum[i].resize(ids[i].size()+1);
	}
}
int Find(int x, int y){ return upper_bound(ids[x].begin(),ids[x].end(),y)-ids[x].begin();}
void Set(int x, int y, int f){ for(int i=x;i<N;i+=i&-i) for(int j=Find(i,y);j<sum[i].size();j+=j&-j) sum[i][j]+=f;}
int Get(int x, int y){ int ans=0;for(int i=x;i;i-=i&-i) for(int j=Find(i,y);j;j-=j&-j) ans+=sum[i][j];return ans;}
int Get(int xl, int xr, int yl, int yr){ return Get(xr,yr)-Get(xl-1,yr)-Get(xr,yl-1)+Get(xl-1,yl-1);}
int a[N],b[N],c[N],d[N],e[N],f[N],t[N],xl[N],xr[N],yl[N],yr[N],x[N],y[N];
int main()
{
	int n,q,i;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&c[i]),e[i]=c[i],a[c[i]]=i;
	for(i=1;i<=n;i++) scanf("%i",&d[i]),f[i]=d[i],b[d[i]]=i;
	for(i=1;i<=n;i++) Add(a[i],b[i]);
      for(i=1;i<=q;i++)
	{
		scanf("%i",&t[i]);
		if(t[i]==1) scanf("%i %i %i %i",&xl[i],&xr[i],&yl[i],&yr[i]);
		else
		{
			scanf("%i %i",&x[i],&y[i]);
			swap(b[d[x[i]]],b[d[y[i]]]);
			swap(d[x[i]],d[y[i]]);
			Add(a[d[x[i]]],b[d[x[i]]]);
			Add(a[d[y[i]]],b[d[y[i]]]);
		}
	}
	Build();
	for(i=1;i<=n;i++) c[i]=e[i],a[c[i]]=i;
	for(i=1;i<=n;i++) d[i]=f[i],b[d[i]]=i;
	for(i=1;i<=n;i++) Set(a[i],b[i],1);
	for(i=1;i<=q;i++)
	{
		if(t[i]==1) printf("%i\n",Get(xl[i],xr[i],yl[i],yr[i]));
		else
		{
			Set(a[d[x[i]]],b[d[x[i]]],-1);
			Set(a[d[y[i]]],b[d[y[i]]],-1);
			swap(b[d[x[i]]],b[d[y[i]]]);
			swap(d[x[i]],d[y[i]]);
			Set(a[d[x[i]]],b[d[x[i]]],1);
			Set(a[d[y[i]]],b[d[y[i]]],1);
		}
	}
	return 0;
}