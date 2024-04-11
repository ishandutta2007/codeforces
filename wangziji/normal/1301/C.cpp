#include <iostream>
#include <map>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		int t=(n-m)/(m+1);
		int ans=n*(n+1)/2;
		ans-=(n-m)%(m+1)*(t+1)*(t+2)/2; 
		ans-=(m+1-(n-m)%(m+1))*t*(t+1)/2;
		cout << ans << "\n";
	}
	return 0;
}