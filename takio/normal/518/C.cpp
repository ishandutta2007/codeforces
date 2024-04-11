#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 100100;

int a[N], pos[N], id[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        pos[a[i]] = i;
        id[i] = id[i - 1];
        if ((i - 1) % k == 0) id[i]++;
    }
    int x;
    LL res = 0;
    while (m--) {
        scanf ("%d", &x);
        res += id[pos[x]];
        if (pos[x] == 1) continue;
        int t = pos[x];
        pos[a[t - 1]]++, pos[x]--;
        swap (a[t - 1], a[t]);
//        for (int i = 1; i <= n; i++) {
//            printf ("%d ", a[i]);
//        } cout << endl;
    }
    cout << res << endl;
}