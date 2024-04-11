#include <bits/stdc++.h>
using namespace std;

long long ans;
int all;

map<tuple<vector<int>, bool, int>, long long> dp;

long long dfs(vector<int> c, bool d, int u) {
    if (dp.find(make_tuple(c, d, u)) != dp.end()) return dp[make_tuple(c, d, u)];
    long long r = 0;
    if (d && u == all) ++r;
    for (int i = 0; i < 10; ++i) if (c[i] > 0) {
        --c[i];
        if (i > 0) r += dfs(c, true, u | (1 << i));
        else r += dfs(c, false, u | (1 << i));
        ++c[i];
    } 
    return dp[make_tuple(c, d, u)] = r;
}

int main() {
    string s; cin >> s;
    vector<int> c(10);
    for (int i = 0; i < s.size(); ++i) ++c[s[i] - '0'];
    for (int i = 0; i < 10; ++i) if (c[i]) all ^= (1 << i);
    cout << dfs(c, false, 0) << endl;
}