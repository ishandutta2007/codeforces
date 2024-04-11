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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int mod = 1000*1000*1000+7;

int n;
int m;
int w[8];
int res[1 << 7];
int nres[1 << 7];
int g[1 << 7][1 << 7];
int h[1 << 7][1 << 7];

int main () {
    for (int i = 1; i <= 7; i++) scanf ("%d", &w[i]); 
    memset (res, 0, sizeof (res));
    res[0] = 1;
    for (int t = 1; t <= 7; t++) {
        int n = 1 << t;
        memset (g, 0, sizeof (g));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int cur = 0;
                for (int k = 0; k < n; k += 2) {
                    int tmp = i | j | k | (k >> 1);
                    if ((tmp & (n - 1)) == n - 1)
                        cur++;
                }
                g[i][j] = cur;
            }
        while (w[t]) {
            if (w[t] & 1) {
                for (int i = 0; i < n; i++) {
                    nres[i] = 0;
                    for (int j = 0; j < n; j++)
                        nres[i] = (nres[i] + (ll)res[j] * g[j][i]) % mod;
                }
                for (int i = 0; i < n; i++)
                    res[i] = nres[i];
            }
            w[t] /= 2;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    h[i][j] = 0;
                    for (int k = 0; k < n; k++)
                        h[i][j] = (h[i][j] + (ll)g[i][k] * g[k][j]) % mod;
                }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    g[i][j] = h[i][j];
        }
    }
    printf ("%d\n", res[0]);
    return 0;
}