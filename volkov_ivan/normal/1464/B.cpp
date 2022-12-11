#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7, INF = 1e18;
int pref_0[N];
int pref_1[N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    int n = s.size();
    if (x > y) {
        swap(x, y);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                s[i] = '1';
            else if (s[i] == '1')
                s[i] = '0';
        }
    }
    int all_0 = 0, all_1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            all_0++;
        else if (s[i] == '1')
            all_1++;
    }
    s = "." + s;
    vector <int> pos_q;
    vector <int> cost_zero, cost_one;
    pref_0[0] = pref_1[0] = 0;
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        pref_0[i] = pref_0[i - 1];
        pref_1[i] = pref_1[i - 1];
        if (s[i] == '?') {
            pos_q.push_back(i);
            cost_zero.push_back(y * pref_1[i] + x * (all_1 - pref_1[i]));
            cost_one.push_back(x * pref_0[i] + y * (all_0 - pref_0[i]));
            cur += cost_zero.back();
            continue;
        }
        if (s[i] == '0') {
            pref_0[i]++;
            ans += y * pref_1[i];
        } else {
            pref_1[i]++;
            ans += x * pref_0[i];
        }
    }
    if (pos_q.empty()) {
        cout << ans << endl;
        return 0;
    }
    int mini = INF;
    int sz = pos_q.size();
    for (int cnt_zero = sz; cnt_zero >= 0; cnt_zero--) {
        mini = min(mini, cur + (cnt_zero * (sz - cnt_zero)) * x);
        if (cnt_zero == 0)
            break;
        cur -= cost_zero[cnt_zero - 1];
        cur += cost_one[cnt_zero - 1];
    }
    cout << ans + mini << endl;
}