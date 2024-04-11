#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using pii = pair<int, int>;

const int N = 105;

int n, a[N], m;

int solve() {
    if(m == 1) return 0;
    if(m == 2) return (a[1] - a[0])%2 ? a[1]-a[0] : (a[1]-a[0])/2;
    if(m == 3) return a[2]-a[1] == a[1]-a[0] ? a[2]-a[1] : -1;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    m = unique(a,a+n) - a;
    cout << solve();
}