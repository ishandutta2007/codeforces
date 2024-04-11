#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100100, mod = 1e9 + 7;

int main () {
//    freopen ("in.txt", "r", stdin);
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i * a <= c; i++) {
        if ((c - i * a) % b == 0) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}