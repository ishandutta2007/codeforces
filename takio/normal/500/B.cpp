#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define LL long long

using namespace std;

const int N = 100100;

int a[N], tree[N], p[N], pn, ish[N], mp[310][310];
vector <int> g[N];
//struct mat {
//    int a[330][330];
//    void init () {
//        memset (a, 0, sizeof a);
//    }
//}A;
//
//
//mat mul (mat A) {
//    mat C;
//    C.init();
//    for (int i = 1; i <= 300; i++) {
//        for (int j = 1; j <= 300; j++) if (!C.a[i][j]) {
//            for (int k = 1; k <= 300; k++) {
//                C.a[i][j] |= A.a[i][k] & A.a[k][j];
//            }
//            C.a[i][j] |= A.a[i][j];
//        }
//    }
//    return C;
//}
//
//
//mat pow (mat A) {
//    int T = 10;
//    while (T--) {
//        A = mul(A);
//    }
//    return A;
//}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            mp[i][j] |= c - '0';
            mp[j][i] |= c - '0';
            if (i == j) mp[i][j] = 1;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mp[i][j] |= mp[i][k] & mp[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < a[i]; j++) {
            for (int k = i + 1; k <= n; k++) {
                if (a[k] == j && mp[k][i]) {
                    swap (a[i], a[k]);
                    goto x;
                }
            }
        }
        x:;
//        for (int i = 1; i <= n; i++) cout << a[i] << ' ';cout << endl;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}