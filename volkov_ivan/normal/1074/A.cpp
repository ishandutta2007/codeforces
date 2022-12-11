#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = 1e9, MAX_N = 1e5 + 7;
long long vert[MAX_N], gor[MAX_N];

int main() {
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, m = 0, mm, ans = 0;
	long long x1, x2, y;
	cin >> n >> mm;
	ans = n;
	for (int i = 0; i < n; i++) cin >> vert[i];
	for (int i = 0; i < mm; i++) {
		cin >> x1 >> x2 >> y;
		if (x1 == 1) {
			gor[m] = x2;
			m++;
			if (x2 == INF) ans++; 
		}
	}
	sort(vert, vert + n);
	sort(gor, gor + m);
	int l = -1;
	for (int i = 0; i < n; i++) {
		while (l + 1 < m && gor[l + 1] < vert[i]) l++;
		ans = min(ans, i + m - l - 1);
	}
	cout << ans << endl;
	return 0;
}