#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=500050;
int a[N],pre[N];
vector<int> pos[N];
int main()
{
	int n,c,i,j;
	scanf("%i %i",&n,&c);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),pre[i]=pre[i-1]+(a[i]==c),pos[a[i]].pb(i);
	int ans=pre[n];
	for(j=1;j<N;j++)
	{
		if(j==c) continue;
		vector<int> sum;
		for(i=0;i<pos[j].size();i++)
		{
			int k=pos[j][i];
			sum.pb(pre[n]-pre[k-1]+i);
			sum.pb(pre[n]-pre[k]+i+1);
		}
		int mn=1e9+7,mx=0;
		for(i=0;i<sum.size();i++)
		{
			mx=max(mx,sum[i]-mn);
			mn=min(mn,sum[i]);
		}
		ans=max(ans,mx+pre[n]);
	}
	printf("%i\n",ans);
	return 0;
}