#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int maxd = 17;
bool v[maxn];

struct trie {
    trie *ch[2];
    int minv;
    trie(): minv(maxn) { ch[0] = ch[1] = nullptr; }
    void insert(int v, int d = maxd) {
        if (d < 0) return;
        int b = v >> d & 1;
        if (!ch[b]) ch[b] = new trie();
        ch[b]->minv = min(ch[b]->minv, v);
        ch[b]->insert(v, d - 1);
    }
    int query(int v, int s, int d = maxd) {
        if (d < 0) return 0;
        int vb = v >> d & 1;
        int res = -maxn;
        if (ch[vb ^ 1] && ch[vb ^ 1]->minv + v <= s) res = max(res, (1 << d) + ch[vb ^ 1]->query(v, s, d - 1));
        else if (ch[vb] && ch[vb]->minv + v <= s) res = max(res, ch[vb]->query(v, s, d - 1));
        return res;
    }
} *tr[maxn];

int main() {
    for (int i = 0; i < maxn; ++i) tr[i] = new trie();
    int q; scanf("%d", &q);
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int x; scanf("%d", &x);
            if (v[x]) continue;
            v[x] = true;
            for (int i = 1; i * i <= x; ++i) if (x % i == 0) {
                tr[i]->insert(x);
                if (x / i != i) tr[x / i]->insert(x);
            }
        } else {
            int x, k, s; scanf("%d %d %d", &x, &k, &s);
            if (x % k != 0) {
                puts("-1");
                continue;
            }
            int res = tr[k]->query(x, s);
            if (res < 0) puts("-1");
            else printf("%d\n", (x ^ res));
        }
    }
    return 0;
}