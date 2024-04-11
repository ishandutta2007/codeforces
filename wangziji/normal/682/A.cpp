#include <iostream>
#define int long long
using namespace std;
int cnt[10];
signed main(int argc, char** argv) {
	int ans=0,n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		++cnt[i%5];
	for(int i=1;i<=m;i++)
	{
		ans+=cnt[(5-i%5)%5]; 
	}
	cout << ans;
	return 0;
}