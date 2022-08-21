#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[2333333],d[2333333],pm[2333333],
cnt[2333333],c[2333333],no[2333333],mat[2333333],mat2[2333333];
ll fac[2333333];
vector<int> ys[2333333];
const int MOD=1e9+7;
#define GG {puts("0"); return;}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) c[i]=(i==1)?1:(n/i);
	for(int i=0;i<=n;i++) no[i]=cnt[i]=mat[i]=mat2[i]=0;
	for(int i=1;i<=n;i++)
	{
		int s=1;
		vector<int>&x=ys[i];
		for(int j=0;j<x.size();++j) s=s*x[j];
		++cnt[d[i]=s];
		if(d[i]>n) throw "???";
	}
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
	{
		if(!a[i]) continue;
		int s=d[a[i]]; --cnt[s];
		vector<int>&x=ys[a[i]],&y=ys[i];
		if(x.size()!=y.size()) GG
		for(int j=0;j<x.size();++j)
		{
			if(c[x[j]]!=c[y[j]]) GG
			if(mat[x[j]]&&mat[x[j]]!=y[j]) GG
			mat[x[j]]=y[j];
			if(mat2[y[j]]&&mat2[y[j]]!=x[j]) GG
			mat2[y[j]]=x[j];
		}
	}
	for(int i=1;i<=n;i++)
		if(pm[i]&&!mat[i])
			++no[c[i]];
	ll ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*fac[no[i]]%MOD*fac[cnt[i]]%MOD;
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}
int main()
{
	#define MAXN 1000000
	fac[0]=1;
	for(int i=1;i<=MAXN;++i)
		fac[i]=fac[i-1]*i%MOD;
	for(int i=2;i<=MAXN;i++)
		ys[i].reserve(10);
	ys[1].push_back(1); pm[1]=1;
	for(int i=2;i<=MAXN;i++)
	{
		if(ys[i].size()) continue;
		pm[i]=1;
		for(int j=i;j<=MAXN;j+=i)
			ys[j].push_back(i);
	}
	//scanf("%d",&T);
	//while(T--)
	sol();
}