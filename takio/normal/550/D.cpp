#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

void link (int a, int b) {
    printf ("%d %d\n", a, b);
}

void solve (int u, int n) {
    int a = u + n - 1, b = u + n - 2;
    link (a, b);
    for (int i = 1; i <= n - 3; i++) {
        link (u, u + i);
        link (a, u + i);
        link (b, u + i);
    }
    for (int i = 1; i <= n - 3; i++) {
        for (int j = i + 1; j <= n - 3; j++) {
            if (i % 2 == 1 && j == i + 1) continue;
            link (u + i, u + j);
        }
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int k;
    cin >> k;
    if (k % 2 == 0) { cout << "NO"; return 0; }
    cout << "YES\n";
    if (k == 1) { cout << "2 1\n1 2"; return 0; }
    cout << 2 * k + 4 << ' ' << (k + 2) * k << endl;
    link (1, k + 3);
    solve (1, k + 2);
    solve (k + 3, k + 2);

}