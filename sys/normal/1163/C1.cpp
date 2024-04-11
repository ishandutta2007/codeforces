#include <bits/stdc++.h>
using namespace std;
const int Maxn=1005;
int ct[Maxn*Maxn],tot,n,x[Maxn],y[Maxn],cnt;
long long ans;
const double eps=1e-9;
struct line
{
	double k,b;
	bool operator < (const line &tmp) const
	{
		if(k!=tmp.k) return k<tmp.k;
		return b<tmp.b;
	}
}L[Maxn*Maxn];
map <int,int> Ma;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(x[i]==x[j])
			{
				L[++cnt].k=0x3f3f3f3f;
				L[cnt].b=x[i];
			}
			else
			{
				L[++cnt].k=(y[i]-y[j])/(double)(x[i]-x[j]);
				L[cnt].b=y[i]-x[i]*L[cnt].k;
			}
		}
	L[0].k=-0x3f3f3f3f; 
	sort(L+1,L+1+cnt);
	for(int i=1;i<=cnt;i++)
	{
		if(fabs(L[i].k-L[i-1].k)<=eps)
		{
			if(fabs(L[i].b-L[i-1].b)<=eps) continue;
			else ct[tot]++;
		}
		else tot++,ct[tot]++;
	}
	for(int i=1;i<=tot;i++)
		Ma[ct[i]]++;
	for(map<int,int>::iterator it=Ma.begin();it!=Ma.end();it++)
	{
		ans+=(long long)it->first*it->first*it->second*(it->second-1)/2;
		for(map <int,int>::iterator it2=Ma.begin();it2!=Ma.end();it2++)
		{
			if(it2->first<=it->first) continue;
			ans+=(long long)it->first*it2->first*it2->second*it->second;
		}
	}
	printf("%lld",ans);
	return 0;
}