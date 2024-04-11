#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <memory.h>
#include <vector>

#define N (1 << 24)

using namespace std;

int a[N], ans, cnt[N], n;

void solve(int l, int r, int k) {
    if (k == -1) {
        a[l] = cnt[l];
        return;
    }
    int mid = (l + r) >> 1;
    solve(l, mid, k - 1);
    solve(mid, r, k - 1);
    for (int i = mid; i < r; i++)
        a[i] += a[i - (1 << k)];
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int mask = 0;
        for (int j = 0; j < s.size(); j++)
            mask |= 1 << int(s[j] - 'a');
        cnt[mask]++;
    }
    solve(0, 1 << 24, 23);
    ans = 0;
    // for (int i = 0; i < (1 << 24); i++)
        // if (a[i] != 0) 
            // printf("%d %d\n", i, a[i]);
    // return 0;
    for (int i = 0; i < (1 << 24); i++) {
        a[i] = n - a[i];
        ans ^= a[i] * a[i];
    }
    cout << ans << endl;
    return 0;
}