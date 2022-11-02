#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair <int, int>
#define xx first
#define yy second
#define LL long long
using namespace std;

const int N = 100100;
char s[N], t[N];

int jug1 (int l, int r) {
    for (int i = l; i < r; i++) {
        if (s[i] != t[i + 1]) return 0;
    }
    return 1;
}

int jug2 (int l, int r) {
    for (int i = l; i < r; i++) {
        if (s[i + 1] != t[i]) return 0;
    }
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    scanf ("%s%s", s, t);
    int l, r;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != t[i]) {
            r = i;
            break;
        }
    }
    if (l == r) { cout << 2; return 0; }
    cout << jug1 (l, r) + jug2 (l, r) << endl;
}