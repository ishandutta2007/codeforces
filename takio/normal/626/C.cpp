#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 1010;

int n, m;

int jug (int x) {
    int c1 = x / 2 - x / 6;
    int c2 = x / 3 - x / 6;
    int c3 = x / 6;
    int cnt = 0;
    if (n > c1) cnt += n - c1;
    if (m > c2) cnt += m - c2;
    return cnt <= c3;
}

int main() {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m;
    int l = 0, r = 10000000;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        if (jug (m)) r = m;
        else l = m;
    }
    cout << r << endl;
}