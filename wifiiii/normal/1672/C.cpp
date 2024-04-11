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
        int l = -1, r = -1;
        for(int i = 0; i + 1 < n; ++i) {
            if(a[i] == a[i + 1]) {
                if(l == -1) l = i;
                r = i;
            }
        }
        if(l == r) {
            cout << 0 << '\n';
        } else {
            cout << max(1, r - l - 1) << '\n';
        }
    }
}