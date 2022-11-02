#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 
 
using namespace std;

set <string> se;

const int maxn = (int)1e5 + 10;

int dp[maxn][4];
string s;

bool check(int pos, int last, int len) {
	if (last == 0) {
		return true;
	}

	if (last != len) {
		return true;
	}

	for (int i = pos - last; i < pos; i++) {
		if (s[i] != s[i + last]) {
			return true;
		}
	}

	return false;
}

int go(int pos, int last) {
	if (dp[pos][last] == -1) {
		if (pos == (int)s.size()) {
			dp[pos][last] = 1;
		} else {
			dp[pos][last] = 0;
			if (pos + 2 <= (int)s.size() && check(pos, last, 2)) {
				dp[pos][last] = go(pos + 2, 2);
				if (go(pos + 2, 2) == 1) {
					string t = "";
					t.push_back(s[pos]);
					t.push_back(s[pos + 1]);
					se.insert(t);
				}
			}

			if (pos + 3 <= (int)s.size() && check(pos, last, 3)) {
				dp[pos][last] = max(dp[pos][last], go(pos + 3, 3));
				if (go(pos + 3, 3) == 1) {
					string t = "";
					t.push_back(s[pos]);
					t.push_back(s[pos + 1]);
					t.push_back(s[pos + 2]);
					se.insert(t);
				}
			}
		}
	}

	return dp[pos][last];
}

int main() {
	memset(dp, -1, sizeof dp);
	
	cin >> s;

	for (int i = 5; i < (int)s.size(); i++) {
		go(i, 0);
	}

	cout << se.size() << endl;

	for (auto i = se.begin(); i != se.end(); i++) {
		printf("%s\n", (*i).c_str());
	}

	return 0;
}