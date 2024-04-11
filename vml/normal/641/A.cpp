#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <ctime>
#include <cassert>
#include <memory.h>
#include <bitset>

using namespace std;

#define ll long long
#define mp make_pair

const ll mod = 1000000007;
const int maxn = 200001;

int n, d[200001], was[200001];
string s;

int main() {

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	int cur = 0;
	while (true) {
		if (was[cur]) {
			cout << "INFINITE";
			return 0;
		}
		was[cur] = 1;
		if (s[cur] == '>') {
			cur += d[cur];
		}
		else {
			cur -= d[cur];
		}
		if (cur < 0 || cur >= n) {
			cout << "FINITE";
			return 0;
		}
	}

	return 0;
}