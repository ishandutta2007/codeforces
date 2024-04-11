#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int n, b, mx;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	while (n--) {
		cin >> b;
		int a = b + mx;
		cout << a << " ";
		mx = max(mx, a);
	}
	return 0;
}