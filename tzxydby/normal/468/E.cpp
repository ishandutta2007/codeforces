#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=55,mod=1e9+7;
int n,m,k,u[N],v[N],w[N],fc[N],ans;
long long s[N];
vector<pair<int,int>>e[N];
vector<int>vu,vv;
map<long long,int>dp[M][M];
inline void ad(int &a,int b){a+=b;if(a>=mod)a-=mod;}
int main()
{
	scanf("%d%d",&n,&k);
	fc[0]=1;
	for(int i=1;i<=n;i++)
		fc[i]=1ll*fc[i-1]*i%mod;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		w[i]--;
		vu.push_back(u[i]);
		vv.push_back(v[i]);
	}
	sort(vu.begin(),vu.end());
	vu.erase(unique(vu.begin(),vu.end()),vu.end());
	sort(vv.begin(),vv.end());
	vv.erase(unique(vv.begin(),vv.end()),vv.end());
	m=vu.size();
	for(int i=1;i<=k;i++)
	{
		u[i]=lower_bound(vu.begin(),vu.end(),u[i])-vu.begin();
		v[i]=lower_bound(vv.begin(),vv.end(),v[i])-vv.begin();
		e[u[i]].emplace_back(v[i],w[i]);
	}
	for(int i=m-1;i>=0;i--)
	{
		s[i]=s[i+1];
		for(auto v:e[i])
			s[i]|=(1LL<<v.first);
	}
	dp[0][0][0]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<=i;j++)
			for(auto v:dp[i][j])
			{
				ad(dp[i+1][j][v.first&s[i+1]],v.second);
				for(auto z:e[i])
					if(!(v.first&(1LL<<z.first)))
						ad(dp[i+1][j+1][(v.first|(1LL<<z.first))&s[i+1]],1ll*v.second*z.second%mod);
			}
	for(int i=0;i<=m;i++)
		for(auto v:dp[m][i])
			ans=(ans+1ll*v.second*fc[n-i]%mod)%mod;
	printf("%d\n",ans);
	return 0;
}