#include <stdio.h>
#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    long long m;
    vector<long long> f;
    cin >> n >> m;
    f.pb(1);f.pb(1);
    for (int i = 2; i < n; i++) {
        f.pb(f[i-1]+f[i-2]);
        if (f[i] > m) f[i] = m+1;
    }
    vector<int> used(n + 1);
    --m;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (used[j]) continue;
            if (m < f[n-i-1]) {
                printf("%d ", j);
                used[j] = 1;
                break;
            } else m -= f[n-i-1];
        }
    }
    puts("");
}