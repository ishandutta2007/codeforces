#include <iostream>
using namespace std;
int a[10005];
int main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		a[t]^=1;
	}
	int ans=0;
	for(int i=1;i<=k;i++) ans+=a[i];
	cout << n-ans/2;
	return 0;
}