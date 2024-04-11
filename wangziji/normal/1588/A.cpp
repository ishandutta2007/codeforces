#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],b[10005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cin >> b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		int flag=1;
		for(int i=1;i<=n;i++)
			if(b[i]!=a[i]&&b[i]!=a[i]+1) flag=0;
		if(!flag) cout << "NO\n";
		else cout << "YES\n"; 
	}
	return 0;
}