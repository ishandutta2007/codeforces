#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

const int V = 52 * (1 << 10);
const int B = 1 << 10;
const int INF = 1e9;

string s;
map<char, int> num;
int was[52], prv[V], dp[V], calc[V];
vector<int> go[V];
vector<int> pos[10][52];

int calculate(int v) {
    if (dp[v] < 0 || calc[v]) return dp[v];

    calc[v] = 1;
    for (int u : go[v]) {
        if (ckmax(dp[v], calculate(u) + 1)) prv[v] = u;
    }

    return dp[v];
}

void solve() {
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        fill(was, was+52, 0);
        string s; cin >> s;

        for (int j = 0; j < 52; ++j) pos[i][j].clear();
        for (int j = 0; j < s.size(); ++j) {
            // cout << "pos " << i << " " << j << " => " << num[s[j]] << endl;
            pos[i][num[s[j]]].push_back(j);
        }
    }

    fill(dp, dp+V, -INF);
    fill(prv, prv+V, -1);
    fill(calc, calc+V, 0);

    for (int i = 0; i < V; ++i) go[i].clear();

    for (int a = 0; a < 52; ++a) {
        for (int msk = 0; msk < (1 << n); ++msk) {
            bool exist = true;
            vector<int> loc(n);
            for (int i = 0; i < n; ++i) {
                if (((msk >> i) & 1) >= pos[i][a].size()) {
                    exist = false;
                    break;
                }

                loc[i] = pos[i][a][(msk >> i) & 1];
            }

            if (exist) {
                int v = (a << 10) + msk;

                // cerr << "vertex, v = " << v << endl;
                dp[v] = 1;

                for (int b = 0; b < 52; ++b) {
                    int nmsk = 0;
                    bool exist = true;
                    for (int i = 0; i < n; ++i) {
                        if (pos[i][b].empty()) { exist = false; break; }

                        if (pos[i][b][0] <= loc[i]) {
                            if (pos[i][b].size() == 1 || pos[i][b][1] <= loc[i]) { exist = false; break; }
                            nmsk |= 1 << i;
                        }
                    }

                    if (exist) {
                        go[v].push_back((b << 10) + nmsk);
                        // cerr << v << " --> " << (b << 10) + nmsk << endl;
                    }
                }
            }
        }
    }

    int len = 0, v0 = -1;
    for (int i = 0; i < V; ++i) {
        if (ckmax(len, calculate(i))) v0 = i;
    }

    cout << len << endl;

    string ans = "";
    while (v0 != -1) {
        ans.push_back(s[v0 >> 10]);
        v0 = prv[v0];
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    for (char c = 'a'; c <= 'z'; ++c) s.push_back(c);
    for (char c = 'A'; c <= 'Z'; ++c) s.push_back(c);
    for (int i = 0; i < 52; ++i) num[s[i]] = i;

    int t; cin >> t;
    while (t--) {
        solve();
    }
}