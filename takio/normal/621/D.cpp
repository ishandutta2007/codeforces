#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

char S[5] = "xyz";
long double c[3];

struct data {
    int t, id;
    long double x, y, z;
    string s;
    data () {}
    data (int tt, int tx, int ty, int tz, int tid) {
        t = tt, x = c[tx], y = c[ty], z = c[tz], id = tid;
        if (t) s += '(';
        s += S[tx];
        s += '^';
        s += S[ty];
        if (t) s += ')';
        s += '^';
        s += S[tz];
    }
} a[20];

bool cmp (data a, data b) {
    if (a.t == 0 && b.t == 0) {
        if (fabs (pow(a.y, a.z) * log (a.x) - pow (b.y, b.z) * log (b.x)) > 1e-6)
        return pow(a.y, a.z) * log (a.x) < pow (b.y, b.z) * log (b.x);
    }
    if (a.t == 1 && b.t == 1) {
        if (fabs (a.y * a.z * log (a.x) - b.y * b.z * log (b.x)) > 1e-6)
        return a.y * a.z * log (a.x) < b.y * b.z * log (b.x);
    }
    if (a.t == 1 && b.t == 0) {
        if (fabs (a.y * a.z * log (a.x) - pow (b.y, b.z) * log (b.x)) > 1e-6)
        return a.y * a.z * log (a.x) < pow (b.y, b.z) * log (b.x);
    }
    if (a.t == 0 && b.t == 1) {
        if (fabs (pow(a.y, a.z) * log (a.x) - b.y * b.z * log (b.x)) > 1e-6)
        return pow(a.y, a.z) * log (a.x) < b.y * b.z * log (b.x);
    }
    return a.id > b.id;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> c[0] >> c[1] >> c[2];
    int n = 0;
    a[++n] = data (0, 0, 1, 2, 1);
    a[++n] = data (0, 0, 2, 1, 2);
    a[++n] = data (0, 1, 0, 2, 3);
    a[++n] = data (0, 1, 2, 0, 4);
    a[++n] = data (0, 2, 0, 1, 5);
    a[++n] = data (0, 2, 1, 0, 6);
    a[++n] = data (1, 0, 1, 2, 7);
    a[++n] = data (1, 0, 2, 1, 8);
    a[++n] = data (1, 1, 0, 2, 9);
    a[++n] = data (1, 1, 2, 0, 10);
    a[++n] = data (1, 2, 0, 1, 11);
    a[++n] = data (1, 2, 1, 0, 12);
    sort (a + 1, a + 1 + n, cmp);
    cout << a[n].s << endl;
}