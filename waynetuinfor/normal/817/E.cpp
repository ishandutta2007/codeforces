#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxd = 30;

struct trie {
    trie *ch[2];
    int cnt;
    trie() {
        ch[0] = ch[1] = nullptr;
        cnt = 0;
    }
    void insert(int v, int d) {
        if (d < 0) return;
        int b = v >> d & 1;
        if (!ch[b]) ch[b] = new trie();
        ++ch[b]->cnt;
        ch[b]->insert(v, d - 1);
    }
    void erase(int v, int d) {
        if (d < 0) return;
        int b = v >> d & 1;
        --ch[b]->cnt;
        ch[b]->erase(v, d - 1);
    }
    int query(int v, int p, int d) {
        if (d < 0) return 0;
        int bv = v >> d & 1, bp = p >> d & 1;
        if (bv == 0) {
            if (ch[bp] && ch[bp]->cnt > 0) return ch[bp]->query(v, p, d - 1);
            return 0;
        } else {
            int ret = 0;
            if (ch[bp]) ret += ch[bp]->cnt;
            if (ch[bp ^ 1] && ch[bp ^ 1]->cnt > 0) ret += ch[bp ^ 1]->query(v, p, d - 1); 
            return ret;
        }
    }
} *tr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    tr = new trie();
    int q; cin >> q; while (q--) {
        int t, p, l; cin >> t >> p;
        if (t == 1) tr->insert(p, maxd);
        if (t == 2) tr->erase(p, maxd);
        if (t == 3) cin >> l, cout << tr->query(l, p, maxd) << endl;
    }
    return 0;
}