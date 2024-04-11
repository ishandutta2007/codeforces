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
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> inline T sqr (T x) { re x * x; }

#define filename ""

int n;
int m;
char h[100100];
int d[100100];
int was[100100];

int main () {
	scanf ("%d", &n);
	scanf (" %s", h);
	for (int i = 0; i < n; i++) scanf ("%d", &d[i]);
	int cur = 0;
	while (cur >= 0 && cur < n) {
		if (was[cur]) {
			printf ("INFINITE\n");
			re 0;
		}
		was[cur] = 1;
		if (h[cur] == '<') cur -= d[cur]; else cur += d[cur];
	}
	printf ("FINITE\n");
	return 0;
}