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
int x[1003];
int w[1003];
int a[3], b[3];

int go (int i) {
    int ok = 1;
    for (int j = 1; j <= n && ok; j++)
        if (j != x[j])
            ok = 0;
    if (ok) {
        printf ("%d\n", i);
        for (int j = 0; j < i; j++)
            printf ("%d %d\n", a[i - j - 1], b[i - j - 1]);
        re 1;
    }
    if (i < 3) {
        int m = 0;
        int w[1000];
        for (int j = 1; j <= n; j++)
            if (abs (x[j] - x[j - 1]) > 1 || abs (x[j] - x[j + 1]) > 1)
                w[m++] = j;
        for (int s = 0; s + 1 < m; s++)
            for (int t = s + 1; t < m; t++) {
                reverse (x + w[s], x + w[t] + 1);
                a[i] = w[s];
                b[i] = w[t];
                if (go (i + 1)) re 1;
                reverse (x + w[s], x + w[t] + 1);
            }
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    x[0] = 0;
    x[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) scanf ("%d", &x[i]);
    go (0);
    return 0;
}