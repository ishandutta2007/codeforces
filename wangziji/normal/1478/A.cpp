#include <iostream>
#include <map>
using namespace std;
map <int,int> mp;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		mp.clear();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			ans=max(ans,++mp[x]);
		}
		cout << ans << "\n";
	}
	return 0;
}