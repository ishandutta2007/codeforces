#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int check(int n, vector <pair <int, int>> v) {
	int q = v.size();
	//cout << q << endl;
	int extr[q];
	pair <int, int> op[n + 1];
	int delta[n + 1];
	for (int i = 1; i <= n; i++) delta[i] = 0;
	for (int i = 1; i <= n; i++) op[i] = {-1, -1};
	for (int i = 0; i < q; i++) extr[i] = 0;
	for (int i = 0; i < q; i++) {
		//op[v[i].first] = max(op[v[i].first], v[i].second);
		if (v[i].second > op[v[i].first].first) {
			op[v[i].first] = {v[i].second, i}; 
		}
		delta[v[i].first]++;
		delta[v[i].second + 1]--;
	}
	int last = -1;
	int num = -1;
	int bal = 0;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		if (op[i].first > last) {
			last = op[i].first;
			num = op[i].second;
		}
		bal += delta[i];
		if (bal == 1) {
			extr[num]++;
		}
		if (bal > 0) s++;
	}
	int mini = 50000;
	for (int i = 0; i < q; i++) mini = min(mini, extr[i]);
	return s - mini;
}

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	int n, q;
	cin >> n >> q;
	vector <pair <int, int>> poss;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		poss.push_back({l, r});
	}
	int maxi = -1;
	for (int i = 0; i < q; i++) {
		vector <pair <int, int>> now;
		for (int j = 0; j < q; j++) {
			if (j != i) now.push_back(poss[j]);
		}
		maxi = max(maxi, check(n, now));
	}
	cout << maxi << endl;
	return 0;
}