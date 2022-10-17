#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        map<int, vector<int>> pos;
        for(int i = 0; i < n; ++i) {
            pos[a[i]].push_back(i);
        }
        vector<int> ans(n);
        vector<int> res;
        for(auto p : pos) {
            if(p.second.size() >= k) {
                for(int i = 0; i < k; ++i) {
                    ans[p.second[i]] = i + 1;
                }
            } else {
                for(int i : p.second) {
                    res.push_back(i);
                }
            }
        }
        for(int i = 0; i < res.size() / k * k; ++i) {
            ans[res[i]] = i % k + 1;
        }
        for(int i : ans) cout << i << " ";
        cout << '\n';
    }
}