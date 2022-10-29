#include <iostream>
#include <algorithm>
using namespace std;
int a[1000],b[10005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++) cin >> b[i];
		sort(a+1,a+n+1),sort(b+1,b+n+1);
		for(int i=1;i<=n;i++) cout << a[i] << " ";
		cout << "\n";
		for(int i=1;i<=n;i++) cout << b[i] << " ";
		cout << "\n";
	}
	return 0;
}