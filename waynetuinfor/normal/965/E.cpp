#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
char s[maxn];

struct trie {
    trie *ch[26];
    bool tag;
    trie() {
        for (int i = 0; i < 26; ++i) ch[i] = nullptr;
        tag = false;
    }
    void insert(char *s, int pos, int t) {
        if (pos == t) return tag = true, void();
        if (!ch[s[pos] - 'a']) ch[s[pos] - 'a'] = new trie();
        ch[s[pos] - 'a']->insert(s, pos + 1, t);
    }
    pair<long long, priority_queue<int>*> dfs(int dep) {
        priority_queue<int> *res = new priority_queue<int>();
        long long sum = 0;
        if (tag) res->push(dep), sum += dep;
        for (int i = 0; i < 26; ++i) if (ch[i]) {
            long long k;
            priority_queue<int> *pq;
            tie(k, pq) = ch[i]->dfs(dep + 1);
            sum += k;
            while (pq->size()) res->push(pq->top()), pq->pop();
        }
        if (!tag && dep > 0) {
            int t = res->top();
            sum -= t - dep;
            res->pop();
            res->push(dep);
        }
        return make_pair(sum, res);
    }
};

int main() {
    int n; scanf("%d", &n);
    trie *tr = new trie();
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        tr->insert(s, 0, strlen(s));
    }
    printf("%lld\n", tr->dfs(0).first);
}