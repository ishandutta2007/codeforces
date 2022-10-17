#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> l(q), r(q);
        for(int i = 0; i < q; ++i) cin >> l[i] >> r[i], --l[i], --r[i];
        vector<int> sum(n + 1);
        for(int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + (s[i] == '+' ? 1 : -1) * (i % 2 ? 1 : -1);
        }
        for(int i = 0; i < q; ++i) {
            if(sum[l[i]] == sum[r[i] + 1]) {
                cout << 0 << '\n';
            } else {
                cout << (r[i] - l[i]) % 2 + 1 << endl;
            }
        }
    }
}