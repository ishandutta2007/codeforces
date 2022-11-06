#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
string s[maxn];
map<string, int> id;
int p[maxn << 1];
vector<pair<int, string>> G[maxn << 1];
int out[maxn << 1], in[maxn << 1];
vector<string> ret;

void dfs(int now, string t) {
    for (; p[now] < G[now].size(); ) {
        int go = G[now][p[now]].first;
        string s = G[now][p[now]].second;
        ++p[now];
        dfs(go, s);
    }
    if (t.length() > 0) ret.push_back(t);
}

int get(const string& t) {
    if (id.find(t) == id.end()) id[t] = id.size();
    return id[t];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int st;
    for (int i = 0; i < n; ++i) {
        int a = get(s[i].substr(0, 2));
        int b = get(s[i].substr(1, 2));
        ++out[a]; ++in[b];
        G[a].emplace_back(b, s[i]);
        st = a;
    } 
    int en = 0, ex = 0;
    for (auto it = id.begin(); it != id.end(); ++it) {
        int a = it->second;
        if (in[a] == out[a]) continue;
        if (in[a] - out[a] == 1) ++ex;
        else if (out[a] - in[a] == 1) ++en, st = a;
        else return cout << "NO" << endl, 0;
    }
    if (en == ex && en <= 1) {
        dfs(st, "");
        if (ret.size() == n) {
            reverse(ret.begin(), ret.end());
            string ans = ret[0];
            for (int i = 1; i < ret.size(); ++i) ans += ret[i][2];
            cout << "YES" << endl;
            cout << ans << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}