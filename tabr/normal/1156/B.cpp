#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using P = pair<ll, int>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<string> abc(26);
        rep(i, 0, s.size()) abc[s[i] - 'a'].push_back(s[i]);
        sort(abc.begin(), abc.end());
        abc.erase(unique(abc.begin(), abc.end()), abc.end());
        string u, v;
        rep(i, 0, abc.size()) {
            if (i % 2)
                u = u + abc[i];
            else
                v = v + abc[i];
        }
        string w = u + v;
        v = v + u;
        rep(i, 0, v.size() - 1) if (abs(v[i] - v[i + 1]) == 1) {
            v = "No answer";
            break;
        }
        rep(i, 0, w.size() - 1) if (abs(w[i] - w[i + 1]) == 1) {
            w = "No answer";
            break;
        }
        if (v == "No answer")
            cout << w << endl;
        else
            cout << v << endl;
    }
    return 0;
}