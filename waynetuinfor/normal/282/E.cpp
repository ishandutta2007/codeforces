#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxdep = 40;
long long a[maxn], s[maxn];

struct Trie {
    Trie *ch[2];
    int cnt;
    Trie(): cnt(0) {
        ch[0] = ch[1] = nullptr;
    }
    void insert(long long v, int dep) {
        if (dep < 0) return;
        int bit = ((1ll << dep) & v) >> dep;
        if (!ch[bit]) ch[bit] = new Trie();
        ch[bit]->cnt++;
        ch[bit]->insert(v, dep - 1);
    }
    void erase(long long v, int dep) {
        if (dep < 0) return;
        int bit = ((1ll << dep) & v) >> dep;
        ch[bit]->cnt--;
        ch[bit]->erase(v, dep - 1);
    }
    long long query(long long v, int dep) {
        if (dep < 0) return 0;
        int bit = ((1ll << dep) & v) >> dep;
        if (ch[bit ^ 1] && ch[bit ^ 1]->cnt > 0) return (1ll << dep) + ch[bit ^ 1]->query(v, dep - 1);
        else return ch[bit]->query(v, dep - 1);
    }
} *tr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    tr = new Trie();
    tr->insert(0, maxdep);
    for (int i = n; i >= 1; --i) s[i] = s[i + 1] ^ a[i], tr->insert(s[i], maxdep);
    long long cur = 0, ans = tr->query(0, maxdep);
    for (int i = 1; i <= n; ++i) {
        cur ^= a[i]; tr->erase(s[i], maxdep);
        ans = max(ans, tr->query(cur, maxdep));
    }
    cout << ans << endl;
    return 0;
}