#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,v[N],a[N],f[N],d[N],s,pr,ans;
vector<int>p[N],vl;
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++)
	{
		p[i].clear();
		v[i]=n+1;
		f[i]=d[i]=0;
	}
	s=n,pr=0,ans=n;
	vl.clear();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		vl.push_back(a[i]);
	}
	sort(vl.begin(),vl.end());
	vl.erase(unique(vl.begin(),vl.end()),vl.end());
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(vl.begin(),vl.end(),a[i])-vl.begin()+1;
		d[i]=p[a[i]].size();
		p[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		v[r]=min(v[r],l);
	}
	for(int i=n-1;i;i--)
		v[i]=min(v[i],v[i+1]);
	for(int i=1;i<=n;i++)
	{
		if(v[i]>=i)
			continue;
		int x=lower_bound(p[a[i]].begin(),p[a[i]].end(),v[i])-p[a[i]].begin();
		if(d[i]&&p[a[i]][d[i]-1]>=v[i]) 
			pr=max(pr,p[a[i]][d[i]-1]);
		if(x+1<p[a[i]].size())
			s=min(s,p[a[i]][x+1]);
		f[p[a[i]][x]+1]=max(f[p[a[i]][x]+1],i);	
	}
	for(int i=1;i<=s;i++)
	{
		pr=max(pr,f[i]);
		ans=min(ans,max(0,pr-i+1));
	}
	printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}