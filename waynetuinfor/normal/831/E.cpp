#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
vector<int> pos[maxn];

struct Seg {
    Seg *lc, *rc;
    int sum, tag;
#define M ((L + R) >> 1)
    Seg (int L, int R) {
        lc = rc = nullptr;
        sum = 0; tag = 0;
        if (L == R) {
            sum = 1; return;
        }
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
        pull();
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    void push(int L, int R) {
        if (L == R || !tag) return;
        lc->sum += (M - L + 1) * tag; lc->tag += tag; 
        rc->sum += (R - M) * tag; rc->tag += tag;
        tag = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R)return;
        if (L >= l && R <= r) {
            sum += (R - L + 1) * v; sum = max(sum, 0);
            tag += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]].push_back(i);
    st = new Seg(1, n);
    long long ans = 0;
    int ptr = 0;
    for (int i = 1; i < maxn; ++i) {
        if (pos[i].size()  == 0) continue;
        int ind = lower_bound(pos[i].begin(), pos[i].end(), ptr) - pos[i].begin();
        for (int j = 0; j < pos[i].size(); ++j) {
            if (ind == pos[i].size()) ind = 0;
            if (ptr < pos[i][ind]) ans += st->query(1, n, ptr + 1, pos[i][ind]);
            else ans += st->query(1, n, 1, n) - st->query(1, n, pos[i][ind] + 1, ptr);
            st->modify(1, n, pos[i][ind], pos[i][ind], -1);
            ptr = pos[i][ind]; ++ind;
        }
    }
    cout << ans << endl;
    return 0;
}