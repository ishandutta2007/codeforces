#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int A = 26;
string s;
int n;
bool g[A][A];
bool has[A];
bool fst[A];
string ans = "";

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < A; i++)
		fst[i] = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int L = (int)s.length();
		for (int j = 0; j < L; j++) {
			has[(int)(s[j] - 'a')] = 1;
			if (j > 0) {
				fst[(int)(s[j] - 'a')] = 0;
				g[(int)(s[j - 1] - 'a')][(int)(s[j] - 'a')] = 1;
			}
		}
	}
	for (int i = 0; i < A; i++) {
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < A; j++) {
			cnt1 += g[i][j];
			cnt2 += g[j][i];
		}
		if (cnt1 > 1 || cnt2 > 1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (int i = 0; i < A; i++) {
		if (!has[i]) continue;
		if (!fst[i]) continue;
		int v = i;
		while(v != -1) {
			has[v] = 0;
			ans.push_back((char)('a' + v));
			int w = -1;
			for (int u = 0; u < A; u++) {
				if (!g[v][u]) continue;
				w = u;
			}
			v = w;
		}
	}
	for (int i = 0; i < A; i++) {
		if (has[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << ans << endl;

	return 0;
}