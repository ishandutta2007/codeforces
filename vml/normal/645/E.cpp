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
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

const int maxn = (int)2e6 + 10;
int n, k;
char s[maxn];
int pos[maxn];

set <pair <int, int> > t;
string g;
int sum[maxn];
int mod = (int)1e9 + 7;

int go(int l, int r) {
	if (l > r) {
		return 0;
	}

	if (l == 0) {
		return sum[r];
	}

	int ans = sum[r] - sum[l - 1];

	if (ans < 0) {
		ans += mod;
	}

	return ans;
}

bool us[maxn];

int main() {
	cin >> n >> k;

	scanf("%s", s);

	int len = strlen(s);

	for (int i = 0; i < len; i++) {
		pos[s[i] - 'a'] = i + 1;
		g.push_back(s[i]);
	}

	for (int i = 0; i < k; i++) {
		t.insert(mp(pos[i], i));
	}

	for (int i = 0; i < n; i++) {
		int x = (*t.begin()).second;

		t.erase(mp(pos[x], x));
		pos[x] = len + i + 1;
		t.insert(mp(pos[x], x));

		g.push_back('a' + x);
	}

	memset(pos, 0, sizeof pos);

	int ans = 0;

	//cout << g << endl;

	for (int i = 0; i < (int)g.size(); i++) {
		ans += go(pos[g[i] - 'a'], i - 1);

		if (!us[g[i] - 'a']) {
			us[g[i] - 'a'] = true;
			ans++;
		}

		if (ans >= mod) {
			ans -= mod;
		}

		sum[i] = ans;
		pos[g[i] - 'a'] = i;
	}

	ans++;
	ans %= mod;

	cout << ans << endl;

	return 0;
}