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
int w[100][100];

int main() {
	int n, k;
	scanf ("%d%d", &n, &k);
	int X = k / 2, Y = k / 2;
	for (int i = 0; i < n; i++) {
		int a;
		scanf ("%d", &a);
		int cur = -1, ax = 0, al = 0, ar = 0;
		for (int x = 0; x < k; x++)
			for (int y = 0; y + a <= k; y++) {
				int ok = 1, sum = 0;
				for (int j = 0; j < a; j++) {
					sum += abs (x - X) + abs (y + j - Y);
					if (w[x][j + y]) ok = 0;
				}
				if (ok && (cur == -1 || cur > sum)) {
					cur = sum;
					ax = x;
					al = y;
					ar = y + a - 1;
				} 
			} 
		if (cur == -1) printf ("-1\n"); else {
			printf ("%d %d %d\n", ax + 1, al + 1, ar + 1);
			for (int j = al; j <= ar; j++) w[ax][j] = 1;
		}                                        
	}
	return 0;
}