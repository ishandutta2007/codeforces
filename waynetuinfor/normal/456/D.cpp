#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

struct trie {
    trie *ch[26];
    int cnt, sg1, sg2;
    trie() {
        for (int i = 0; i < 26; ++i) ch[i] = nullptr;
        cnt = 0;
    }
    void insert(const string& s, size_t ptr) {
        if (ptr == s.length()) return;
        if (!ch[s[ptr] - 'a']) ch[s[ptr] - 'a'] = new trie();
        ++ch[s[ptr] - 'a']->cnt;
        ch[s[ptr] - 'a']->insert(s, ptr + 1);
    }
} *tr;

pair<int, int> go(trie* t) {
    bool hasch = false;
    for (int i = 0; i < 26; ++i) hasch |= (t->ch[i] != nullptr);
    if (!hasch) return make_pair(0, 1);
    pair<int, int> ret = make_pair(0, 0);
    for (int i = 0; i < 26; ++i) if (t->ch[i] && t->ch[i]->cnt) {
        pair<int, int> p = go(t->ch[i]);
        ret.first |= (!p.first);
        ret.second |= (!p.second);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    tr = new trie();
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        tr->insert(s, 0);
    }
    int w, l;
    tie(w, l) = go(tr);
    if (w == 0) cout << "Second" << endl;
    else if (w == 1 && l == 1) cout << "First" << endl;
    else cout << (k % 2 == 0 ? "Second" : "First") << endl;
    return 0;
}