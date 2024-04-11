#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int k, n;

struct trie {
    trie *ch[2];
    int cnt;
    trie() {
        ch[0] = ch[1] = nullptr;
        cnt = 0;
    }
    void insert(int v, int d) {
        if (d < 0) return;
        int b = (v >> d) & 1;
        if (!ch[b]) ch[b] = new trie();
        ++ch[b]->cnt;
        ch[b]->insert(v, d - 1);
    }
    int query(int v, int d) {
        if (d < 0) return 0;
        int kb = (k >> d) & 1;
        int b = (v >> d) & 1;
        int ret = 0;
        if (kb == 1) {
            if (ch[b ^ 1]) ret += (d - 1 < 0 ? ch[b ^ 1]->cnt : ch[b ^ 1]->query(v, d - 1));
        } else {
            if (ch[b ^ 1]) ret += ch[b ^ 1]->cnt;
            if (ch[b]) ret += (d - 1 < 0 ? ch[b]->cnt : ch[b]->query(v, d - 1));
        }
        return ret;
    }
} *tr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long ans = 0;
    cin >> n >> k;
    int s = 0;
    tr = new trie();
    tr->insert(0, 31);
    for (int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        s ^= ai;
        ans += tr->query(s, 31);
        tr->insert(s, 31);
    }
    cout << ans << endl;
    return 0;
}