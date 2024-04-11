#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <ctime>
#include <map>
#define ld double
#define ll long long
#define mp make_pair

using namespace std;

int n;

const int maxn = (int)1e5 + 10;
int v[maxn];
int dp[maxn];

int main() {
	cin >> n;

	vector <pair <int, int> > f;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		f.push_back(make_pair(v[i], i));
	}

	sort(f.begin(), f.end());

	int ans = 1;

	int now = 1;

	for (int i = 1; i < n; i++) {
		if (f[i].second > f[i - 1].second) {
			now++;
		} else {
			ans = max(ans, now);
			now = 1;
		}
	}

	ans = max(ans, now);

	cout << n - ans << endl;

	return 0;
}