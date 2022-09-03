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
int x[200000], rl[200000], rr[200000];

int main() {
	scanf ("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &x[i]);
		sum += x[i];
	}	
	int cur = 0, res = 0;
	rl[0] = 0;
	for (int i = 1; i <= n; i++) {
		cur += x[i];
		if (cur < res) res = cur;
		rl[i] = res;
	}
	cur = 0;
	res = 0;
	rl[n + 1] = 0;
	for (int i = n; i > 0; i--) {
		cur += x[i];
		if (cur < res) res = cur;
		rr[i] = res;
	}
	int ans = sum;
	for (int i = 0; i <= n; i++)
		if (sum - 2 * (rl[i] + rr[i + 1]) > ans)
			ans = sum - 2 * (rl[i] + rr[i + 1]);
	printf ("%d\n", ans);
	return 0;
}