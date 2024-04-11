#include <iostream>
using namespace std;
int a[1000005],ans[100005],cnt;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin >> c;
		if(c=='B')
			a[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		if(a[i])
		{
			ans[++cnt]=i;
			a[i]^=1,a[i+1]^=1;
		}
	}
	if(!a[n])
	{
		cout << cnt << endl;
		for(int i=1;i<=cnt;i++) cout << ans[i] << " ";
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		if(!a[i])
		{
			ans[++cnt]=i;
			a[i]^=1,a[i+1]^=1;
		}
	}
	if(a[n])
	{
		cout << cnt << endl;
		for(int i=1;i<=cnt;i++) cout << ans[i] << " ";
		return 0;
	}
	cout << -1;
	return 0;
}