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
int m, a, b, c, d;
int x[26];
char g[100][100];

int main() {
    scanf ("%d%d%d%d%d", &a, &b, &c, &d, &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    memset (g, '.', sizeof (g));
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            g[j][i] = '#';
    for (int i = 0; i < c; i++)
        for (int j = 0; j < d; j++)
            g[j][i + a] = '#';
    int q = 0;
    if (b < d && b % 2 == 1 || b >= d && d % 2 == 0) q = 1;
    int k = 0;
    for (int i = 0; i < max (b, d); i++) {
        if (q) {
            for (int j = 0; j < a + c; j++)
                if (g[i][j] == '#') {
                    g[i][j] = k + 'a';
                    x[k]--;
                    if (x[k] == 0) k++;
                }
        } else {
            for (int j = a + c - 1; j >= 0; j--)
                if (g[i][j] == '#') {
                    g[i][j] = k + 'a';
                    x[k]--;
                    if (x[k] == 0) k++;
                }
        }
        q ^= 1;
    }   
    printf ("YES\n");
    for (int i = 0; i < max (b, d); i++) {
        for (int j = 0; j < a + c; j++)
            printf ("%c", g[i][j]);
        printf ("\n");
    }
    return 0;
}