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

const int mod = 1000000000 + 7;

int n;
int m;
int f[100001];
int rf[100001];
int p[100001];

int power (int a, int b) {
    if (b < 0) re 1;
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        a = ((ll)a * a) % mod;
        b /= 2;
    }
    re c;
}

int cnk (int a, int b) {
    re (((ll)f[a + b] * rf[a]) % mod * rf[b]) % mod;
}

int go (int i, int j, int l, int r) {
    if (i == n) {
        if (l == -1 && r == -1) re power (2, n - 1);
        re cnk (l, n - r - 1);
    }
    if (p[i] == -1) re go (i + 1, j + 1, l, r);
    int cur = 0;
    if (l == -1) {
        if (p[i] - j >= 0) cur += ((ll)power (2, j - 1) * go (i + 1, 0, p[i] - j, p[i])) % mod;
        if (p[i] + j < n && j > 0) cur += ((ll)power (2, j - 1) * go (i + 1, 0, p[i], p[i] + j)) % mod;
    } else {
            if (p[i] < l) {
                if (l - p[i] - 1 <= j) {
                    int a = l - p[i] - 1;
                    int b = j - a;
                    cur = ((ll)go (i + 1, 0, p[i], r + b) * cnk (a, b)) % mod;
                }   
            } else
            if (p[i] > r) {
                if (p[i] - r - 1 <= j) {
                    int a = p[i] - r - 1;
                    int b = j - a;
                    cur = ((ll)go (i + 1, 0, l - b, p[i]) * cnk (a, b)) % mod;
                }   
            }
    }   
    re cur % mod;
}

int main () {
    f[0] = rf[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        f[i] = ((ll)f[i - 1] * i) % mod;
        rf[i] = power (f[i], mod - 2);
    }
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) p[i] = -1;
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        if (x != 0) p[x - 1] = i;
    }
    printf ("%d\n", go (0, 0, -1, -1));
    return 0;
}