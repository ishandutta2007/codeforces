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
bool was[36][36];
long long res[36][36];

long long calc (int n, int h) {
	if (n == 0) return 1;
	if (h == 0) return 0;
	if (was[n][h]) return res[n][h];
	long long tmp = 0;
	for (int a = 0; a < n; a++)
		tmp += calc (a, h - 1) * calc (n - a - 1, h - 1);
	was[n][h] = 1;
	res[n][h] = tmp;
	return tmp;
}

int main() {
	int n, h;
	scanf ("%d%d", &n, &h);
	printf ("%I64d\n", calc (n, n) - calc (n, h - 1));
	return 0;
}