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
int t[100002], a[100002], b[100002];

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d", &t[i]);
	a[0] = b[n + 1] = 0;
	for (int i = 1; i <= n; i++) a[i] = a[i - 1] + t[i];
	for (int i = n; i >= 1; i--) b[i] = b[i + 1] + t[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] <= b[i])
			ans++;
	printf ("%d %d\n", ans, n - ans);
	return 0;
}