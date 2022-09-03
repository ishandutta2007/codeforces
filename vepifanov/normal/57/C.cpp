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

const int mod = 1000000007;

int n;
int m;

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int main() {
	scanf ("%d", &n);
	int ans = 1;
	for (int i = 1; i <= 2 * n - 1; i++) ans = ((ll)ans * i) % mod;
	for (int i = 1; i <= n - 1; i++) {
		int j = power (i, mod - 2);
		ans = ((ll)ans * j) % mod;
		ans = ((ll)ans * j) % mod;
	}
	ans = ((ll)ans * power (n, mod - 2)) % mod;
	ans = (ans * 2) % mod;
	ans = (ans - n + mod) % mod;
	printf ("%d\n", ans);
	return 0;
}