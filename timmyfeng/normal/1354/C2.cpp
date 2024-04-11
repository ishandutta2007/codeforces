#include <bits/stdc++.h> 
using namespace std;

const double PI = 3.1415926535897932384;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(12);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		double r = 0.5 / sin(PI / (2 * n));
		double ang = PI / n;
		double s1 = r * r + r * r - 2 * r * r * cos(ang * ((n + 1) / 2));
		double s2 = r * r + r * r - 2 * r * r * cos(ang * (n / 2));
		cout << (sqrt(s1) + sqrt(s2)) / sqrt(2) << '\n';
	}
}