#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 100100;

char t[30] = {"CODEFORCES"}, s[1100];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, a[20], an = 0;
    cin >> n;
    while (n) {
        a[++an] = n % 10;
        n /= 10;
    }
    int f[20], res = 0;
    f[1] = 1;
    for (int i = 2; i <= 9; i++) f[i] = f[i - 1] * 10;
    for (int i = 1; i <= an; i++) {
        res = max (res, a[i]);
    }
    cout << res << endl;
    for (int i = 1; i <= res; i++) {
        int tmp = 0;
        for (int j = 1; j <= an; j++) {
            if (a[j]) a[j]--, tmp += f[j];
        }
        cout << tmp << ' ';
    }
}