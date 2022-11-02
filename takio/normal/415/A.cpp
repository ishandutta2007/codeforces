#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int u[110];

int main () {
    int n, m, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b;
        int t = b;
        while (!u[b] && b <= n) u[b++] = t;
//        for (int j = 1; j <= n; j++) {
//            if (j != 1 ) cout << ' ';
//            cout << u[j];
//        }cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1 ) cout << ' ';
        cout << u[i];
    }
}