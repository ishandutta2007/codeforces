#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;

const int MAXN = 1e5;

long long k2, k3, k5, k6;

long long ans = 0;

int main() {
	//freopen("input.in", "r", stdin);
	cin >> k2 >> k3 >> k5 >> k6;
	ans += min({k2, k5, k6}) * 256;
	ans += max(0LL, min(k3, k2 - min({k2, k5, k6}))) * 32;
	cout << ans << endl;
}