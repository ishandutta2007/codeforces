#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int a[maxn], p[maxn];

struct trie {
    trie *ch[2];
    int cnt;
    trie(): cnt(0) { ch[0] = ch[1] = nullptr; }
    void insert(int v, int d = 30) {
         if (d < 0) return;
         int b = v >> d & 1;
         if (!ch[b]) ch[b] = new trie();
         ++ch[b]->cnt;
         ch[b]->insert(v, d - 1);
    }
    void erase(int v, int d = 30) {
        if (d < 0) return;
        int b = v >> d & 1;
        --ch[b]->cnt;
        ch[b]->erase(v, d - 1);
    }
    int query(int v, int offset, int d = 30) {
        if (d < 0) return offset;
        int b = v >> d & 1;
        if (ch[b] && ch[b]->cnt > 0) return ch[b]->query(v, offset, d - 1);
        else return ch[b ^ 1]->query(v, offset + (1 << d), d - 1);
    }
} *tr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    tr = new trie();
    for (int i = 1; i <= n; ++i) tr->insert(p[i]);
    for (int i = 1; i <= n; ++i) {
        int v = tr->query(a[i], 0);
        cout << v << ' ';
        tr->erase(a[i] ^ v);
    }
    cout << endl;
    return 0;
}