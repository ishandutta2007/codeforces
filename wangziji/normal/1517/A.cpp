#include <bits/stdc++.h>
using namespace std;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		long long n;
		cin >> n;
		long long qwq=n/2050;
		int ans=0;
		while(qwq) ans+=qwq%10,qwq/=10;
		if(n%2050) puts("-1");
		else cout << ans << "\n";
	}
	return 0;
}