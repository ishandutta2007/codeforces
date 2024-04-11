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
        auto solve1 = [&](vector<int> a) -> vector<int> {
            deque<int> ans;
            int l = 0, r = n - 1;
            while(l < r) {
                if(a[l] < a[r]) ans.push_front(a[l]), ++l;
                else ans.push_back(a[r]), --r;
            }
            ans.push_front(a[r]);
            return vector<int>(ans.begin(), ans.end());
        };
        auto solve2 = [&](vector<int> a) -> vector<int> {
            deque<int> ans;
            int l = 0, r = n - 1;
            while(l < r) {
                if(a[l] < a[r]) ans.push_front(a[l]), ++l;
                else ans.push_back(a[r]), --r;
            }
            ans.push_back(a[r]);
            return vector<int>(ans.begin(), ans.end());
        };
        auto ans = solve1(a);
        if(solve1(ans) != a && solve2(ans) != a) cout << -1;
        else for(int i : ans) cout << i << " ";
        cout << '\n';
    }
}