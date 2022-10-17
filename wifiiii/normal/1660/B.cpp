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
        sort(a.begin(), a.end());
        if(n == 1) {
            cout << (a[0] == 1 ? "YES" : "NO") << '\n';
        } else {
            cout << (a[n - 1] - a[n - 2] <= 1 ? "YES" : "NO") << '\n';
        }
    }
}