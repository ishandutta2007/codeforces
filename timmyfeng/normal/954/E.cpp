#include <bits/stdc++.h>
using namespace std;

using ld = long double;

const ld EPS = 1e-12;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(15);

	int n, tt;
	cin >> n >> tt;
	vector<pair<int, int>> pipes(n);
	for (auto& i : pipes) {
		cin >> i.second;
	}
	for (auto& i : pipes) {
		cin >> i.first;
	}
	sort(pipes.begin(), pipes.end());

	ld num = 0.0;
	ld den = 0.0;
	for (auto i : pipes) {
		num += (ld)i.first * i.second;
		den += i.second;
	}

	auto upd = [&](int i) {
		ld delta = min((ld)pipes[i].second, ((ld)tt * den - num) / (tt - pipes[i].first));
		num -= delta * pipes[i].first;
		den -= delta;
	};

	int l = 0, r = n - 1;
	while (l < r && den && num / den > tt + EPS) {
		if (pipes[r].first <= tt) {
			cout << 0.0 << '\n';
			return 0;
		}
		upd(r);
		--r;
	}

	while (l < r && den && num / den < tt - EPS) {
		if (pipes[l].first >= tt) {
			cout << 0.0 << '\n';
			return 0;
		}
		upd(l);
		++l;
	}

	if (den && abs(num / den - tt) >= EPS) {
		cout << 0.0 << '\n';
		return 0;
	}

	cout << den << '\n';
}