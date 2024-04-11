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

const int MAX = 1000;
const int MIN = 500;

int n;
int m;
int g[101];
int w[101];
int x[MAX + 1];

int get (int a, int b) {
    x[0] = 1;
    for (int i = 1; i <= MAX; i++) x[i] = x[i - 1] * a % b;
    int k = MAX;
    while (x[k] == 0) k--;
    if (k < MIN) {
        g[b] = 2;
        w[b] = k + 1;
        re 0;
    }
    int ok = 1;
    for (int i = 0; i <= MAX; i++)
        if (x[i] != 1)
            ok = 0;
    if (ok) {
        g[b] = 3;
        re 0;
    }
    ok = 1;
    for (int i = 0, j = 1; i <= MAX; i++, j *= -1)
        if (x[i] != (b + j) % b)
            ok = 0;
    if (ok) {
        g[b] = 11;
        re 0;
    }
    g[b] = 7;
    re 0;
}

int gcd (int a, int b) { re a ? gcd (b % a, a) : b; }

int nok (int a, int b) {
    re a * b / gcd (a, b);
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 2; i <= m; i++) get (n, i);
    if (g[m] != 7) {
        printf ("%d-type\n", g[m]);
        if (g[m] == 2) printf ("%d\n", w[m]);
        re 0;
    }
    for (int a = 2; a <= m; a++)
        for (int b = a; a * b <= m; b++)
            if (nok (a, b) == m && g[a] != 7 && g[b] != 7) {
                printf ("6-type\n");
                re 0;
            }
    for (int a = 2; a <= m; a++)
        for (int b = a; a * b <= m; b++)
            for (int c = b; a * b * c <= m; c++)
                if (nok (a, nok (b, c)) == m && g[a] != 7 && g[b] != 7 && g[c] != 7) {
                    printf ("6-type\n");
                    re 0;
                }
    printf ("7-type\n");
    return 0;
}