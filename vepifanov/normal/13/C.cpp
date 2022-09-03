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
long long res[2][5000];
int x[5000], y[5000];

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) { 
		scanf ("%d", &x[i]);	
		y[i] = x[i];
	}
	sort (y, y + n);
	for (int i = 0; i < n; i++)
		res[0][i] = abs (x[0] - y[i]);
	for (int i = 0; i + 1 < n; i++) {
		int ci = i & 1;
		int ni = 1 - ci;
		long long cur = 1e18;
		for (int j = 0; j < n; j++) {
			if (cur > res[ci][j]) cur = res[ci][j];
			res[ni][j] = cur + abs (x[i + 1] - y[j]);
		}
	}
	int ci = (n - 1) & 1;
	long long ans = 1e18;
	for (int i = 0; i < n; i++)
		if (ans > res[ci][i])
			ans = res[ci][i];
	cout << ans << endl;
	return 0;
}