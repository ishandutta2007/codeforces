#include <iostream>
#include <map>
using namespace std;
map <int,long long> mp;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,x=1;
		cin >> n;
		mp.clear();
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			ans+=(long long)(n-i+1)*mp[x];
			mp[x]+=i;
		}
		cout << ans << "\n";
	}
	return 0;
}