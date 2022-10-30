#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int N = 10100;
vector <int> g[N];

int f = 1;
int used [5000100];

int gcd (int n, int m) {
    while (n && m) if (n > m) n %= m; else m %= n;
    return n + m;
}

int getnx (int x) {
    while (used[x]) x++;
    return x;
}

int jug (int k, int x) {
    int t[5];
    t[0] = x, t[1] = x + 2, t[2] = x + 3, t[3] = x + 4;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (gcd (t[i], t[j]) != 1) return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        g[k].push_back (t[i]);
        used[t[i]] = 1;
    }
    return 1;
}

int main () {
    int n, m;
    cin >> n >> m;
    int mx = 0, t;
    for (int i = 1; i <= n; i++) {
        while (used[f]) f++;
        t = f;
        while (!jug (i, t = getnx (t))) t++;
        mx = max (mx, t + 4);
    }
    cout << mx * m << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            printf ("%d", g[i][j] * m);
            if (j == 3) printf ("\n"); else printf (" ");
        }
    }
}