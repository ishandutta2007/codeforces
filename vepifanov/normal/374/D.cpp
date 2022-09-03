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

const int N = 1 << 20;

int n;
int m;
int x[1000000];
int u[1000000];
int w[1000000];
int tree[2 * N + 1];

int put (int x, int l, int r, int y) {
    tree[x]++;
    if (l == r) re 0;
    int s = (l + r) / 2;
    if (y <= s) put (x * 2 + 1, l, s, y); else put (x * 2 + 2, s + 1, r, y);
    re 0;
}

int kill (int x, int l, int r, int y) {
    tree[x]--;
    if (l == r) {
        u[l] = 1;
        re 0;
    }   
    int s = (l + r) / 2;
    if (tree[x * 2 + 1] >= y) kill (x * 2 + 1, l, s, y); else kill (x * 2 + 2, s + 1, r, y - tree[x * 2 + 1]);
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf ("%d", &x[i]);
    int o = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        if (x == -1) {
            for (int j = 0; j < m; j++) {
                int k = ::x[j] - j;
                if (tree[0] >= k) kill (0, 0, n - 1, k); else break;
            }
        } else {
            put (0, 0, n - 1, o);
            w[o++] = x;
        }
    }
    if (tree[0] == 0) printf ("Poor stack!\n"); else {
        for (int i = 0; i < o; i++)
            if (!u[i])
                printf ("%d", w[i]);
        printf ("\n");
    }   
    return 0;
}