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
		if(x-y-1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}