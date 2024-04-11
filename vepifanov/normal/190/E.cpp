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
vi w[500000];
vvi res;
int q[500000];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        w[a].pb (b);
        w[b].pb (a);
    }
    int r = n;
    for (int i = 0; i < n; i++) q[i] = i;
    while (r > 0) {
        vi v;
        v.pb (q[r - 1]);
        r--;
        for (int i = 0; i < sz (v); i++) {
            int x = v[i], nr = 0, k = 0;
            sort (all (w[x]));
            for (int j = 0; j < r; j++) {
                while (k < sz (w[x]) && w[x][k] < q[j]) k++;
                if (k < sz (w[x]) && w[x][k] == q[j]) q[nr++] = q[j]; else v.pb (q[j]);
            }   
            r = nr;
        }
        res.pb (v);
    }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++) {
        printf ("%d ", sz (res[i]));
        for (int j = 0; j < sz (res[i]); j++)
            printf ("%d ", res[i][j] + 1);
        printf ("\n");
    }
    return 0;
}