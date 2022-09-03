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
ll k;
int p;

int was[20];

int go2 (int x, int y) {
    int t = 0;
    if (x > 0 && x <= y) t++;
    if (x <= 100000000) t += go2 (x * 10 + 4, y) + go2 (x * 10 + 7, y);
    re t;
}

int cool (int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) re 0;
        x /= 10;
    }
    re 1;
}

int go (int i, ll j, ll k) {
    if (i == 0) re 0;
    k /= i;
    for (int l = 0; l < p; l++)
        if (!was[l])
            if (j <= k) {
                was[l] = 1;
                re go (i - 1, j, k) + cool (n - i + 1) * cool (n - p + l + 1);
            } else j -= k;
}

int main () {
    cin >> n >> m;
    k = 1;
    p = 1;
    while (k < m && p < n) {
        p++;
        k *= p;
    }
    if (k < m) printf ("-1\n"); else printf ("%d\n", go2 (0, n - p) + go (p, m, k));
    return 0;
}