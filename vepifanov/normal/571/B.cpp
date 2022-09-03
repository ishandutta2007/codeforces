#include <bits/stdc++.h>

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
#define prev PREV
#define next NEXT
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const D pi = asin(1.0) * 2;

#define filename ""

int n;
int m;
bool was[5001][5001];
int res[5001][5001];
int x[300000];
int a, b, A, B;

int go (int i, int j) {
    if (i + j == m) re 0;
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    int cur = 2e9 + 1;
    int pos = i * A + j * B;
    if (i < a) cur = min (cur, go (i + 1, j) + x[pos + A - 1] - x[pos]);
    if (j < b) cur = min (cur, go (i, j + 1) + x[pos + B - 1] - x[pos]);
    re res[i][j] = cur;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    sort (x, x + n);
    a = n % m;
    b = m - a;
    A = n / m + 1;
    B = n / m;
    printf ("%d\n", go (0, 0));
    re 0;
}