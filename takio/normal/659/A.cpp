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
#define pdi pair <double, int>
using namespace std;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;
    if (b < 0) {
        while (b) {
            b++;
            a --;
            if (a == 0) a = n;
        }
    }
    if (b > 0) {
        while (b) {
            b--;
            a++;
            if (a == n + 1) a = 1;
        }
    }
    cout << a << endl;
}