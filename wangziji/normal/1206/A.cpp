#include <iostream>
using namespace std;
int a[100005];
int main(int argc, char** argv) {
	int n,ans=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		ans=max(ans,a[i]);
	}
	cout << ans << endl;
	ans=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		ans=max(ans,a[i]);
	}
	cout << ans << endl;
	return 0;
}