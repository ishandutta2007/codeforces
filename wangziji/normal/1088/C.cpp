#include <iostream>
using namespace std;
int a[100005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{ 
		cin >> a[i];
		a[i]%=n;
	}
	int now=n;
	cout << n+1 << "\n";
	for(int i=n;i>=1;i--)
	{
		--now;
		int X=now+n-a[i];
		cout << "1 " << i << " " << X << "\n";
		for(int j=1;j<=i;j++) a[j]=(a[j]+X)%n;
	}
	cout << "2 " << n << " " << n;
	return 0;
}