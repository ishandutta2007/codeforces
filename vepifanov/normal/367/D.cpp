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
int d;
int w[100000];
int cur[20];
int bad[1 << 20];

int main () {
    scanf ("%d%d%d", &n, &m, &d);
    for (int i = 0; i < m; i++) {
        int k;
        scanf ("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf ("%d", &x); x--;
            w[x] = i;
        }
    }
    memset (cur, 0, sizeof (cur));
    int mask = 0;
    for (int i = 0; i < n; i++) {
        if (i >= d) {
            cur[w[i - d]]--;
            if (cur[w[i - d]] == 0) mask -= 1 << w[i - d];
        }
        cur[w[i]]++;
        if (cur[w[i]] == 1) mask += 1 << w[i];
        if (i + 1 >= d) bad[(1 << m) - mask - 1] = 1;
    }
    for (int i = (1 << m) - 1; i >= 0; i--)
        if (bad[i])
            for (int j = 0; j < m; j++)
                if ((i >> j) & 1)
                    bad[i - (1 << j)] = 1;
    int ans = m;
    for (int i = 0; i < (1 << m); i++)
        if (!bad[i]) {
            int cur = 0;
            for (int j = 0; j < m; j++)
                if ((i >> j) & 1)
                    cur++;
            ans = min (ans, cur);
        }
    printf ("%d\n", ans);
    return 0;
}