#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using res_t = uint32_t;

const int N = 3e5+7;

ll cost, suf[N];
int a[N], p[N], n, k;

int main() {
    cin >> n >> k; iota(p, p+n, 0);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = n; i--; ) suf[i] = a[i] + suf[i+1];
    sort(p+1, p+n, [](int l, int r) {
        return suf[l] > suf[r];
    });
    sort(p, p+k);

    for(int i = 0, j = 0, q = 0; i < n; ++i) {
        if(j < k && p[j] == i) ++q, ++j;
        cost += (ll)q*a[i];
    }
    
    cout << cost;
}