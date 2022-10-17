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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = n & 1; i < n; i += 2) {
            if(a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
        cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
    }
}