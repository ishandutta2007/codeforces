#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
char c[maxn];
int l[maxn], r[maxn], sz[maxn];

void debug(const vector<int> &buf) {
    for (int i : buf) cout << sz[i] << ' ' << l[i] << ' ' << r[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int p = 0;
    for (int i = 0; i < s.length(); ) {
        int j = i;
        ++p;
        while (j < s.length() && s[j] == s[i]) ++j;
        l[p] = p - 1; r[p] = p + 1;
        sz[p] = j - i;
        c[p] = s[i];
        i = j;
    }
    vector<int> buf(p); iota(buf.begin(), buf.end(), 1);
    int ans = 0;
    while (buf.size() > 1) {
        ++ans;
        // cout << "buf" << endl;
        // debug(buf);
        vector<int> nbuf;
        for (int i : buf) {
            if (l[i] > 0) --sz[i];
            if (r[i] <= p) --sz[i];
            if (sz[i] > 0) nbuf.push_back(i); 
        }
        // cout << "nbuf" << endl;
        // debug(nbuf);
        buf.clear();
        for (size_t i = 0; i < nbuf.size(); ) {
            size_t j = i;
            int tsz = 0;
            while (j < nbuf.size() && c[nbuf[j]] == c[nbuf[i]]) tsz += sz[nbuf[j]], ++j; 
            sz[nbuf[i]] = tsz;
            // l[nbuf[i]] = ;
            // r[nbuf]
            buf.push_back(nbuf[i]);
            i = j;
        }
        for (size_t i = 0; i < buf.size(); ++i) {
            l[buf[i]] = (i > 0 ? buf[i - 1] : 0);
            r[buf[i]] = (i + 1 < buf.size() ? buf[i + 1] : p + 1);
        }
    }
    cout << ans << endl;
    return 0;
}