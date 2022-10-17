#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int l, r; ll w;
    bool operator < (const node & n) const {
        return l < n.l;
    }
};
int cmp(const node &n1, const node &n2) {
    return n1.r < n2.r;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> stk1(n + 1), stk2(n + 1);
    int tp1 = 0, tp2 = 0;
    ll ans = 0;
    vector<vector<node>> segs1(60);
    vector<vector<node>> segs2(60);
    int cur = 0;
    auto lap = [&](int l1, int r1, int l2, int r2) {
        return max(0, min(r1, r2) - max(l1, l2) + 1);
    };
    auto calc = [&](int l, int r, vector<node> & seg) -> int {
        int p1 = lower_bound(seg.begin(), seg.end(), node{l, 0, 0}) - seg.begin();
        int p2 = upper_bound(seg.begin(), seg.end(), node{0, r, 0}, cmp) - seg.begin();
        int ans = 0;
        if(p1) ans += lap(l, r, seg[p1 - 1].l, seg[p1 - 1].r);
        if(p1 < seg.size()) ans += lap(l, r, seg[p1].l, seg[p1].r);
        if(p2 < seg.size() && p1 != p2 && p2 != p1 - 1) ans += lap(l, r, seg[p2].l, seg[p2].r);
        if(p1 < p2 - 1) {
            ans += seg[p2 - 1].w - seg[p1].w;
        }
        return ans;
    };
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        while(tp1 && a[stk1[tp1]] >= a[i]) --tp1;
        while(tp2 && a[stk2[tp2]] <= a[i]) --tp2;
        int mp = 0, Mp = 0;
        if(tp1) mp = stk1[tp1] + 1;
        if(tp2) Mp = stk2[tp2] + 1;
        stk1[++tp1] = i;
        stk2[++tp2] = i;
        int bits = __builtin_popcountll(a[i]);
        for(int j = 0; j < 60; ++j) {
            while(!segs1[j].empty() && segs1[j].back().r >= mp) {
                if(segs1[j].back().l >= mp) {
                    cur -= calc(segs1[j].back().l, segs1[j].back().r, segs2[j]);
                    segs1[j].pop_back();
                } else {
                    cur -= calc(segs1[j].back().l, segs1[j].back().r, segs2[j]);
                    ll d = mp - 1 - segs1[j].back().r;
                    segs1[j].back().r = mp - 1;
                    segs1[j].back().w += d;
                    cur += calc(segs1[j].back().l, segs1[j].back().r, segs2[j]);
                    break;
                }
            }
        }
        for(int j = 0; j < 60; ++j) {
            while(!segs2[j].empty() && segs2[j].back().r >= Mp) {
                if(segs2[j].back().l >= Mp) {
                    cur -= calc(segs2[j].back().l, segs2[j].back().r, segs1[j]);
                    segs2[j].pop_back();
                } else {
                    cur -= calc(segs2[j].back().l, segs2[j].back().r, segs1[j]);
                    ll d = Mp - 1 - segs2[j].back().r;
                    segs2[j].back().r = Mp - 1;
                    segs2[j].back().w += d;
                    cur += calc(segs2[j].back().l, segs2[j].back().r, segs1[j]);
                    break;
                }
            }
        }
        ll w1 = i - mp + 1;
        if(!segs1[bits].empty()) w1 += segs1[bits].back().w;
        ll w2 = i - Mp + 1;
        if(!segs2[bits].empty()) w2 += segs2[bits].back().w;
        segs1[bits].push_back({mp, i, w1});
        cur += calc(segs1[bits].back().l, segs1[bits].back().r, segs2[bits]);
        segs2[bits].push_back({Mp, i, w2});
        cur += calc(segs2[bits].back().l, segs2[bits].back().r, segs1[bits]);
        ans += cur;
    }
    cout << ans << '\n';
}