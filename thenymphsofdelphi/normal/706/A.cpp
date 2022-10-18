#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y, xt, yt, v;
	long double mn = 1000000000.0, dis;
	cin >> x >> y >> n;
	for (int i = 0; i < n; i++){
		cin >> xt >> yt >> v;
		dis = sqrt(abs(x - xt) * abs(x - xt) * 1.0 + abs(y - yt) * abs(y - yt) * 1.0) / (v * 1.0);
		mn = min(mn, dis);
	}
	cout << fixed << setprecision(6) << mn;
}