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

int a[N], tree[N], p[N], pn, ish[N];
vector <int> g[N];

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        scanf ("%d", &a[i]);
    }
    int k = 1;
    while (k < n) {
        if (k == m) {
            cout << "YES";
            return 0;
        }
        k += a[k];
    }
    if (k == m) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}