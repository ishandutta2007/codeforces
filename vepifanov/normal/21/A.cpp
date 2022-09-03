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
char w[200];

int main() {
	gets (w);
	int n = strlen (w);
	int x = -1, y = n;
	for (int i = 0; i < n; i++)
		if (w[i] == '@') x = i; else
		if (w[i] == '/') y = i;
	if (x == -1 || x == 0 || x > 16) printf ("NO\n"); else {
		for (int i = 0; i < x; i++)
			if (!(w[i] >= '0' && w[i] <= '9' || w[i] >= 'A' && w[i] <= 'Z' || w[i] >= 'a' && w[i] <= 'z' || w[i] == '_')) {
				printf ("NO\n");
				return 0;
			}
		if (y - x - 1 > 32) printf ("NO\n"); else {
			int cur = 0;
			for (int i = x + 1; i <= y; i++)
				if (i == y || w[i] == '.') {
					if (cur == 0 || cur > 16) {
						printf ("NO\n");
						return 0;
					}
					cur = 0;
				} else {
					cur++;
					if (!(w[i] >= '0' && w[i] <= '9' || w[i] >= 'A' && w[i] <= 'Z' || w[i] >= 'a' && w[i] <= 'z' || w[i] == '_')) {
						printf ("NO\n");
						return 0;
					}
				}
			if (y == n) printf ("YES\n"); else
			if (y == n - 1 || n - y - 1 > 16) printf ("NO\n"); else {
				for (int i = y + 1; i < n; i++)
					if (!(w[i] >= '0' && w[i] <= '9' || w[i] >= 'A' && w[i] <= 'Z' || w[i] >= 'a' && w[i] <= 'z' || w[i] == '_')) {
						printf ("NO\n");
						return 0;
					}
				printf ("YES\n");
			}
		}
	}
	return 0;   
}