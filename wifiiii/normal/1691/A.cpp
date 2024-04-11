#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> cnt(2);
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[x & 1] += 1;
        }
        cout << min(cnt[0], cnt[1]) << '\n';
    }
}