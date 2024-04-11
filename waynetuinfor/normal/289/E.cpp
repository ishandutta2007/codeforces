#include <bits/stdc++.h>
using namespace std;

struct trie {
    trie *ch[2];
    int cnt;
    trie(): cnt(0) { ch[0] = ch[1] = nullptr; }
    void insert(int v, int d) {
        if (d < 0) return;
        int b = (v >> d) & 1;
        if (!ch[b]) ch[b] = new trie();
        ++ch[b]->cnt;
        ch[b]->insert(v, d - 1);
    }
    int query(int v, int d, int now) {
        if (d < 0) return now;
        int b = v >> d & 1;
        if (ch[b ^ 1] && ch[b ^ 1]->cnt > 0) return ch[b ^ 1]->query(v, d - 1, now + (1 << d));
        return ch[b]->query(v, d - 1, now);
    }
    void erase(int v, int d) {
        if (d < 0) return;
        int b = v >> d & 1;
        --ch[b]->cnt;
        ch[b]->erase(v, d - 1);
    }
} *tr;

const int maxn = 1e6 + 10;
int p[maxn];
int main() {
    int n; cin >> n;
    tr = new trie();
    long long ans = 0;
    for (int i = 0; i <= n; ++i) tr->insert(i, 20);
    for (int i = 0; i <= n; ++i) {
        int to = tr->query(i, 20, 0);
        p[i] = (i ^ to);
        ans += to;
        tr->erase((i ^ to), 20);
    }
    cout << ans << endl;
    for (int i = 0; i <= n; ++i) cout << p[i] << ' ' ; cout << endl;
}