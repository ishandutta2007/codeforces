#include <iostream>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	for(int i=0;i<=n;i++)
	{
		if((i+1)*i/2-n+i==k)
		{
			cout << n-i;
			return 0;
		}
	}
	return 0;
}