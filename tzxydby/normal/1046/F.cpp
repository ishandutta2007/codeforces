#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int f, x;
	scanf("%d%d", &f, &x);
	long long ans = 0;
	for (int i = 0; i < n; i++){
		int l = 0, r = 1000000000, t;
		while (l < r){
			int mid = (l + r) >> 1;
			if (a[i] - 1ll * mid * (f + x) > f) l = mid + 1;
			else r = mid;
		}
		ans += 1ll * r * x;
	}
	cout << ans << endl;
	return 0;
}