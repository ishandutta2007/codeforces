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
int m, k;
int f[100];
int x[100];
int y[100];
int p[100];
int q[100];
int r[100];

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf ("%d", &x); x--;
        f[x]++;
    }
    scanf ("%d", &k);
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        cin >> p[i];
        for (int j = 0; j < p[i]; j++) {
            int x;
            scanf ("%d", &x); x--;
            if (x == -1) r[i]++; else
            if (f[x]) q[i]++;
        }
        x[i] = q[i] + r[i] - min (n - m - (p[i] - q[i] - r[i]), r[i]);
        y[i] = q[i] + min (m - q[i], r[i]);
    }
    for (int i = 0; i < k; i++) {
        int ok = 0;
        for (int j = 0; j < k && !ok; j++)
            if (i != j)
                if (y[i] < x[j])
                    ok = 1;
        if (!ok)
            for (int j = 0; j < k && !ok; j++)
                if (i != j)
                    if (y[j] > x[i])
                        ok = 2;
        printf ("%d\n", ok);
    }
    return 0;
}