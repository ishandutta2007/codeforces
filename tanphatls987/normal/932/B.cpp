#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int f[N];
int g[N][10];

int cal(int x) {
    if (x < 10) return x;

    int prod = 1;
    while (x) {
        int dig = x % 10; x /= 10;
        if (dig != 0) prod *= dig;
    }
    return cal(prod);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    for(int i = 1; i < N; i++) 
        f[i] = cal(i);
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 10; j++) g[i][j] = g[i - 1][j];
        g[i][f[i]]++;
    }
    int test;
    cin >> test;
    while (test--) {
        int L, R, k;
        cin >> L >> R >> k;
        cout << g[R][k] - g[L - 1][k] << '\n';
    }
}