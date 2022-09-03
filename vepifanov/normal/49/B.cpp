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

int get (char c) {
	re c - '0';
}

int main() {
	string a, b;
	cin >> a >> b;
	reverse (all (a));
	reverse (all (b));
	while (a.size () < b.size ()) a += '0';
	while (b.size () < a.size ()) b += '0';
	int ans = 0;
	for (int i = 2; i <= 16; i++) {
		int r = 0, ok = 1, k = 0;
		while (k < a.size ()) {
			if (get (a[k]) >= i || get (b[k]) >= i) ok = 0;
			r += get (a[k]) + get (b[k]);
			r /= i;
			k++;
		}
		k += int (r > 0);
		if (ok) ans = max (ans, k);
	}
	printf ("%d\n", ans);
	
	return 0;
}