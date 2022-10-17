#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

#define int ll
int32_t main() {
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int edge = k - a[r] + a[l] - 1;
        int mid = a[r] - a[l] + 1 - (r - l + 1);
        cout << mid * 2 + edge << endl;
    }
}