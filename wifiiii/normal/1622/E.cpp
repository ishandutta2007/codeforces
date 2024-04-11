#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<string> b(n);
        for(int i = 0; i < n; ++i) cin >> b[i];
        vector<int> ans;
        ll mx = -1;
        for(int i = 0; i < 1 << n; ++i) {
            ll surprise = 0;
            vector<int> weight(m);
            for(int j = 0; j < n; ++j) {
                if(i >> j & 1) {
                    for(int k = 0; k < m; ++k) {
                        if(b[j][k] == '1') weight[k] += 1;
                    }
                    surprise -= a[j];
                } else {
                    for(int k = 0; k < m; ++k) {
                        if(b[j][k] == '1') weight[k] -= 1;
                    }
                    surprise += a[j];
                }
            }
            vector<int> ord(m), r(m);
            iota(ord.begin(), ord.end(), 0);
            sort(ord.begin(), ord.end(), [&](int i, int j) {return weight[i] < weight[j];});
            for(int j = 0; j < m; ++j) {
                r[ord[j]] = j;
                surprise += (j + 1) * weight[ord[j]];
            }
            if(surprise > mx) {
                mx = surprise;
                ans = r;
            }
        }
        for(int i : ans) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }
}