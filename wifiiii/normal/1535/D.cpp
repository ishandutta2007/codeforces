#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1 << 19 | 5;

string s;
int cnt[maxn], win[maxn];
int L[maxn], R[maxn];
void build(int l, int r, int rt) {
    L[rt] = l, R[rt] = r;
    if(l == r) {
        cnt[rt] = 1;
        return;
    }
    int m = (l + r) / 2;
    build(m + 1, r, rt << 1);
    build(l, m, rt << 1 | 1);
    char c = s[s.size() - rt];
    if(c == '1') {
        win[rt] = 1;
    } else if(c == '0') {
        win[rt] = 0;
    } else if(c == '?') {
        win[rt] = -1;
    }
    if(win[rt] == 1) {
        // right win
        cnt[rt] = cnt[rt << 1];
    } else if(win[rt] == 0) {
        // left win
        cnt[rt] = cnt[rt << 1 | 1];
    } else {
        // both
        cnt[rt] = cnt[rt << 1 | 1] + cnt[rt << 1];
    }
}
void update(int lx, int rx, char c, int l, int r, int rt) {
    int m = (l + r) / 2;
    if(lx == l && rx == r) {
        if(c == '1') {
            win[rt] = 1;
        } else if(c == '0') {
            win[rt] = 0;
        } else if(c == '?') {
            win[rt] = -1;
        }
    } else if(m >= rx) {
        update(lx, rx, c, l, m, rt<<1|1);
    } else {
        update(lx, rx, c, m+1, r, rt<<1);
    }
    if(win[rt] == 1) {
        // right win
        cnt[rt] = cnt[rt << 1];
    } else if(win[rt] == 0) {
        // left win
        cnt[rt] = cnt[rt << 1 | 1];
    } else {
        // both
        cnt[rt] = cnt[rt << 1 | 1] + cnt[rt << 1];
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k;
    cin >> k >> s;
    build(1, 1 << k, 1);
    int q;
    cin >> q;
    while(q--) {
        int p;
        cin >> p;
        p = (1 << k) - p;
        char c;
        cin >> c;
        update(L[p], R[p], c, 1, 1 << k, 1);
        cout << cnt[1] << '\n';
    }
}