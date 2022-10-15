#include<bits/stdc++.h>
using namespace std;
int a[111];
int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	for(int i(1); i <= n; i++) {
		int y;
		scanf("%d", &y);
		a[y] = 1;
	}
	int ans(0);
	for(int i(0); i < x; i++) {
		if(a[i] == 0) ans++;
	}
	if(a[x] == 1) ans++;
	cout << ans << endl;
}