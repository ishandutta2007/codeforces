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

const int LEN = 300;
const int MAX = (100000 + LEN - 1) / LEN;

int n;
int m;
int was[100000], x[100000], y[100000];
int l[MAX], r[MAX], w[MAX];
vector<pair<ii, int> > v;
vi res;

int get (int a, int b) {
    int A = a / LEN;
    int B = b / LEN;
    if (abs (A - B) <= 1) {
        for (int i = a; i <= b; i++)
            if (!was[i])
                re i;
    } else {
        for (int i = a; i <= r[A]; i++)
            if (!was[i])
                re i;
        for (int i = A + 1; i < B; i++)
            if (w[i] > 0) {
                for (int j = l[i]; j <= r[i]; j++)
                    if (!was[j])
                        re j;
            }
        for (int i = l[B]; i <= b; i++)
            if (!was[i])
                re i;
    }
    re -1;
}

int add (int x) {
    was[x] = 1;
    int y = x / LEN;
    w[y]--;
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf ("%d%d", &x[i], &y[i]); x[i]--; y[i]--;
        v.pb (mp (mp (x[i], y[i]), i));
    }
    int NUM = (n + LEN - 1) / LEN;
    for (int i = 0; i < NUM; i++) {
        l[i] = i * LEN;
        r[i] = min ((i + 1) * LEN, n) - 1;
        w[i] = r[i] - l[i] + 1;
    }
    sort (all (v));
    for (int i = 0; i < m; i++) {
        int j = v[i].se;
        int a = n - y[j] - 1;
        int b = x[j];
        int c = get (a, b);
        if (c != -1) {
            res.pb (j + 1);
            add (c);
        }
    }
    sort (all (res));
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++)
        printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}