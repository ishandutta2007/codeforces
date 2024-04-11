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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int l = 0, r = n - 1, ok = 1;
        auto chk = [&](int x) {
            vector<int> b;
            for(int i : a) if(i != x) b.push_back(i);
            int l = 0, r = b.size() - 1;
            while(l < r) {
                if(b[l] != b[r]) return 0;
                ++l, --r;
            }
            return 1;
        };
        while(l < r) {
            if(a[l] != a[r]) {
                if(chk(a[l])) ok = 1;
                else if(chk(a[r])) ok = 1;
                else ok = 0;
                break;
            }
            ++l, --r;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}