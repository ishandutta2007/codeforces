#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int K = 300002;
vector<int> pos[600005];
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
            pos[sum[i + 1] + K].push_back(i + 1);
        }
        for(int i = 0; i < q; ++i) {
            if(sum[l[i]] == sum[r[i] + 1]) {
                cout << 0 << '\n';
            } else {
                vector<int> ans;
                if((r[i] - l[i]) & 1) {
                    ans.push_back(r[i]);
                    --r[i];
                }
                if(l[i] == r[i]) {
                    ans.push_back(r[i]);
                    cout << ans.size() << '\n';
                    for(int x : ans) cout << x + 1 << " "; cout << '\n';
                    continue;
                }
                assert((r[i] - l[i]) % 2 == 0);
                int lo = l[i], hi = r[i] - 1, p;
                if(sum[r[i] + 1] > sum[l[i]]) p = sum[l[i]] + (sum[r[i] + 1] - sum[l[i]] + 1) / 2;
                else p = sum[l[i]] - (sum[l[i]] - sum[r[i] + 1] + 1) / 2;
                int y = *(lower_bound(pos[p + K].begin(), pos[p + K].end(), l[i])) - 1;
                ans.push_back(y);
                cout << ans.size() << '\n';
                for(int x : ans) cout << x + 1 << " "; cout << '\n';
            }
        }
        for(int i = 0; i < n; ++i) {
            pos[sum[i + 1] + K].clear();
        }
    }
}