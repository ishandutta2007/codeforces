#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n;
    cin >> n;

    stack<vector<int>> stk;
    stk.push({});

    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            auto v = stk.top();
            v.push_back(1);
            stk.push(v);
        }
        else {
            while (stk.top().back() != x - 1) {
                ans.push_back(stk.top());
                stk.pop();
            }
            auto v = stk.top();
            ans.push_back(v);
            stk.pop();
            v.pop_back();
            v.push_back(x);
            stk.push(v);
        }
    }

    while (size(stk) > 1) {
        ans.push_back(stk.top());
        stk.pop();
    }

    sort(all(ans));
    for (auto& v : ans) {
        cout << v[0];
        for (int i = 1; i < (int)size(v); ++i) {
            cout << "." << v[i];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    exit(0);
}