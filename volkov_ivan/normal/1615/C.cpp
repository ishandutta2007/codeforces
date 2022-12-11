#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int INF = 1e9 + 7;

int solve_chet(string s, string t) {
    int ans = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '1' && t[i] == '0')
            ans++;
    }
    return 2 * ans;
}

int solve_nechet(string s, string t) {
    int pos = -1;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '1' && t[i] == '1') {
            pos = i;
            break;
        }
        if (s[i] == '1')
            pos = i;
    }
    assert(pos != -1);
    for (int i = 0; i < (int) s.size(); i++) {
        if (i != pos) {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }
    }
    return 1 + solve_chet(s, t);
}

int get_1(string &s) {
    int res = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '1')
            res++;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt1_s = get_1(s), cnt1_t = get_1(t);
    int res = INF;
    if (cnt1_s == cnt1_t)
        res = min(res, solve_chet(s, t));
    if (cnt1_s == n + 1 - cnt1_t)
        res = min(res, solve_nechet(s, t));
    cout << (res == INF ? -1 : res) << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}