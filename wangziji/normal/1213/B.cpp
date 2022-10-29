#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int mn=1e9,ans=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]!=(mn=min(mn,a[i]))) ++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}