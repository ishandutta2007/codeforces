#include <iostream>
using namespace std;
long long a[2];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		a[i&1]+=t/2;
		a[(i&1)^1]+=t-t/2;
	}
	cout << min(a[1],a[0]); 
	return 0;
}