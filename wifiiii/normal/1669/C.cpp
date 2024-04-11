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
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ok = 1;
        for(int i = 0; i < 2; ++i) {
            for(int j = i; j < n; j += 2) {
                if(a[j] % 2 != a[i] % 2) ok = 0;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}