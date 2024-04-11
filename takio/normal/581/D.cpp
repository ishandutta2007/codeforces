#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second

using namespace std;

const int N = 100100;

vector <int> t;
int sz;

int jug0 () {
    if (t[0] != sz || t[2] != sz || t[4] != sz) return 0;
    if (t[1] + t[3] + t[5] != sz) return 0;
//    for (int i = 0; i < 6; i++) cout << t[i] <<' '; cout << endl;
    cout << sz << endl;
    while (t[1]--) { for (int i = 1; i <= sz; i++ ) printf ("A"); printf ("\n"); }
    while (t[3]--) { for (int i = 1; i <= sz; i++ ) printf ("B"); printf ("\n"); }
    while (t[5]--) { for (int i = 1; i <= sz; i++ ) printf ("C"); printf ("\n"); }
    return 1;
}

int vis[10], b[10];

int jug1 () {
    if (t[0] != sz) return 0;
    if (t[2] + t[4] != sz) return 0;
    if (t[3] != t[5]) return 0;
    if (t[1] + t[3] != sz) return 0;
    cout << sz << endl;
//    for (int i = 0; i < 3; i++) cout << b[i] << endl;
    while (t[1]--) { for (int i = 1; i <= sz; i++ ) printf ("%c", b[0] + 'A'); printf ("\n"); }
    while (t[3]--) {
        for (int i = 1; i <= t[2]; i++ ) printf ("%c", b[1] + 'A');
        for (int i = 1; i <= t[4]; i++ ) printf ("%c", b[2] + 'A');
        printf ("\n");
    }
//    cout << "0";
    return 1;
}

int x[10][10], all = 0;

int dfs (int k) {
    if (k == 3) {
        if (jug1 ()) return 1;
        return 0;
    }
    for (int i = 0; i < 3; i++) if (!vis[i]) {
        vis[i] = 1;
        b[k] = i;
        t.push_back (x[0][i]), t.push_back (x[1][i]);
        if (dfs (k + 1)) return 1;
        t.pop_back(), t.pop_back();
        t.push_back (x[1][i]), t.push_back (x[0][i]);
        if (dfs (k + 1)) return 1;
        t.pop_back(), t.pop_back();
        vis[i] = 0;
    }
    return 0;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    for (int i = 0; i < 3; i++) {
        cin >> x[0][i] >> x[1][i];
        all += x[0][i] * x[1][i];
    }
    sz = sqrt (all) + 0.5;
    if (sz * sz != all) { cout << -1; return 0; }
//    cout << "x";
    for (int i = 0; i < 8; i++) {
        t.clear();
        for (int j = 0; j < 3; j++) {
            if (i & (1 << j)) t.push_back (x[0][j]), t.push_back (x[1][j]);
            else t.push_back (x[1][j]), t.push_back (x[0][j]);
        }
        if (jug0 ()) { return 0; }
    }
    t.clear();
    if (!dfs (0)) cout << -1;
}