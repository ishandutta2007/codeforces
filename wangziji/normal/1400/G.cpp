#include <iostream>
#define int long long
#include <cstdio>
#define mod 998244353
using namespace std;
int inv[300005],jc[300005],jcinv[300005];
int l[300005],r[300005],cf[300005],qqzh[300005][50],vis[300005];
int u[30],v[30];
inline int C(int x,int y)
{
	if(x<y||y<0) return 0;
	return jc[x]*jcinv[y]%mod*jcinv[x-y]%mod;
}
signed main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&l[i],&r[i]);
		++cf[l[i]],--cf[r[i]+1];
	}
	for(int i=1;i<=m;i++)
		cin >> u[i] >> v[i];
	for(int i=1;i<=n;i++)
		cf[i]+=cf[i-1];
	inv[1]=jc[0]=jc[1]=jcinv[0]=jcinv[1]=1;
	for(int i=2;i<=300000;i++)
	{
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		jc[i]=jc[i-1]*i%mod;
		jcinv[i]=jcinv[i-1]*inv[i]%mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=40;j++)
			qqzh[i][j]=(qqzh[i-1][j]+C(cf[i]-j,i-j))%mod;
	}
	int ans=0;
	for(int i=0;i<(1<<m);i++)
	{
		int L=1,R=n;
		int cnt=0,Cnt=0;
		for(int j=1;j<=m;j++)
		{
			if((1<<j-1)&i)
			{
				++Cnt;
				L=max(L,l[u[j]]);
				R=min(R,r[u[j]]);
				L=max(L,l[v[j]]);
				R=min(R,r[v[j]]);
				if(!vis[u[j]]) ++cnt;
				if(!vis[v[j]]) ++cnt;
				vis[u[j]]=vis[v[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
			vis[u[j]]=vis[v[j]]=0;
		if(R>=L)
		{
			//cout << cnt << "\n";
			if(Cnt&1) ans-=qqzh[R][cnt]-qqzh[L-1][cnt];
			else ans+=qqzh[R][cnt]-qqzh[L-1][cnt];
		}
	}
	cout << (ans%mod+mod)%mod;
	return 0;
}