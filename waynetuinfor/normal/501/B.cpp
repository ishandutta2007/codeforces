#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
string s[maxn];
map<string, string> mp, rmp;

int main() {
    int q; cin >> q;
    while (q--) {
        string a, b; cin >> a >> b;
        if (rmp.find(a) == rmp.end()) {
            mp[a] = b;
            rmp[b] = a;
            continue;
        }
        string to = rmp[a];
        mp[to] = b;
        rmp[b] = to;
        rmp.erase(a);
    }
    cout << mp.size() << endl;
    for (auto it : mp) cout << it.first << ' ' << it.second << endl;
}