#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		n=n/m;
		m%=10;
		int qwq=0;
		for(int i=1;i<=10;i++) qwq+=m*i%10;
		int ans=n/10*qwq;
		for(int i=1;i<=n%10;i++) ans+=m*i%10;
		cout << ans << "\n";
	}
	return 0;
}