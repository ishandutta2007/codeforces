#include <cstdio>
#include <iostream>
using namespace std;

int n, a[5010];

int solve (int l, int r){
    if (l > r) return 0;
    if (l == r) return 1;
    int mn = 1e9 + 10;
    for (int i = l; i <= r; i++)
        mn = min(mn, a[i]);
    int res = mn;
    int f = l - 1;
    for (int i = l; i <= r; i++)
    {
        a[i] -= mn;
        if (a[i] == 0) res += solve(f + 1, i - 1), f = i;
    }
    res += solve(f + 1, r);
    return min(res, r - l + 1);
}

int main () {
    cin >> n;
    for (int i = 1; i<= n; i++)
        cin >>a[i];
    cout << solve(1, n);
}