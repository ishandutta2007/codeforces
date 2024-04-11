#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            while(a[i] % 2 == 0) {
                a[i] /= 2;
                cnt++;
            }
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < cnt; ++i) {
            a[n-1] = a[n-1] * 2;
        }
        cout << accumulate(a.begin(), a.end(), 0ll) << '\n';
    }
}