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

const string name[7] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};

int n;
int m;
int g[7][7];
int ans, res, p[7], x[3], y[3];

int get (string s) {
    for (int i = 0; i < 7; i++)
        if (name[i] == s)
            re i;
    re 0;
}

int go (int i) {
    if (i == 7) {
        int y[3];
        memset (y, 0, sizeof (y));
        for (int i = 0; i < 7; i++)
            y[p[i]]++;
        if (y[0] * y[1] * y[2] == 0) re 0;
        int mn = min (x[0] / y[0], min (x[1] / y[1], x[2] / y[2]));
        int mx = max (x[0] / y[0], max (x[1] / y[1], x[2] / y[2]));
        int smp = 0;
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 7; j++)
                if (g[i][j] && p[i] == p[j])
                    smp++;
        if (mx - mn < ans || mx - mn == ans && res < smp) {
            ans = mx - mn;
            res = smp;
        }
        re 0;
    }
    for (int j = 0; j < 3; j++) {
        p[i] = j;
        go (i + 1);
    }
    re 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        g[get (a)][get (c)] = 1;
    }
    for (int i = 0; i < 3; i++) cin >> x[i];
    ans = 2e9 + 1;
    res = 0;
    go (0);
    printf ("%d %d\n", ans, res);
    return 0;
}