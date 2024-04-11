#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;

char w[2000000];
int res[2000000], p[2000000];

int main() {
	gets (w);
	int n = strlen (w);
	int r = 0;
	for (int i = 0; i < n; i++)
		if (w[i] == ')') {
			if (r > 0) {
				r--;
				res[i] = i - p[r] + 1;
				if (p[r] > 0 && res[p[r] - 1] != -1)
					res[i] = res[i] + res[p[r] - 1];
			} else res[i] = -1;
		} else {
			res[i] = -1;
			p[r++] = i;
		}
	int ans = 0, cnt = 1;
	for (int i = 0; i < n; i++)
		if (res[i] > ans) {
			ans = res[i];
			cnt = 1;
		} else
		if (res[i] == ans) cnt++;
	printf ("%d %d\n", ans, cnt);
	return 0;
}