#include <iostream>
#define int long long
using namespace std;
int a[200005];
signed main(int argc, char** argv) {
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(i==1)
		{
			cout << a[i] << " ";
			mx=max(mx,a[i]);
		}
		else
		{
			cout << mx+a[i] << " ";
			mx=max(mx,mx+a[i]);
		}
	}
	return 0;
}