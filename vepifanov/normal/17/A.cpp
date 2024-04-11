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
int p[1001], can[1001];

int main() {
	int n, k, last = 0;
	scanf ("%d%d", &n, &k);
	for (int i = 2; i <= n; i++)
		if (!p[i]) {
			k -= can[i];
			if (last != 0 && last + i + 1 <= n) can[last + i + 1] = 1;
			last = i;
			for (int j = i * i; j <= n; j += i) p[j] = 1;
		}
	if (k > 0) printf ("NO\n"); else printf ("YES\n");
	return 0;
}