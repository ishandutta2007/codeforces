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
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        ll sum = 0;
        for(int i = 0; i < n - 1; ++i) {
            sum += a[i];
        }
        cout << fixed << setprecision(10) << 1.0 * sum / (n - 1) + a.back() << endl;
    }
}