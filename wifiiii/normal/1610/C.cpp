#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];
        int lo = 1, hi = n;
        auto chk = [&](int k) -> int {
            int res = k - 1, cur = 0;
            for(int i = 0; i < n; ++i) {
                if(b[i] >= cur && a[i] >= res) {
                    --res;
                    ++cur;
                    if(cur == k) break;
                }
            }
            return cur == k;
        };
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if(chk(mid)) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << '\n';
    }
}