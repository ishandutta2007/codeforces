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
        if(pow(3, n - 1) <= 1e9) {
            cout << "YES\n";
            vector<int> a(n, 1);
            for(int i = 1; i < n; ++i) a[i] = a[i - 1] * 3;
            for(int i = 0; i < n; ++i) cout << a[i] << ' '; cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}