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

char w[5000001];
int res[5000001], d[5000001][2];

int good (int i) {
	return d[(i + 1) >> 1][i & 1] == ((i + 1) >> 1);
}

int main() {
        gets (w);
        int n = strlen (w);
        for (int t = 0; t < 2; t++) {
        	int l = 0, r = -1, j;
        	for (int i = 0; i < n; i++) {
        		if (i > r) j = 1; else j = min (d[l + r - i + t][t], r - i + t) + 1;
        		while (i + j - t < n && i - j >= 0 && w[i + j - t] == w[i - j]) j++;
        		j--;
        		d[i][t] = j;
        		if (i + j + t > r) { l = i - j; r = i + j - t; }
        	}
        }
        long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (good (i - 1)) res[i] = res[i / 2] + 1; else res[i] = 0;
		ans += res[i];
	}
	cout << ans << endl;
	return 0;
}