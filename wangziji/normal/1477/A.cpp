#include <iostream>
#include <cstdio>
#include <map>
#define int long long
using namespace std;
int a[500005];
inline int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y;
}
map <int,int> mp;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		long long k,g=0,MX=1;
		cin >> n >> k;
		long long lst=0;
		cin >> lst;
		for(int i=2;i<=n;i++)
		{
			long long x;
			scanf("%lld",&x);
			g=gcd(g,max(x-lst,lst-x)),lst=x;
		}
		if((lst-k)%g) puts("NO");
		else puts("YES");
	}
	return 0;
}