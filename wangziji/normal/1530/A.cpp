#include <bits/stdc++.h>
using namespace std;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		char ans='0';
		for(auto t:s) ans=max(ans,t);
		cout << ans << "\n";
	}
	return 0;
}