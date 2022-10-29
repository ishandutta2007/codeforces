#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int c,d;
		cin >> c >> d;
		if(c+d&1) cout << -1 << "\n";
		else if(c==d&&c==0) cout << 0 << "\n";
		else if(c==d) cout << 1 << "\n";
		else if(c+d==0) cout << 1 << "\n";
		else cout << 2 << "\n";
	}
	return 0;
}