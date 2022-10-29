#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
long long a[1005][1005],ans[1005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	long long x,y;
	x=a[1][2]*a[1][3]/(a[2][3]);
	x=sqrt(x);
	ans[1]=x;
	for(int i=2;i<=n;i++)
		ans[i]=a[1][i]/ans[1];
	for(int i=1;i<=n;i++)
		cout << ans[i] << " ";
	return 0;
}