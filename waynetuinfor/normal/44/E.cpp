#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10;
bool dp[maxn][maxn], v[maxn][maxn];
int t[maxn][maxn];
int k, a, b;

bool f(int div, int now) {
    if (v[div][now]) return dp[div][now];
    if (div == 0) {
        if (now == -1) return true;
        return false;
    }
    for (int i = a; i <= b; ++i) {
        if (now - i >= -1) {
            bool d = f(div - 1, now - i);
            if (d) t[div][now] = now - i, dp[div][now] = true;
        }
    }
    v[div][now] = true;
    return dp[div][now];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> k >> a >> b;
    string s; cin >> s;
    bool ans = f(k, s.length() - 1);
    if (!ans) return cout << "No solution" << endl, 0;
    int know = k, nnow = s.length() - 1;
    vector<pair<int, int>> ret;
    while (nnow >= 0) {
        ret.push_back(make_pair(t[know][nnow] + 1, nnow));
        nnow = t[know][nnow]; --know;
    }
    reverse(ret.begin(), ret.end());
    for (auto i : ret) {
        cout << s.substr(i.first, i.second - i.first + 1) << endl;
    }
    return 0;
}