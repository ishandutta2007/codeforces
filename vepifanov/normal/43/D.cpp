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

int main() {
	scanf ("%d%d", &n, &m);
	if (n % 2 == 0 && (m > 1 || n < 3)) {
		printf ("0\n");
		printf ("1 1\n");
		for (int i = 1; i <= n; i++)
			for (int j = 2; j <= m; j++)
				printf ("%d %d\n", i, i & 1 ? j : m - j + 2);
		for (int i = n; i >= 1; i--)
			printf ("%d 1\n", i);
	} else
	if (m % 2 == 0 && (n > 1 || m < 3)) {
		printf ("0\n");
		printf ("1 1\n");
		for (int i = 1; i <= m; i++)
			for (int j = 2; j <= n; j++)
				printf ("%d %d\n", i & 1 ? j : n - j + 2, i);
		for (int i = m; i >= 1; i--)
			printf ("1 %d\n", i);
	} else {
		printf ("1\n%d %d 1 1\n", n, m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				printf ("%d %d\n", i, i & 1 ? j : m - j + 1);
		printf ("1 1\n");
	}
	
	return 0;
}