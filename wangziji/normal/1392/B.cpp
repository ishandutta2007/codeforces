#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int a[200005],b[200005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		int mx=-1e10;
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
		for(int i=1;i<=n;i++)
			a[i]=mx-a[i];
		mx=-1e10;
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
		for(int i=1;i<=n;i++)
			b[i]=mx-a[i];
		if(k%2==1)
		{
			for(int i=1;i<=n;i++)
				cout << a[i] << " ";
			puts("");
		}
		else
		{
			for(int i=1;i<=n;i++)
				cout << b[i] << " ";
			puts("");
		}
	}
	return 0;
}