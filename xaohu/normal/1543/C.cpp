#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
#define double long double
typedef long long ll;	
using namespace std;
int T;
double x, y, z, v;

double solve(double c, double m, double p) {
	double res = 1;
	rep(i, 0, 2) {
		if (c > 0) {
			if (m < 0.00000001) {
				if (c <= v)
					res += c;
				else
					res += c * solve(c - v, 0, p + v);
			}
			else {
				if (c <= v)
					res += c * solve(0, m + c / 2, p + c / 2);
				else
					res += c * solve(c - v, m + v / 2, p + v / 2);
			}
		}
		swap(c, m);
	}
	return res;
}

int main() { 
	cin >> T;
	while (T--) {
		cin >> x >> y >> z >> v;
		cout << setprecision(20) << solve(x, y, z) << "\n";
	}
	return 0;
}