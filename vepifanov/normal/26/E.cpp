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
int x[100], p[100];

bool myless (int i, int j) {
	return x[i] > x[j];
}

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	if (n == 1) {
		if (m != x[0]) printf ("No\n"); else {
			printf ("Yes\n");
			for (int i = 0; i < m; i++) printf ("1 1 ");
			printf ("\n");
		}
	} else {
		int s = 0;
		for (int i = 0; i < n; i++) s += x[i];
		if (m > s) {
			printf ("No\n");
			return 0;
		}
		for (int i = 0; i < n; i++) p[i] = i;
		sort (p, p + n, myless);
		if (x[p[0]] > 1) {
			if (x[p[n - 1]] > 1) {
				if (m < 2) printf ("No\n"); else {
					printf ("Yes\n");
					x[p[0]]--;
					x[p[1]]--;
					printf ("%d ", p[0] + 1);
					for (int i = 1; i < n; i++)
						while (x[p[i]] > 0 && s > m) {
							printf ("%d %d ", p[i] + 1, p[i] + 1);
							x[p[i]]--;
							s--;
						}
					printf ("%d ", p[0] + 1);
					printf ("%d ", p[1] + 1);
					while (x[p[0]] > 0 && s > m) {
						printf ("%d %d ", p[0] + 1, p[0] + 1);
						x[p[0]]--;
						s--;
					}
					printf ("%d ", p[1] + 1);
					for (int i = 0; i < n; i++)
						for (int j = 0; j < x[p[i]]; j++)
							printf ("%d %d ", p[i] + 1, p[i] + 1);
					printf ("\n");
				}
			} else {
				if (m < 1) printf ("No\n"); else {
					printf ("Yes\n");
					printf ("%d ", p[n - 1] + 1);
					for (int i = 0; i < n - 1; i++)
						while (x[p[i]] > 0 && s > m) {
							printf ("%d %d ", p[i] + 1, p[i] + 1);
							x[p[i]]--;
							s--;
						}
					printf ("%d ", p[n - 1] + 1);
					for (int i = 0; i < n - 1; i++)
						for (int j = 0; j < x[p[i]]; j++)
							printf ("%d %d ", p[i] + 1, p[i] + 1);
					printf ("\n");
				}
			}
		} else {
			if (m < 1 || m > n) printf ("No\n"); else {
				printf ("Yes\n");
				printf ("1 ");
				for (int j = 0; j < n - m; j++) printf ("%d %d ", j + 2, j + 2);
				printf ("1 ");
				for (int j = n - m; j + 1 < n; j++) printf ("%d %d ", j + 2, j + 2); 
				printf ("\n");
			}
		}
	}
	return 0;
}