#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int a[500005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,q;
		cin >> n >> q;
		int ans=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<n;i++)
			ans+=max(a[i]-a[i+1],(int)0);
		printf("%lld\n",ans+a[n]);
		while(q--)
		{
			int x,y;
			cin >> x >> y;
			if(x==y)
			{
		printf("%lld\n",ans+a[n]);
				continue;
			}
			if(x-1) ans-=max(a[x-1]-a[x],(int)0);
			if(x<n) ans-=max(a[x]-a[x+1],(int)0);
			if(y-1&&y-1!=x) ans-=max(a[y-1]-a[y],(int)0);
			if(y<n) ans-=max(a[y]-a[y+1],(int)0);
			swap(a[x],a[y]);
			if(x-1) ans+=max(a[x-1]-a[x],(int)0);
			if(x<n) ans+=max(a[x]-a[x+1],(int)0);
			if(y-1&&y-1!=x) ans+=max(a[y-1]-a[y],(int)0);
			if(y<n) ans+=max(a[y]-a[y+1],(int)0);
		printf("%lld\n",ans+a[n]);
		}
	}
	return 0;
}