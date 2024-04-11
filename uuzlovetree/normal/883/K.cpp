#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
typedef long long ll;
int n;
int s[maxn],g[maxn],L[maxn],R[maxn];
int Ans[maxn];
ll tot;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&s[i],&g[i]);
	L[1]=s[1],R[1]=s[1]+g[1];
	for(int i=2;i<=n;++i)
	{
		int l=s[i],r=s[i]+g[i];
		L[i]=max(L[i-1]-1,l);
		R[i]=min(R[i-1]+1,r);
		if(L[i]>R[i])
		{
			puts("-1");
			return 0;
		}
	}
	Ans[n]=R[n];
	for(int i=n-1;i>=1;--i)
	{
		R[i]=min(R[i+1]+1,R[i]);
		Ans[i]=R[i];
	}
	for(int i=1;i<=n;++i)tot+=1ll*(Ans[i]-s[i]);
	printf("%lld\n",tot);
	for(int i=1;i<=n;++i)printf("%d ",Ans[i]);
}