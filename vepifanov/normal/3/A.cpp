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
char a[3], b[3];

int go (int i1, int j1, int i2, int j2) {
	while (i1 < i2 && j1 < j2) {
		printf ("RU\n");
		i1++; j1++;
	}
	while (i1 < i2 && j1 > j2) {
		printf ("LU\n");
		i1++; j1--;
	}
	while (i1 > i2 && j1 < j2) {
		printf ("RD\n");
		i1--; j1++;
	}
	while (i1 > i2 && j1 > j2) {
		printf ("LD\n");
		i1--; j1--;
	}
	while (i1 < i2) { printf ("U\n"); i1++; }
	while (i1 > i2) { printf ("D\n"); i1--; }
	while (j1 < j2) { printf ("R\n"); j1++; }
	while (j1 > j2) { printf ("L\n"); j1--; }
	return 0;
}

int main() {
	gets (a);
	gets (b);
	int i1 = a[0] - 'a', j1 = a[1] - '1';
	int i2 = b[0] - 'a', j2 = b[1] - '1';
	printf ("%d\n", max (abs (i1 - i2), abs (j1 - j2)));
	go (j1, i1, j2, i2);
	return 0;
}