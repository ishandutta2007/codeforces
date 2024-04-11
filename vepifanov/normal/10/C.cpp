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
int cnt[61];

int d (int x) {
	int y = 0;
	while (x) { y += x % 10; x /= 10; }
	if (y <= 9) return y;
	return d (y);
}

int main() {
	int n;
	long long ans = 0;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		ans -= (n / i);
	for (int i = 1; i <= n; i++)
		cnt[d (i)]++;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			ans += (long long)cnt[i] * cnt[j] * cnt[d (i * j)];
	printf ("%I64d\n", ans);
	return 0;
}