#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 200100;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    LL r = 0;
    for (int i = 1; i <= min (k, n / 2); i++) {
        r += (n - i * 2) * 2 + 1;
    }
    cout << r << endl;
}