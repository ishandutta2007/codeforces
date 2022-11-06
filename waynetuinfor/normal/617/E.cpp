#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5, maxk = 1000000 + 5;
int n, m, k, a[maxn], s[maxn], cnt[maxk << 1];
long long ANS, ans[maxn];

struct Query {
    int L, R, block, i;
    bool operator<(const Query& rhs) const {
        return block == rhs.block ? R < rhs.R : block < rhs.block;
    }
} query[maxn];

void add(int);
void sub(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], s[i] = s[i - 1] ^ a[i];
    int lim = 1 + (int)sqrt(n);
    for (int i = 0; i < m; ++i) {
        cin >> query[i].L >> query[i].R; --query[i].L;
        query[i].block = query[i].L / lim;
        query[i].i = i;
    }
    sort(query, query + m);
    for (int i = 0, R = 0, L = 1; i < m; ++i) {
        while (R < query[i].R) add(++R);
        while (R > query[i].R) sub(R--);
        while (L < query[i].L) sub(L++);
        while (L > query[i].L) add(--L);
        ans[query[i].i] = ANS;
    }
    for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
    return 0;
}

void add(int x) {
    ANS += cnt[s[x] ^ k];
    ++cnt[s[x]];
}

void sub(int x) {
    --cnt[s[x]];
    ANS -= cnt[s[x] ^ k];
}