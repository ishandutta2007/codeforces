#include <bits/stdc++.h>
using namespace std;
 
int n, a, b, x[100], y[100], ans;
 
bool chk2(int x1, int y1, int x2, int y2) {
	return x1<=a&&x2<=a&&y1+y2<=b||y1<=b&&y2<=b&&x1+x2<=a;
}
 
bool chk(int i, int j) {
	return chk2(x[i], y[i], x[j], y[j])||chk2(x[i], y[i], y[j], x[j])||chk2(y[i], x[i], x[j], y[j])||chk2(y[i], x[i], y[j], x[j]);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> a >> b;
	for(int i=0; i<n; ++i)
		cin >> x[i] >> y[i];
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
			if(chk(i, j))
				ans=max(x[i]*y[i]+x[j]*y[j], ans);
	cout << ans;
}