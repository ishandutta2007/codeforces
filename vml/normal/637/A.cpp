#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <cstdio>
#include <cassert>
#include <climits>
#include <ctime>

using namespace std;

#define ll long long
#define mp make_pair

int n, a[2000001], x, ans, y;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x]++;
		if (a[x] > ans) {
			ans = a[x];
			y = x;
		}
	}
	cout << y;

	return 0;
}