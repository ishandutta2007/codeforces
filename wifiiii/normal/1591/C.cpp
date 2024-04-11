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
        vector<int> pos {0}, neg {0};
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x > 0) pos.push_back(x);
            else if(x < 0) neg.push_back(-x);
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        auto solve = [&](vector<int> a) -> ll {
            if(a.empty()) return 0;
            ll sum = 0;
            for(int i = a.size() - 1; i >= 0; i -= k) {
                sum += a[i] * 2;
            }
            return sum;
        };
        cout << solve(pos) + solve(neg) - max(pos.back(), neg.back()) << endl;
    }
}