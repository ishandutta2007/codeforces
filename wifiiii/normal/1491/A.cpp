#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), cnt(2);
    for(int i = 0; i < n; ++i) cin >> a[i], cnt[a[i]]++;
    while(q--) {
        int op, k;
        cin >> op >> k;
        if(op == 1) {
            --k;
            cnt[a[k]]--;
            a[k] ^= 1;
            cnt[a[k]]++;
        } else {
            if(cnt[1] >= k) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}