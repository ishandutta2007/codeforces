#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int p = min_element(a.begin(), a.end()) - a.begin();
        vector<int> aa(n);
        aa[p] = a[p];
        for(int i = p + 1; i < n; ++i) aa[i] = aa[i-1] + 1;
        for(int i = p - 1; i >= 0; --i) aa[i] = aa[i+1] + 1;
        cout << n - 1 << '\n';
        for(int i = 0; i < n; ++i) {
            if(i == p) continue;
            cout << i + 1 << " " << p + 1 << " " << aa[i] << " " << aa[p] << '\n';
        }
    }
}