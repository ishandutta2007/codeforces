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

const int MAX = 1000000;

int n;
int m, a, b, k;
int f[MAX + 2];
int h[MAX + 2];

int can (int s) {
    for (int i = a; i + s - 1 <= b; i++)
        if (h[i] - h[i + s] < k)
            re 0;
    re 1;
}

int main () {
    f[1] = 1;
    for (int i = 2; i <= MAX; i++)
        if (!f[i])
            if (i <= MAX / i)
                for (int j = i * i; j <= MAX; j += i)
                    f[j] = 1;
    h[MAX + 1] = 0;
    for (int i = MAX; i >= 1; i--) h[i] = h[i + 1] + (1 - f[i]);
    scanf ("%d%d%d", &a, &b, &k);
    if (h[a] - h[b + 1] < k) {
        printf ("-1\n");
        re 0;
    }
    int l = 0, r = b - a + 1;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (can (s)) r = s; else l = s;
    }
    printf ("%d\n", r);
    return 0;
}