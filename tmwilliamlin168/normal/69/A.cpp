#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, sx=0, sy=0, sz=0;
	cin >> n;
	int x[n], y[n], z[n];
	for(int i=0; i<n; ++i)
		cin >> x[i] >> y[i] >> z[i], sx+=x[i], sy+=y[i], sz+=z[i];
	cout << (sx||sy||sz?"NO":"YES");
	return 0;
}