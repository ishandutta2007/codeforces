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
int p[300000], q[300000], use[300000], last[300000];
ii g[100000][3];
ii w[100000];

int main() {
    scanf ("%d", &n);

    for (int i = 0; i < 3 * n; i++) {
        scanf ("%d", &p[i]);
        p[i]--;
        q[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf ("%d", &g[i][j].se);
            g[i][j].se--;
            g[i][j].fi = q[g[i][j].se];
        }
        sort (g[i], g[i] + 3);
    }
    int f;
    scanf ("%d", &f);
    f--;
    for (int i = 0; i < n; i++) {
        if (g[i][0].se == f) {
            use[g[i][1].se] = use[g[i][2].se] = 1;
            for (int k = 0; k < 3 * n && (last[g[i][1].se] != i + 1 || last[g[i][2].se] != i + 1); k++)
                if (use[k]) {
                    last[k] = i + 1;
                    printf ("%d ", k + 1);
                }   
            for (int k = 0; k < 3 * n; k++)
                if (last[k] != i + 1 && k != f) {
                    last[k] = i + 1;
                    printf ("%d ", k + 1);
                }   
            printf ("\n");
            re 0;
        }
        use[g[i][0].se] = use[g[i][1].se] = use[g[i][2].se] = 1;
    }
    for (int i = 0; i < 3 * n; i++)
        if (i != f) 
            printf ("%d ", i + 1);
    printf ("\n");
    return 0;
}