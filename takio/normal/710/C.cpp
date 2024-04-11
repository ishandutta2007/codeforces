#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 55;

int a[N][N];

int main()
{
//    freopen ("in.txt", "r", stdin);
    int n, A = -1, B = 0;
    cin >> n;
    int m = n / 2 + 1;
//    int tmp = (n / 2) & 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = (((max (abs (i - m), abs (j - m)) & 1) ^ (i & 1) ^ (j & 1) ^ 1) ? A += 2 : B += 2);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        } cout << endl;
    }
    return 0;
}