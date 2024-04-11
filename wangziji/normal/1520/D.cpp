#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
map <int,int> mp;
signed main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		long long ans=0;
		mp.clear();
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			ans+=mp[x-i]++;
		}
		cout << ans << "\n";
	}
	return 0;
}