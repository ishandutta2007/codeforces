#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define prev asdgasdg

using namespace std;

const double CT = 1e4;
const double EPS = 1e-10;
const int N = 5e5;

struct Point {
    int r, s;
    int nom;

    bool operator <(const Point &u) const {
        if (r != u.r) return r > u.r;
        return s > u.s;
    }
};

int n, pn, rev[N];
Point a[N];
double u[N], v[N], up[N], down[N];
bool ok[N], can[N];

double get_down(double a0, double b0, double a1, double b1) {
    return (a0 - a1) / (b1 - b0);
}

double get_up(double a0, double b0, double a1, double b1) {
    return (a1 - a0) / (b0 - b1);
}

bool go0(double a0, double b0, double a1, double b1, double a2, double b2) {
    double u = get_down(a0, b0, a1, b1);
    double v = get_down(a0, b0, a2, b2);
    return u + EPS > v;
}

bool go1(double a0, double b0, double a1, double b1, double a2, double b2) {
    double u = get_up(a0, b0, a1, b1);
    double v = get_up(a0, b0, a2, b2);
    return u < v + EPS;
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    pn = n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].r, &a[i].s);
        a[i].nom = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) rev[a[i].nom] = a[i].nom;
    int ms = -1;
    for (int i = 0; i < n; i++) {
        if ((i > 0) && (a[i].r == a[i - 1].r) && (a[i].s == a[i - 1].s)) {
            rev[a[i].nom] = rev[a[i - 1].nom];
        } else if ((i > 0) && (ms >= a[i].s)) {
            rev[a[i].nom] = -1;
        }
        ms = max(ms, a[i].s);
    }
    //for (int i = 0; i < n; i++) cerr << a[i].nom << endl;
    int nn = 1;
    for (int i = 1; i < n; i++) {
        if (rev[a[i].nom] == a[i].nom) {
            a[nn++] = a[i];
        }
    }
    n = nn;
//  cerr << n << endl;
    //for (int i = 0; i < pn; i++) cerr << rev[i] << endl;
    vector<int> st;
    ok[0] = 1;
    st.push_back(0);
    for (int i = 0; i < n; i++) {
        u[i] = CT * 1.0 / a[i].r;
        v[i] = CT * 1.0 / a[i].s;
    }
    for (int i = 1; i < n; i++) {
        while ((st.size() > 1) && (go0(u[i], v[i], u[st[st.size() - 2]], v[st[st.size() - 2]], u[st.back()], v[st.back()]))) {
            st.pop_back();
        }
        down[i] = get_down(u[i], v[i], u[st.back()], v[st.back()]);
        st.push_back(i);
    }

    st.clear();
    ok[n - 1] = 1;
    st.push_back(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        while ((st.size() > 1) && (go1(u[i], v[i], u[st[st.size() - 2]], v[st[st.size() - 2]], u[st.back()], v[st.back()]))) {
            st.pop_back();
        }
        up[i] = get_up(u[i], v[i], u[st.back()], v[st.back()]);
        st.push_back(i);
    }
    for (int i = 1; i < n - 1; i++) {
        ok[i] = down[i] < up[i] + EPS;
    }
    for (int i = 0; i < n; i++) can[a[i].nom] = ok[i];
    for (int i = 0; i < pn; i++) {
        if (rev[i] < 0) can[i] = 0; else
        if (rev[i] != i) can[i] = can[rev[i]];  
    }
    for (int i = 0; i < pn; i++) {
        if (can[i]) printf("%d ", i + 1);
    }
    puts("");
}