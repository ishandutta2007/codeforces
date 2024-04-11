#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int p[maxn];
stack<int> s;
set<int> st;
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; ++i) cin >> p[i], v[p[i]] = true;
    int to = 1;
    for (int i = 1; i <= k; ++i) {
        while (s.size() && s.top() == to) st.erase(s.top()), s.pop(), ++to;
        s.push(p[i]);
        st.insert(p[i]);
    }
    while (s.size() && s.top() == to) st.erase(s.top()), s.pop(), ++to;
    vector<int> vec;
    for (int i = 1; i <= n; ++i) if (!v[i]) vec.push_back(i);
    int ind = 0;
    vector<int> ans;
    // cout << "s.size() = " << s.size() << endl;
    while (s.size() && ind < vec.size()) {
        // cout << "bang" << endl;
        vector<int> goal;
        while (ind < vec.size() && vec[ind] < *st.begin()) {
            goal.push_back(vec[ind]);
            // s.push(vec[ind]);
            ++ind;
        }
        if (!goal.size()) break;
        for (int i = goal.size() - 1; i >= 0; --i) ans.push_back(goal[i]), s.push(goal[i]);
        while (s.size() && s.top() == to) {
            // cout << "top = " << s.top() << endl;
            if (v[s.top()]) st.erase(s.top());
            s.pop();
            ++to;
        }
    }
    while (ind < vec.size()) {
        vector<int> goal;
        while (ind < vec.size()) {
            goal.push_back(vec[ind]);
            ++ind;
        }
        for (int i = goal.size() - 1; i >= 0; --i) ans.push_back(goal[i]);
    }
    if (s.size()) return cout << "-1" << endl, 0;
    for (int i = 1; i <= k; ++i) cout << p[i] << ' ';
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}