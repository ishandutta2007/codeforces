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
int m, k;
int a[100000], b[100000], c[100000], x[100];

int main() {
	scanf ("%d%d%d", &n, &m, &k);	
	for (int i = 0; i < m; i++) scanf ("%d%d%d", &a[i], &b[i], &c[i]);
	for (int i = 0; i < k; i++) scanf ("%d", &x[i]);
	ll ans = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			if (a[i] <= x[j] && b[i] >= x[j])
				ans += c[i] + (x[j] - a[i]);
	cout << ans << endl;	
	return 0;
}