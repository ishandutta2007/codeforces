#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int a[100], b[100], c[100], d[100];

int main () {
	scanf ("%d", &n);	
	int res = -1;
	for (int i = 0; i < n; i++) scanf ("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	for (int i = 0; i < n; i++) {
		int ok = 1;
		for (int j = 0; j < n; j++)
			if (a[i] < a[j] && b[i] < b[j] && c[i] < c[j])
				ok = 0;
		if (ok && (res == -1 || d[res] > d[i])) res = i;
	}
	printf ("%d\n", res + 1);
	return 0;
}