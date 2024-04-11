#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[100005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	int x=0,y=0;
	for(int i=n;i>=n/2+1;i--)
		x+=a[i];
	for(int i=n/2;i>=1;i--)
		y+=a[i];
	cout << x*x+y*y;
	return 0;
}