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

const int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int n;
int m;
vii v[11];
vi u[1 << 10];
int cnt[10];
int res[5000];

int go (int i, int I, int mask, int cur, int MAX) {
    if (i == I) {
        u[mask].pb (cur);
        re 1;
    }   
    int ans = 0;
    if ((mask >> i) & 1) {
        while (cur * p[i] <= MAX) {
            cur *= p[i];
            ans += go (i + 1, I, mask, cur, MAX);
        }
    } else ans = go (i + 1, I, mask, cur, MAX);
    re ans;
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) v[j].clear ();
        for (int mask = 1; mask < (1 << i); mask++) {
            u[mask].clear ();
            int cur = go (0, i, mask, 1, 2 * n * n);
            int tmp = 0;
            for (int j = 0; j < i; j++)
                if ((mask >> j) & 1)
                    tmp++;
            v[tmp].pb (mp (cur, mask));
        }
        memset (cnt, 0, sizeof (cnt));
        int m = 0;
        for (int j = i; j > 0; j--) {
            int k = 0;
            int empty = 0;
            while (m < n) {
                if (v[j][k].fi == 0) {
                    empty++;
                    if (empty == sz (v[j])) break;
                } else {
                    empty = 0;
                    int mask = v[j][k].se;
                    for (int t = 0; t < i; t++)
                        if ((mask >> t) & 1)
                            cnt[t]++;
                    v[j][k].fi--;
                    res[m++] = u[mask][v[j][k].fi];
                }
                k = (k + 1) % sz (v[j]);
            }
        }
        if (m == n) {
            int ok = 1;
            for (int j = 0; j < i; j++)
                if (2 * cnt[j] < n)
                    ok = 0;
            if (ok) {
                sort (res, res + n);
                for (int j = 0; j < n; j++)
                    printf ("%d ", res[j]);
                printf ("\n");
                re 0;
            }
        }   
    }
    return 0;
}