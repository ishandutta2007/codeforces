#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;

	int fir = 0, sec = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a > fir) {
			sec = fir;
			fir = a;
		} else if (a > sec) {
			sec = a;
		}
	}

	cout << m / (k + 1) * (fir * k + sec) + m % (k + 1) * fir << '\n';
}