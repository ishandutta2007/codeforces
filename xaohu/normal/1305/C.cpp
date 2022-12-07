#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int n, m, a[1000];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	if (n > m) {
		cout << "0\n";
		return 0;
	}

	int res = 1;
	rep(i, 0, n) {
		cin >> a[i];
		rep(j, 0, i)
			res = 1ll * res * abs(a[i] - a[j]) % m;
	}
	cout << res << endl;
	
	return 0;
}