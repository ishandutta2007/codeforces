#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5, p[2] = { 131, 97 }, mod[2] = { 1000000123, 1000000087 };
vector<int> graf[maxn];
int c[maxn], ans, cans;
char s[maxn];

set<vector<int>> *dfs(int now, int fa, vector<int> hv) {
    for (int i = 0; i < 2; ++i) hv[i] = (hv[i] * 1ll * p[i] % mod[i] + s[now]) % mod[i];
    set<vector<int>> *s = new set<vector<int>>;
    s->insert(hv);
    for (int u : graf[now]) if (u != fa) {
        set<vector<int>> *r = dfs(u, now, hv);
        if (r->size() > s->size()) swap(r, s);
        while (r->size()) {
            s->insert(*(r->begin()));
            r->erase(r->begin());
        }
    }
    if (s->size() + c[now] > ans) ans = s->size() + c[now], cans = 1;
    else if (s->size() + c[now] == ans) ++cans;
    return s;
}

int main() { 
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", c + i);
    scanf("%s", s);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d %d", &a, &b); --a; --b;
        graf[a].push_back(b); graf[b].push_back(a);
    }
    dfs(0, -1, vector<int>(2, 0));
    printf("%d\n%d\n", ans, cans);
    return 0;
}