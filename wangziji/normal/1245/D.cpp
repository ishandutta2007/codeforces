#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int x[100005],y[100005],cnt,k[100005],c[100005],fa[100005],d[100005],E,f[100005];
struct edge
{
	int u,v,w,t;
}e[4000005];
inline bool cmp(edge X,edge Y)
{
	return X.w<Y.w;
}
inline int ff(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=ff(fa[x]);
}
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		cin >> x[i] >> y[i];
	for(int i=1;i<=n;i++)
		cin >> c[i];
	for(int i=1;i<=n;i++)
		cin >> k[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			e[++cnt]={i,j,(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j])};
		}
		e[++cnt]={i,2333,c[i]};
	}
	sort(e+1,e+cnt+1,cmp);
	int ans=0,b=0;
	for(int i=1;i<=cnt;i++)
	{
		if(ff(e[i].u)!=ff(e[i].v))
		{
			if(ff(e[i].u)==2333)
				swap(e[i].u,e[i].v);
			fa[ff(e[i].u)]=ff(e[i].v);
			e[i].t=1;
			if(e[i].v==2333)
				d[++b]=e[i].u;
			else
				f[++E]=i;
			ans+=e[i].w;
		}
	}
	cout << ans << endl << b << endl;
	for(int i=1;i<=b;i++)
		cout << d[i] << " ";
	cout << endl << E << endl;
	for(int i=1;i<=E;i++)
		cout << e[f[i]].u << " "<< e[f[i]].v<< endl;
	return 0;
}