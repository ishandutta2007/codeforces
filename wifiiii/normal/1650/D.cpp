#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), ans(n);
        for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
        for(int i = n - 1; i >= 0; --i) {
            int p = find(a.begin(), a.end(), i) - a.begin();
            rotate(a.begin(), a.begin() + p + 1, a.end());
            ans[i] = (p + 1) % (i + 1);
            a.pop_back();
        }
        for(int i : ans) cout << i << " "; cout << '\n';
    }
}