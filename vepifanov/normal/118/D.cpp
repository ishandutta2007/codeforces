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

const int mod = 100000000;

int n;
int m;
int n1, n2, k1, k2;
int was[101][101][2][11];
int res[101][101][2][11];

int go (int a, int b, int t, int k) {
	if (a == 0 && b == 0) re 1;
	if (was[a][b][t][k]) re res[a][b][t][k];
	was[a][b][t][k] = 1;
	int cur = 0;
	if (a > 0 && int (t == 0) * k + 1 <= k1) cur += go (a - 1, b, 0, int (t == 0) * k + 1);
	if (b > 0 && int (t == 1) * k + 1 <= k2) cur += go (a, b - 1, 1, int (t == 1) * k + 1);
	if (cur >= mod) cur -= mod;
	re res[a][b][t][k] = cur;
}

int main () {
	scanf ("%d%d%d%d", &n1, &n2, &k1, &k2);	
	printf ("%d\n", go (n1, n2, 0, 0));
	return 0;
}