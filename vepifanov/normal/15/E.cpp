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

const int mod = 1000000009;

int n;
int m;

int main() {
	int n;
	scanf ("%d", &n);
	int cur = 1, sum = 2, p2 = 4, mul = 1;
	for (int i = 2; i * 2 <= n; i++) {
		mul = ((long long)mul * cur) % mod;
		sum = (sum + (long long)4 * mul) % mod;
		cur = (cur + p2) % mod;
		p2 = (p2 * 2) % mod;
	}
	printf ("%d\n", int((2 + 2 * (long long)sum * sum) % mod));
	return 0;
}