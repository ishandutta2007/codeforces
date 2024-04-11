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

ll ans, x[4];
int z[4];
string y[3];

int go (int i) {
	if (i == 1) {
		for (int j = 0; j < 4; j++)
			if (!z[j])
				ans = min (ans, x[j]);
		re 0;
	}
	for (int j = 0; j < 4; j++)
		for (int k = j + 1; k < 4; k++)
			if (!z[j] && !z[k]) {
				ll t = x[j];
				if (y[4 - i] == "+") x[j] += x[k]; else x[j] *= x[k];
				z[k] = 1;
				go (i - 1);
				x[j] = t;
				z[k] = 0;
			}
	re 0;
}

int main() {
	for (int i = 0; i < 4; i++) cin >> x[i];
	for (int i = 0; i < 3; i++) cin >> y[i];
	ans = 1e18;
	go (4);
	cout << ans << endl;
	return 0;
}