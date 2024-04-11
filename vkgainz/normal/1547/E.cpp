#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<pair<int, int>> in(k);
        for(int i = 0; i < k; i++) {
            cin >> in[i].first;
        }
        for(int i = 0; i < k; i++) {
            cin >> in[i].second;
        }
        multiset<int> l, r;
        vector<pair<int, int>> ord(k);
        for(int i = 0; i < k; i++)
            ord[i] = in[i];
        sort(ord.begin(), ord.end());
        reverse(ord.begin(), ord.end());
        for(int i = 0; i < k; i++)
            r.insert(in[i].second + in[i].first);
        vector<int> ans(n);
        for(int i = 1; i <= n; i++) {
            while(!ord.empty() && ord.back().first <= i) {
                r.erase(r.lower_bound(ord.back().first + ord.back().second));
                l.insert(ord.back().second - ord.back().first);
                ord.pop_back();
            }
            if(l.empty())
                ans[i - 1] = *r.begin() - i;
            else if(r.empty())
                ans[i - 1] = *l.begin() + i;
            else
                ans[i - 1] = min(*r.begin() - i, *l.begin() + i);
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}