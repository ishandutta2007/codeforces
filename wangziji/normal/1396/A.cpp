#include <iostream>
#define int long long
using namespace std;
int a[100005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	cout << 1 << " " << 1 << "\n" << -a[1] << "\n";
	a[1]=0;
	if(n==1)
	{
		cout << 1 << " " << 1 << "\n" << -a[1] << "\n";
		cout << 1 << " " << 1 << "\n" << -a[1] << "\n";
		return 0;
	}
	cout << 2 << " " << n << "\n";
	for(int i=2;i<=n;i++)
	{
		cout << a[i]%n*(n-1) << " ";
		a[i]+=a[i]%n*(n-1);
	}
	cout << "\n";
	cout << 1 << " " << n << "\n";
	for(int i=1;i<=n;i++)
		cout << -a[i] << " ";
	return 0;
}