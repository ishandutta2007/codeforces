#include <bits/stdc++.h>
using namespace std;

long long query(int a, vector<long long>& ft) {
	long long res = 0;
	for ( ; ~a; a = (a & (a + 1)) - 1) {
		res += ft[a];
	}
	return res;
}

void update(int a, int val, vector<long long>& ft) {
	for ( ; a < ft.size(); a = a | (a + 1)) {
		ft[a] += val;
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> pt(n);
	map<int, int> idx;
	for (auto& i : pt) {
		cin >> i.first;
	}
	for (auto& i : pt) {
		cin >> i.second;
		idx[i.second] = 0;
	}
	sort(pt.begin(), pt.end());
	
	int sz = 0;
	for (auto& i : idx) {
		i.second = sz++;
	}
	
	long long ans = 0;
	vector<long long> ct(sz), coord(sz);
	for (auto i : pt) {
		int tmp = idx[i.second];
		ans += i.first * query(tmp, ct) - query(tmp, coord);
		update(tmp, 1, ct);
		update(tmp, i.first, coord);
	}
	cout << ans << '\n';
}