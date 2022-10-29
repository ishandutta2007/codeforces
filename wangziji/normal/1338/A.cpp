#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int a[100005],mx[100005],d[100005];
inline int qwq(int x)
{
	if(!x) return 0;
	for(int i=1;i<=30;i++)
		if((1<<i)>x) return i;
	return 31;
}
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		mx[1]=a[1];
		for(int i=2;i<=n;i++)
			mx[i]=max(mx[i-1],a[i]);
		int ans=0;
		for(int i=1;i<=n;i++)
			d[i]=mx[i]-a[i],ans=max(ans,qwq(d[i]));
		printf("%lld\n",ans);
	}
	return 0;
}