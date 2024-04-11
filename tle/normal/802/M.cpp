# include <stdio.h>
# include <string.h>
# include <iostream>
# include <algorithm>
// # include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int M = 5e5 + 10;
const int mod = 1e9+7;

# define RG register
# define ST static

int n, k, a[M];

int main() {
	cin >> n >> k;
	for (int i=1; i<=n; ++i) scanf("%d", a+i);
	sort(a+1, a+n+1);
	ll ans = 0;
	for (int i=1; i<=k; ++i) ans += a[i];
	cout << ans;
	return 0;
}