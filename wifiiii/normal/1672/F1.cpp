#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(vector<int> a) {
    int n = a.size();
    auto ans = a;
    vector<int> cnt(n + 1);
    vector<vector<int>> pos(n + 1);
    set<int> res;
    for(int i = 0; i < n; ++i) {
        cnt[a[i]] += 1;
        pos[a[i]].push_back(i);
        res.insert(a[i]);
    }
    while(res.size() > 1) {
        int p = 1e9;
        vector<int> b;
        for(int x : res) {
            --cnt[x];
            b.push_back(pos[x].back()); pos[x].pop_back();
        }
        for(int i = 0; i < b.size(); ++i) {
            ans[b[i]] = a[b[(i + 1) % b.size()]];
        }
        auto it = res.begin();
        while(it != res.end()) {
            if(cnt[*it] == 0) {
                it = res.erase(it);
            } else {
                ++it;
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        auto ans = solve(a);
        for(int i : ans) cout << i << " "; cout << '\n';
    }
}