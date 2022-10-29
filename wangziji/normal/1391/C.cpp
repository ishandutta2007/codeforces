#include <iostream>
#define mod 1000000007
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	int ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*i%mod;
	int x=1;
	for(int i=1;i<n;i++)
		x=x*2%mod;
	cout << (ans-x+mod)%mod;
	return 0;
}