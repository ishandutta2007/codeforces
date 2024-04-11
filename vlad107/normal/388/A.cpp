#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <memory.h>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <ctime>

#define N 1111

using namespace std;

bool cmp(int x, int y) {
    return x > y;
}

int n, a[N], bad, kg[N], g[N][N];

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    sort(a, a + n, cmp);
    for (int ans = 1; ans <= n; ans++) {
        for (int i = 0; i < ans; i++)
            kg[i] = 0;
        bad = 0;    
        int j = 0;
        for (int i = 0; i < n; i++) {
            bool found = 0;
                int u = 100500;
                for (int t = 0; t < kg[j]; t++)
                    if (g[j][t] - (kg[j] - t - 1) < u)
                        u = g[j][t] - (kg[j] - t - 1);
                if (u > 0) {
                    g[j][kg[j]] = a[i];
                    kg[j]++;
                } else {
                    bad = 1;
                    break;
                }
            j = (j + 1) % ans;
        }
        if (!bad) {
            cout << ans << endl;
            return 0;
        }
    }
}