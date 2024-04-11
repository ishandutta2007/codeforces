#include <iostream>
#define int long long
using namespace std;
int a[100005];
signed main(int argc, char** argv) {
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
		cin >> a[i];
	int l=1,r=k,now=1,ans=0,t=1;
	while(now<=m)
	{
		++ans;
		l=(a[now]-t)/k*k+t;
		r=l+k-1;
		while(now<=m&&l<=a[now]&&r>=a[now])
			++t,++now;
	}
	cout << ans;
	return 0;
}