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

int n, W, l[2];
int m;
char w[200000], s[2][1000];
int p[2][1000];

int go (int t, int x) {
	if (x == -1) return -2;
	int k = -1;
	for (int i = x; i < W; i++) {
		while (k != -1 && w[i] != s[t][k + 1]) k = p[t][k];
		if (w[i] == s[t][k + 1]) k++;
		if (k + 1 == l[t]) return i;
	}
	return -2;
}

int main() {
	gets (w);
	gets (s[0]);
	gets (s[1]);
	W = strlen (w);
	for (int t = 0; t < 2; t++) {
		l[t] = strlen (s[t]);        
		p[t][0] = -1;
		for (int i = 1; i < l[t]; i++) {
			int k = p[t][i - 1];
			while (k != -1 && s[t][k + 1] != s[t][i]) k = p[t][k];
			if (s[t][k + 1] == s[t][i]) k++;
			p[t][i] = k;
		}
	}
	int x = go (1, go (0, 0) + 1);
	reverse (w, w + W);
	int y = go (1, go (0, 0) + 1);
	if (x == -2 && y == -2) printf ("fantasy\n"); else
	if (x == -2) printf ("backward\n"); else
	if (y == -2) printf ("forward\n"); else
	printf ("both\n");
	return 0;
}