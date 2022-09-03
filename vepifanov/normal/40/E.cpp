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
int m, k, mod;
int p[1001], fn[1001], fm[1001], cn[1001], cm[1001];

int calc (int x, int y) {
        if (x == 0) re y;
        re p[x - 1];
}

int main() {
        scanf ("%d%d%d", &n, &m, &k);
        for (int i = 0; i < k; i++) {
                int a, b, c;
                scanf ("%d%d%d", &a, &b, &c); a--; b--;
                fn[a]++;
                cn[a] ^= int (c == -1);
                fm[b]++;
                cm[b] ^= int (c == -1);
        }
        scanf ("%d", &mod);
        p[0] = 1;
        for (int i = 1; i <= 1000; i++) p[i] = (p[i - 1] * 2) % mod;
        if ((m & 1) == (n & 1)) {
                int ans = 1, f = 0;
                if (n < m) {
                        for (int i = 0; i < n; i++)
                                if (fn[i] == m) ans *= cn[i];
                        for (int i = 0; i < m; i++) {
                                if (fm[i] == 0 && !f) { f = 1; continue; }
                                ans = ((ll)ans * calc (n - fm[i], cm[i])) % mod;
                        }
                } else {
                        for (int i = 0; i < m; i++)
                                if (fm[i] == n) ans *= cm[i];
                        for (int i = 0; i < n; i++) {
                                if (fn[i] == 0 && !f) { f = 1; continue; }
                                ans = ((ll)ans * calc (m - fn[i], cn[i])) % mod;
                        }
                }
                printf ("%d\n", ans);
        } else printf ("0\n");
        return 0;
}