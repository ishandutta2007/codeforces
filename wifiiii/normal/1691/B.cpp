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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> ans(n);
        int ok = 1;
        for(int i = 0, j = 0; i < n; i = j) {
            while(j < n && a[i] == a[j]) ++j;
            if(j - i == 1) {
                ok = 0;
                break;
            }
            for(int k = i; k < j; ++k) {
                ans[k] = k + 1 == j ? i : k + 1;
            }
        }
        if(ok) {
            for(int i : ans) cout << i + 1 << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}