#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 105, mod = 1e9 + 7;
int c[20];

struct mat {
    int a[N][N];
    mat () {
        memset (a, 0, sizeof a);
    }
    void w (int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
            cout << endl;
        } cout << endl;
    }
};

mat mul (mat A, mat B) {
    mat C;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                (C.a[i][j] += (LL)A.a[i][k] * B.a[k][j] % mod) %= mod;
            }
        }
    }
    return C;
}

mat pm (mat A, int p) {
    mat B;
    for (int i = 0; i < N; i++) B.a[i][i] = 1;
    while (p) {
        if (p & 1) B = mul (B, A);
        A = mul (A, A);
        p >>= 1;
    }
    return B;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, a, b, k, x;
    cin >> n >> b >> k >> x;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
        c[a]++;
    }
    mat B;
    for (int i = 0; i < x; i++) {
        for (int j = 1; j <= 9; j++) {
            int k = (i * 10 + j) % x;
            B.a[i][k] += c[j];
        }
    }
//    B.w (x);
    mat A;
    A.a[0][0] = 1;
    A = mul (A, pm (B, b));
    cout << A.a[0][k] << endl;
}