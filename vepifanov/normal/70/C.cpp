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
int m;
map<ii, int> all;
int x[200001], y[200001];
int cx[200001], cy[200001];

int rev (int x) {
    int y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    re y;
}

int gcd (int a, int b) {
    if (!a) re b;
    re gcd (b % a, a);
}

int r = 0;

int get (int a, int b) {
    if (all.count (mp (a, b))) re all[mp (a, b)];
    all[mp (a, b)] = r++;
    re r - 1;
}

int mx, my, w;

int main() {
    cin >> mx >> my >> w;
    for (int i = 1; i <= 100000; i++) {
        int a = i;
        int b = rev (i);
        int d = gcd (a, b);
        a /= d;
        b /= d;
        if (i <= mx) { x[i] = get (a, b); }
        if (i <= my) { y[i] = get (b, a); cy[y[i]]++; }
    }
    int cur = 0;
    int kx = 0, ky = my, ax = -1, ay = -1;
    while (kx < mx) {
        kx++;
        cx[x[kx]]++;
        cur += cy[x[kx]];
        while (cur - cx[y[ky]] >= w) {
            cur -= cx[y[ky]];
            cy[y[ky]]--;
            ky--;
        }
        if (cur >= w && (ax == -1 || (ll)ax * ay > (ll)kx * ky)) {
            ax = kx;
            ay = ky;
        }
    }
    if (ax != -1) cout << ax << " " << ay << endl; else cout << "-1" << endl;
    return 0;
}