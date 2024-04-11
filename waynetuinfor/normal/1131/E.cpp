#include <bits/stdc++.h>
using namespace std;

struct data {
    int lc, rc;
    long long sz, lans, rans, ans;
    data(): ans(0), sz(0), lans(0), rans(0), lc(0), rc(0) {}
    data(int x): lc(x), rc(x), lans(1), rans(1), ans(1), sz(1) {}
    data(const string &s) {
        lc = s[0] - 'a', rc = s[(int)s.size() - 1] - 'a';
        sz = (int)s.size();
        ans = 0;
        for (int i = 0; i < (int)s.size(); ) {
            int j = i;
            while (j < (int)s.size() && s[j] == s[i])
                ++j;
            ans = max(ans, (long long)j - i);
            if (i == 0)
                lans = j;
            if (j == sz)
                rans = j - i;
            i = j;
        }
    }
    data operator+(const data &d) const {
        data res;
        res.sz = sz + d.sz;
        res.lc = lc, res.rc = d.rc;
        res.lans = lans == sz && lc == d.lc ? lans + d.lans : lans;
        res.rans = d.rans == d.sz && rc == d.rc ? d.rans + rans : d.rans;
        res.ans = max(ans, d.ans);
        res.ans = max(res.ans, max(res.lans, res.rans));
        if (rc == d.lc)
            res.ans = max(res.ans, rans + d.lans);
        return res;
    }
    friend ostream &operator<<(ostream &s, const data &d) {
        s << "lc = " << d.lc << " rc = " << d.rc << " lans = " << d.lans << 
             " rans = " << d.rans << " ans = " << d.ans << " sz = " << d.sz;
        return s;
    }
};

const int maxn = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    reverse(s.begin(), s.end());
    data d = data(s[0]);
    for (int i = 1; i < n; ++i) {
        data e = d;
        for (int j = 0; j < (int)s[i].size(); ++j) {
            e = e + data(s[i][j] - 'a');
            e = e + d;
        }
        d = e;
    }
    cout << d.ans << endl;
}