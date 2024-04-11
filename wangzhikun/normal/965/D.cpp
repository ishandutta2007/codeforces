//
//  main.cpp
//  Round 476
//
//  Created by  on 2018/4/26.
//  Copyright  2018 . Aint rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<long long> s(n + 1, 0);
	long long best = 2e18;
	
	for (int i = 1; i < n; ++i) {
		int now; cin >> now; s[i] = s[i - 1] + now;
		if (i >= k) best = min(best, s[i] - s[i - k]);
	}
	cout << best << endl;
	return 0;
}