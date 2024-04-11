#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(26);
        string s;
        cin >> s;
        for(char c : s) a[c - 'a'] += 1;
        int x = 0, y = 0;
        for(int i = 0; i < 26; ++i) {
            x += a[i] / 2;
            y += a[i] % 2;
        }
        int lo = 1, hi = n;
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if(x - (mid & 1 ? (max(k - y, 0) + 1) / 2 : 0) >= 1ll * mid / 2 * k) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << '\n';
    }
}