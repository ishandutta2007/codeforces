#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define maxn 200005
#define mp(a,b) make_pair(a,b)
using namespace std;
int n;
ll a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	ll ans=0;
	ll x=a[n]+1;
	for(int i=n;i;--i)
	{
		x=min(x,a[i]);
		ans=ans+x;
		x--;
		if(!x)break;
	}
	printf("%I64d\n",ans);
	return 0;
}