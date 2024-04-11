#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q, x;
    cin >> q >> x;
    vector<int> cnt(x);
    int ans = 0;
    while(q--) {
        int a;
        cin >> a;
        cnt[a % x] += 1;
        while(cnt[ans % x] > ans / x) ++ans;
        cout << ans << '\n';
    }
}