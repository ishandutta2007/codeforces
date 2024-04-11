#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int n,k;
int p[maxn];
vector<int> A;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	ll ans1=0,ans2=1;
	for(int i=1;i<=n;++i)if(p[i]>=n-k+1)A.push_back(i),ans1+=p[i];
	if(k>=2)
	{
		for(int i=0;i<k-1;++i)ans2=1ll*ans2*(A[i+1]-A[i])%998244353;
	}
	printf("%I64d %I64d\n",ans1,ans2);
}