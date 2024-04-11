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

const int N = 100000;
const int TT = 3;

int n;
int m;

vi v;
int f[N + 1];
int res[N];
int prev[N];
vii ans;
int x[N];
int y[N];

int add (int a, int b) {
    ans.pb (mp (a + 1, b + 1));
    y[x[a]] = b;
    y[x[b]] = a;
    swap (x[a], x[b]);
    re 0;
}

vi w;

int gen (int x) {
    if (x == 0) re 0;
    w.pb (prev[x]);
    gen (x - prev[x]);
    re 0;
}

int main () {
    for (int i = 2; i <= N; i++)
        if (!f[i]) {
            v.pb (i - 1);
            for (int j = i; j <= N; j += i)
                f[j] = 1;
        }
        scanf ("%d", &n);
        res[0] = 0;
        int k = 0;
        for (int i = 1; i < n; i++) {
            res[i] = 1e9;
            while (k + 1 < sz (v) && v[k + 1] <= i) k++;
            for (int j = k; j >= 0 && res[i] > TT; j--)
                if (res[i] > res[i - v[j]] + 1) {
                    res[i] = res[i - v[j]] + 1;
                    prev[i] = v[j];
                }
        }
        for (int i = 0; i < n; i++) {
            scanf ("%d", &x[i]); x[i]--;
            y[x[i]] = i;
        }
        for (int i = 0; i < n; i++)
            if (y[i] != i) {
                int tmp = y[i] - i;
                w.clear ();
                gen (tmp);
                for (int j = 0; j < sz (w); j++)
                    add (y[i] - w[j], y[i]);
            }
        printf ("%d\n", sz (ans));
        for (int i = 0; i < sz (ans); i++) printf ("%d %d\n", ans[i].fi, ans[i].se);
    return 0;
}