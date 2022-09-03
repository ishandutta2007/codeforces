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
int was[100];
int r[100], last[100];
int x[100][100], y[100][100];
int ct = 0;

int gcd (int a, int b) {
    if (!a) re b;
    re gcd (b % a, a);
}

int go (int i) {
    was[i] = ct;
    for (int j = 0; j < n; j++) 
        if (x[i][j]) {
            if (was[j] == ct) {
                int d = gcd (r[i], r[j]);
                if (d != x[i][j] || (ll)r[i] * r[j] / d != y[i][j]) re 0;
            } else {
                if ((ll)x[i][j] * y[i][j] % r[i] != 0 || (ll)x[i][j] * y[i][j] / r[i] > 1000000) re 0;
                r[j] = (ll)x[i][j] * y[i][j] / r[i];
                if (gcd (r[i], r[j]) != x[i][j]) re 0;
                if (!go (j)) re 0;
            }   
        }
    re 1;
}

int main() {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        scanf ("%d%d", &x[a][b], &y[a][b]);
        x[b][a] = x[a][b];
        y[b][a] = y[a][b];
        last[a] = last[b] = y[a][b];
    }
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            r[i] = 1;
            ct++;
            while (r[i] <= 1000000 && (last[i] % r[i] != 0 || !go (i))) {
                ct++;
                r[i]++;
            }   
            if (r[i] > 1000000) {
                printf ("NO\n");
                re 0;
            }
        }
    printf ("YES\n");
    for (int i = 0; i < n; i++)
        printf ("%d ", r[i]);
    printf ("\n");
    return 0;
}