#include <bits/stdc++.h>
using namespace std;
#define N 200005 
#define int long long
int a[N], v[N], b[N], id[N];
signed main () {
	int T;
	scanf("%d",&T);
	while (T--) {
		int n, ans = 0; cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i < n; i++) v[i] = b[i] = abs (a[i] - a[i+1]), id[i] = i; n--;
		for (int i = 1; i <= n; i++)
			for (int j = i; j; j = id[j]-1) {
				for (v[j] = __gcd (v[j], b[i]); id[j]-1 && v[j] == __gcd (b[i], v[id[j]-1]); id[j] = id[id[j]-1]);
				if (v[j]>1) ans = max (ans, i-id[j]+1);
			}
		printf("%d\n",ans+1);
	}
	return 0;
}