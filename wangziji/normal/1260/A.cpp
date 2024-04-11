#include <iostream>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int x,y;
		cin >> x >> y;
		int ans=0;
		ans+=(y/x)*(y/x)*(x-y%x);
		ans+=(y/x+1)*(y/x+1)*(y%x);
		cout << ans << endl;
	}
	return 0;
}