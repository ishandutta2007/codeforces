#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
string s;

struct Seg {
    static Seg mem[maxn << 1];
    static int top;
    struct ptr {
        ptr() {}
        ptr(const Seg* s): c(s - mem) {}
        int c;
        Seg* operator->() { return mem + c; }
    } lc, rc;
    void* operator new(size_t x) { return mem + top++; }
    int cnt[26], tag;
    Seg() {}
    Seg(int L, int R) {
        tag = -1;
        if (L == R) {
            memset(cnt, 0, sizeof(cnt));
            cnt[s[L] - 'a']++;
            return;
        }
        int M = (L + R) >> 1;
        lc = new Seg(L, M), rc = new Seg(M + 1, R);
        pull();
    }
    void pull() {
        for (int i = 0; i < 26; ++i) cnt[i] = lc->cnt[i] + rc->cnt[i]; 
    }
    int query(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return cnt[v];
        int M = (L + R) >> 1;
        return lc->query(L, M, l, r, v) + rc->query(M + 1, R, l, r, v);
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            memset(cnt, 0, sizeof(cnt));
            cnt[v] = R - L + 1;
            tag = v;
            return;
        }
        int M = (L + R) >> 1;
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    void push(int L, int R) {
        if (L == R) return;
        if (tag == -1) return;
        int M = (L + R) >> 1;
        memset(lc->cnt, 0, sizeof(lc->cnt)), lc->cnt[tag] = M - L + 1, lc->tag = tag;
        memset(rc->cnt, 0, sizeof(rc->cnt)), rc->cnt[tag] = R - M, rc->tag = tag;
        tag = -1;
    }
    void print(int L, int R) {
        push(L, R);
        if (L == R) {
            for (int i = 0; i < 26; ++i) if (cnt[i]) cout << (char)('a' + i);
            return;
        }
        int M = (L + R) >> 1;
        lc->print(L, M);rc->print(M + 1, R);
    }
} Seg::mem[maxn << 1];

int Seg::top = 0;
Seg::ptr st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    cin >> s;
    st = new Seg(0, n - 1);
    while (q--) {
        int l, r, k; cin >> l >> r >> k; --l, --r;
        vector<int> cnt;
        for (int i = 0; i < 26; ++i) cnt.push_back(st->query(0, n - 1, l, r, i));
        if (k) {
            int ind = l;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] == 0) continue;
                st->modify(0, n - 1, ind, ind + cnt[i] - 1, i);
                ind += cnt[i];
            }
        } else {
            int ind = l;
            for (int i = 25; i >= 0; --i) {
                if (cnt[i] == 0) continue; 
                st->modify(0, n - 1, ind, ind + cnt[i] - 1, i);
                ind += cnt[i];
            }
        }
    }
    st->print(0, n - 1); cout << '\n';
    return 0;
}