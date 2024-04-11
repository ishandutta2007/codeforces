#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100;

int res[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    LL l, r;
    int res = 0;
    cin >> l >> r;
    for (int i = 2; i <= 63; i++) {
        LL now = 1LL << i;
        now--;
//        cout << now << endl;
        for (int j = 0; j < i - 1; j++) {
            LL tmp = now ^ (1LL << j);
            if (l <= tmp && tmp <= r) {
//                for (int j = 0; j < i; j++) if ()
                res++;
            }
        }
    }
    cout << res << endl;
}