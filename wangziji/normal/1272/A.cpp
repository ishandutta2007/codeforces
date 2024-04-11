#include <iostream>
#include <cmath>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int ans=1e10;
		int a,b,c;
		cin >> a >> b >> c;
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++)
				for(int k=-1;k<=1;k++)
					ans=min(ans,abs(a+i-(b+j))+abs((b+j)-(c+k))+abs((c+k)-(a+i)));
		cout << ans << endl;
	}
	return 0;
}