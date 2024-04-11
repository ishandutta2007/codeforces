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

struct tpos {
	char w[3][4];
};

bool operator== (tpos a, tpos b) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a.w[i][j] != b.w[i][j])
				return false;
	return true;
}

int hash (tpos a) {
	int tmp = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tmp = tmp * 3 + int (a.w[i][j] == 'X') + 2 * int (a.w[i][j] == 'Y');
	return tmp;
}

int n;
int m;
char g[4][4];

int iswin (tpos a) {
	int o1 = int (a.w[0][0] != '.'), o2 = int (a.w[2][0] != '.');
	for (int i = 0; i < 3; i++) {
		int ok1 = int (a.w[i][0] != '.'), ok2 = int (a.w[0][i] != '.');
		for (int j = 0; j < 3; j++) {
			ok1 &= int (a.w[i][j] == a.w[i][0]);
			ok2 &= int (a.w[j][i] == a.w[0][i]);
		}
		if (ok1) return int (a.w[i][0] == 'X');
		if (ok2) return int (a.w[0][i] == 'X');
		o1 &= int (a.w[i][i] == a.w[0][0]);
		o2 &= int (a.w[2 - i][i] == a.w[2][0]);
	}
	if (o1) return int (a.w[0][0] == 'X');
	if (o2) return int (a.w[2][0] == 'X');
	return -1;
}

int go (tpos a, int p, tpos b, int l) {
	int win = iswin (a);
	if (a == b) {
		if (win != -1) {
			if (win == 1) printf ("the first player won\n"); else printf ("the second player won\n");
		} else {
			if (l == 9) printf ("draw\n"); else 
			if (p == 1) printf ("first\n"); else printf ("second\n");
		}
		return 1;
	}
	if (win != -1) return 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a.w[i][j] == '.') {
				a.w[i][j] = 'X' * p + '0' * (1 - p);
				if (go (a, p ^ 1, b, l + 1)) return 1;
				a.w[i][j] = '.';
			}
	return 0;
}

int main() {
	tpos x, y;
	for (int i = 0; i < 3; i++) {
		gets (x.w[i]);
		for (int j = 0; j < 3; j++) y.w[i][j] = '.';
	}
	if (!go (y, 1, x, 0)) printf ("illegal\n");
	return 0;
}