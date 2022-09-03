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
int x[100000], y[100000];

int check (int p) {
	m = 0;
	for (int i = 0; i < n; i++)
		if (i != p)
			y[m++] = x[i];
	for (int i = 1; i + 1 < m; i++)
		if (y[i] * y[i] != y[i - 1] * y[i + 1])
			re 0;
	for (int i = 0; i < m; i++)
		if (y[i] == 0) {
			for (int j = i; j < m; j++)
				if (y[j] != 0)
					re 0;
			break;
		}
	re 1;
}

int main() {    
	scanf ("%d", &n);	
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	if (n < 1000) {
		if (check (n)) { printf ("0\n"); re 0; }
		for (int i = 0; i < n; i++)
			if (check (i)) {
				printf ("1\n");
				re 0;
			}
		printf ("2\n");		
	} else {
		int l = 0, r = n - 1;
		while (l + 1 < n && x[l + 1] == x[l]) l++;
		while (r - 1 >= 0 && x[r - 1] == x[r]) r--;
		int ok = 2;
		if (l >= r) ok = min (ok, 0);
		if (l + 2 == n || r == 1 || l + 2 == r && x[l] == x[r]) ok = min (ok, 1);
		l = 0;
		r = n - 1;
		while (l + 1 < n && x[l + 1] == -x[l]) l++;
		while (r - 1 >= 0 && x[r - 1] == -x[r]) r--;
		if (l >= r) ok = min (ok, 0);
		if (l + 2 == n || r == 1 || l + 2 == r && x[l] == -x[r] || l + 1 == r && x[l] == x[r]) ok = min (ok, 1);
		int z = 0;
		for (int i = 0; i < n; i++)
			if (x[i] != 0)
				z++;
		if (z == 0 || z == 1 && x[0] != 0) ok = 0;
		if (z == 1 && x[0] == 0 || z == 2 && x[0] != 0) ok = min (ok, 1);
		printf ("%d\n", ok);
	}
	return 0;
}