//
//  main.cpp
//  Round 477
//
//  Created by  on 2018/4/29.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	const int MAX = 62;
	vector< vector<long long> > a(MAX);
	for (int i = 0; i < n; i++) {
		long long foo;
		cin >> foo;
		int highest = -1;
		for (int j = MAX - 1; j >= 0; j--) {
			if (foo & (1LL << j)) {
				highest = j;
				break;
			}
		}
		a[highest].push_back(foo);
	}
	vector<long long> res;
	for (int j = MAX - 1; j >= 0; j--) {
		if (a[j].empty()) {
			continue;
		}
		vector<long long> new_res;
		new_res.push_back(a[j].back());
		a[j].pop_back();
		for (long long foo : res) {
			new_res.push_back(foo);
			if (foo & (1LL << j)) {
				if (!a[j].empty()) {
					new_res.push_back(a[j].back());
					a[j].pop_back();
				}
			}
		}
		if (!a[j].empty()) {
			cout << "No" << '\n';
			return 0;
		}
		swap(res, new_res);
	}
	cout << "Yes" << '\n';
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << ' ';
		}
		cout << res[i];
	}
	cout << '\n';
	return 0;
}