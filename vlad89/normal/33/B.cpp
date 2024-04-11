#define _CRT_SECURE_NO_DEPRECATE
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) SORT(a),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int inf = -1u/4;
char s[123456], t[123456];
int a[26][26];
int b[26][26];
char c[26][26];

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
	int n;
	gets (s);
	gets (t);
	if (strlen (s) != strlen (t)) {
		puts ("-1");
		return 0;
	}
	scanf ("%d", &n);
	REP (i, 26) REP (j, 26) if (i != j) a[i][j] = inf;
	REP (i, n) {
		char q, w;
		int e;
		scanf (" %c %c%d", &q, &w, &e);
		a[q-'a'][w-'a'] = min (a[q-'a'][w-'a'], e);
	}
	REP (k, 26) REP (i, 26) REP (j, 26) a[i][j] = min (a[i][j], a[i][k] + a[k][j]);

	REP (i, 26) REP (j, 26) {
		b[i][j] = inf;
		REP (k, 26)
			if (a[i][k] + a[j][k] < b[i][j]) {
				b[i][j] = a[i][k] + a[j][k];
				c[i][j] = k+'a';
			}
	}
	long long ans = 0;
	for (int i = 0; s[i]; ++i) {
		if (b[s[i]-'a'][t[i]-'a'] == inf) {
			puts ("-1");
			return 0;
		}
		ans += b[s[i]-'a'][t[i]-'a'];
		s[i] = c[s[i]-'a'][t[i]-'a'];
	}
	cout << ans << endl;
	printf ("%s\n", s);
	return 0;
}