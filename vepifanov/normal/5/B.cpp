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

char s[1001][1001];
int l[1001];

int main() {
	int w = 0;
	int n = 0;
	while (gets (s[n])) {
		if (!s[0]) break;
		l[n] = strlen (s[n]);
		if (l[n] > w) w = l[n];
		n++;
	}
	int q = 0;
	for (int i = 0; i < w + 2; i++) printf ("*");
	printf ("\n");
	for (int i = 0; i < n; i++) {
		printf ("*");
		int a = (w - l[i]) / 2;
		int b = w - l[i] - a;
		if (a != b && l[i] > 0) {
			if (q) swap (a, b);
			q ^= 1;
		}
		for (int j = 0; j < a; j++) printf (" ");
		printf ("%s", s[i]);
		for (int j = 0; j < b; j++) printf (" ");
		printf ("*\n");
	}
	for (int i = 0; i < w + 2; i++) printf ("*");
	printf ("\n");
	return 0;
}