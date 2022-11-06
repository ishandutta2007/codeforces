#include <bits/stdc++.h>
using namespace std;

const int maxn = 60 + 5;
map<pair<int, long long>, int> dp;

int go(int now, long long s) {
    if (now == 0) return 0;
    if (dp.find(make_pair(now, s)) != dp.end()) return dp[make_pair(now, s)];
    vector<int> sg;
    for (int i = 0; i < now; ++i) if ((1ll << i) & s) {
        sg.push_back(go(now - i - 1, s ^ (1ll << i)));
    } 
    sort(sg.begin(), sg.end());
    size_t ptr = 0;
    for (int i = 0; ; ++i) {
        bool f = false;
        while (ptr < sg.size() && sg[ptr] == i) ++ptr, f = true;
        if (!f) return dp[make_pair(now, s)] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int sg = 0;
    int n; cin >> n; while (n--) {
        int s; cin >> s;
        sg ^= go(s, (1ll << s) - 1);
    }
    cout << (sg ? "NO" : "YES") << endl;
    return 0;
}