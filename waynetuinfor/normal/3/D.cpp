#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
int l[maxn], r[maxn];
bool chg[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    if ((s.size()) & 1) return cout << "-1" << endl, 0;
    int m = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') cin >> l[m] >> r[m], ++m;
    }
    int lb = 0, ub = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int p = 0;
    long long ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') ++lb, ++ub;
        else if (s[i] == ')') --lb, --ub;
        else --lb, ++ub, pq.emplace(l[p] - r[p], p), ++p;
        if (ub < 0) return cout << "-1" << endl, 0;
        if (lb < 0) lb += 2, ans += pq.top().first, chg[pq.top().second] = true, pq.pop();
    }
    if (lb > 0) return cout << "-1" << endl, 0;
    p = 0;
    string res = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            if (chg[p]) res += '(';
            else res += ')';
            ans += r[p];
            ++p;
            continue;
        }
        res += s[i];
    }
    cout << ans << endl;
    cout << res << endl;
    return 0;
}