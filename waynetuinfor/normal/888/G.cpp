#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, maxd = 30;
const int inf = (1 << 30) + 1;

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
    int query(int v, int d) {
        if (d < 0) return 0;
        int b = (v >> d ) & 1;
        if (ch[b] && ch[b]->cnt > 0) return ch[b]->query(v, d - 1);
        else return ch[b ^ 1]->query(v, d - 1) + (1 << d);
    }
} *tr;

long long solve(const vector<int> &a, int d) {
    if (d < 0 || a.size() == 0) return 0;
    vector<int> la, ra;
    for (int i : a) {
        if (i & (1 << d)) ra.push_back(i);
        else la.push_back(i);
    }
    long long ret = solve(la, d - 1) + solve(ra, d - 1);
    if (la.size() == 0 || ra.size() == 0) return ret;
    int edge = inf;
    for (int i : la) tr->insert(i, maxd);
    for (int i : ra) edge = min(edge, tr->query(i, maxd));
    for (int i : la) tr->erase(i, maxd);
    return ret + edge;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    tr = new trie(); 
    cout << solve(a, maxd) << endl;
    return 0;
}