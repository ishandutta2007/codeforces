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
#include <memory.h>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

map <pair <ll, ll>, int > s;
string t;

const int maxn = 1100;
char k[maxn];
ll t1 = 1234567;
ll p1 = (int)1e9 + 7, p2 = (int)1e9 + 9;

int dp[100000];
int n;

int go(int pos) {
	if (dp[pos] == -1) {
		if (pos == n) {
			dp[pos] = 0;
		} else {
			dp[pos] = (int)1e9;
			ll nowa = 0, nowb = 0;
			ll tt1 = 1;
			ll tt2 = 1;
			for (int i = pos; i < n; i++) {
				nowa += tt1 * (t[i] - 'a' + 1);
				nowb += tt2 * (t[i] - 'a' + 1);
				nowa %= p1;
				nowb %= p2;
				tt1 *= t1;
				tt1 %= p1;
				tt2 *= t1;
				tt2 %= p2;

				if (s.count(mp(nowa, nowb))) {
					if (go(i + 1) != (int)1e9) {
						dp[pos] = s[mp(nowa, nowb)];
						break;
					}
				}
			}
		}
	}

	return dp[pos];
}



int main() {
	cin >> n;

	cin >> t;

	int m;

	cin >> m;

	vector <string> v;

	for (int i = 0; i < m; i++) {
		v.push_back("");
		scanf("%s", k);

		ll nowa = 0, nowb = 0;
		int len = strlen(k);

		for (int j = 0; j < len; j++) {
			nowa *= t1;
			nowb *= t1;
			if ('a' <= k[j] && k[j] <= 'z') {
				nowa += k[j] - 'a' + 1;
				nowb += k[j] - 'a' + 1;
			} else {
				nowa += k[j] - 'A' + 1;
				nowb += k[j] - 'A' + 1;
			}

			nowa %= p1;
			nowb %= p2;

			v.back().push_back(k[j]);
		}

		s[mp(nowa, nowb)] = i;
	}

	memset(dp, -1, sizeof dp);

	if (go(0) == (int)1e9) {
		throw 1;
	}

	int pos = 0;

	while (pos != n) {
		for (int i = 0; i < (int)v[dp[pos]].size(); i++) {
			printf("%c", v[dp[pos]][i]);
		}

		printf(" ");

		pos += v[dp[pos]].size();
	}

	return 0;
}