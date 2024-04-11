#include<bits/stdc++.h>
using namespace std;
const int N=500005,mod=1e9+7;
int n,m,a[N],u[N],v[N],f[N],sz[N],fl[N],s=1;
vector<int>ans;
int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		f[i]=i,sz[i]=1;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d",&u[i]);
			if(!a[u[i]])
				a[u[i]]=i;
			int fu=fa(u[i]);
			if(!fl[fu])
			{
				fl[fu]=1;
				ans.push_back(i);
			}
		}
		else
		{
			scanf("%d%d",&u[i],&v[i]);
			int fu=fa(u[i]),fv=fa(v[i]);
			if(fu==fv)
				continue;
			if(fl[fu]&&fl[fv])
				continue;
			ans.push_back(i);
			f[fu]=fv;
			sz[fv]+=sz[fu];
			fl[fv]=fl[fv]|fl[fu];
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i!=f[i])
			continue;
		if(fl[i])
			s=1ll*s*qp(2,sz[i])%mod;
		else
			s=1ll*s*qp(2,sz[i]-1)%mod;
	}
	cout<<s<<' '<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(auto i:ans)
		cout<<i<<' ';
	return 0;
}