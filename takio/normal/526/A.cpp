#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#define pii pair <int, int>
#define xx first
#define yy second
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

const int N = 100100;

int n;
char s[110];

int in (int x) {
    return x < n && s[x] == '*';
}

int jug (int i, int j) {
    for (int k = 0; k <= 4; k++) {
//        if (i == 1 && j == 3) cout << k << endl;
        if (!in(i + k * j)) return 0;
    }
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (jug (i, j)) { cout << "yes"; return 0; }
        }
    }
    cout << "no";
}