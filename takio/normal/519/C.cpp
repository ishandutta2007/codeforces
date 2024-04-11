#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100100;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    if (n * 2 <= m) cout << n;
    else if (m * 2 <= n) cout << m;
    else cout << (n + m) / 3;
}