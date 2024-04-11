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
int p[200];
vi res;
int was[200];

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

int add (int a, int b) {
    a = gp (a);
    b = gp (b);
    if (a != b)
        if (rand () & 1)
            p[a] = b;
        else
            p[b] = a;   
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < 2 * n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        if (c) {
            add (a, b);
            add (a + n, b + n);
        } else {
            add (a, b + n);
            add (b, a + n);
        }
    }
    for (int i = 0; i < n; i++)
        if (gp (i) == gp (i + n)) {
            printf ("Impossible\n");
            re 0;
        }
    for (int i = 0; i < n; i++)
        if (!was[i] && !was[i + n])
            for (int j = 0; j < 2 * n; j++)
                if (gp (i) == gp (j)) {
                    if (j < n) res.pb (j + 1);
                    was[j] = 1;
                                }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++)
        printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}