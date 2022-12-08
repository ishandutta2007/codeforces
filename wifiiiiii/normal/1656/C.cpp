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
        int c1 = 0;
        for(int i : a) {
            if(i == 1) {
                c1 = 1;
            }
        }
        if(c1 == 0) {
            cout << "YES\n";
            continue;
        }
        int ok = 1;
        for(int i = 1; i < n; ++i) {
            if(a[i] - a[i - 1] == 1) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}