#include <bits/stdc++.h>

const int N = 200010;
const int MAX = 1 << 18;
using ll = long long;
using pii = std::pair <int, int>;

struct Segment{
    int mex;
    int l, r;
    int id;

    bool operator <(const Segment &s)const{
        return mex < s.mex;
    }
};

struct Rectangle{
    int xl, xr, yl, yr;
    ll prel1, prel2, prer1, prer2;
    int id;

    Rectangle():xl(0), xr(0), yl(0), yr(0), prel1(0), prel2(0), prer1(0), prer2(0), id(0){}
};

std::set <pii> setxl[N], setxr[N], setyl[N], setyr[N];
int seg[MAX << 1];
int first[N];
std::vector <Rectangle> rec[N];

void erase(std::set <Segment> &set, std::set <Segment>::iterator it, int pos, bool to_erase = true){
    Rectangle rect;
    rect.xl = it -> l, rect.xr = it -> r;
    rect.yl = it -> id, rect.yr = pos - 1;
    rect.id = rec[it -> mex].size();
    int mex = it -> mex;
    setxl[mex].emplace(rect.xl, rect.id);
    setxr[mex].emplace(rect.xr, rect.id);
    setyl[mex].emplace(rect.yl, rect.id);
    setyr[mex].emplace(rect.yr, rect.id);
    Rectangle pre = rec[it -> mex].empty() ? Rectangle() : rec[it -> mex].back();
    int len = pos - it -> id;
    rect.prel1 = pre.prel1 + len;
    rect.prel2 = pre.prel2 + 1ll * len * rect.xl;
    rect.prer1 = pre.prer1 + len;
    rect.prer2 = pre.prer2 + 1ll * len * (rect.xr + 1);
    rec[it -> mex].push_back(rect);
    if (to_erase){
        set.erase(it);
    }
}

pii calc(const std::set <pii> &setl, const std::set <pii> &setr, int l, int r){
    int n = setl.size();
    auto u = setr.lower_bound({l, INT_MIN});
    int left = u == setr.end() ? n : u -> second;
    u = setl.lower_bound({r + 1, INT_MIN});
    int right = u == setl.end() ? n : u -> second;
    return {left, right - 1};
}

ll inter(Rectangle r1, Rectangle r2){
    int xl = std::max(r1.xl, r2.xl);
    int xr = std::min(r1.xr, r2.xr);
    int yl = std::max(r1.yl, r2.yl);
    int yr = std::min(r1.yr, r2.yr);
    return 1ll * (xr - xl + 1) * (yr - yl + 1);
}

void add(int sit, int value){
    seg[sit += MAX] = value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
    }
}

int query(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return -1;
    }
    if (seg[sit] >= value){
        return -1;
    }
    if (l == r){
        return l;
    }
    int mid = (l + r) / 2;
    int ret = query(sit << 1, l, mid, ql, qr, value);
    if (ret != -1){
        return ret;
    }
    return query(sit << 1 | 1, mid + 1, r, ql, qr, value);
}

int main(){
    ll last = 0;
    int n;
    scanf("%d", &n);
    std::set <Segment> set;
    for (int pos = 1; pos <= n; ++ pos){
        int a, l, r, k;
        scanf("%d%d%d%d", &a, &l, &r, &k);
        a = (a + last) % (n + 1);
        l = (l + last) % pos + 1;
        r = (r + last) % pos + 1;
        if (l > r){
            std::swap(l, r);
        }
        k = (k + last) % (n + 1);
        auto u = set.lower_bound({a, 0, 0, 0});
        add(a, pos);
        if (u != set.end() && u -> mex == a){
            int l = u -> l, r = u -> r;
            erase(set, u, pos);
            while (r >= l){
                int mex = query(1, 0, MAX - 1, 0, n, r);
                int left = seg[mex + MAX] + 1;
                u = set.find({mex, 0, 0, 0});
                int l1 = left, r1 = r;
                if (u != set.end()){
                    l1 = u -> l;
                    erase(set, u, pos);
                }
                set.insert({mex, l1, r1, pos});
                r = left - 1;
            }
        }
        int nmex = a ? 0 : 1;
        if (!set.empty() && set.begin() -> mex == nmex){
            int l = set.begin() -> l;
            erase(set, set.begin(), pos);
            set.insert({nmex, l, pos, pos});
        }
        else{
            set.insert({nmex, pos, pos, pos});
        }
        u = set.lower_bound({k, 0, 0, 0});
        bool has_tmp = false;
        if (u != set.end() && u -> mex == k){
            has_tmp = true;
            erase(set, u, pos + 1, false);
        }
        pii p1 = calc(setxl[k], setxr[k], l, r);
        pii p2 = calc(setyl[k], setyr[k], l, r);
        int left = std::max(p1.first, p2.first);
        int right = std::min(p1.second, p2.second);
        if (left > right){
            last = 0;
        }
        else{
            Rectangle now;
            now.xl = now.yl = l, now.xr = now.yr = r;
            if (left == right){
                last = inter(rec[k][left], now);
            }
            else{
                last = inter(rec[k][left], now) + inter(rec[k][right], now);
                ++ left, -- right;
                if (left <= right){
                    auto v = setxl[k].lower_bound({l, INT_MIN});
                    int lpos = right + 1;
                    if (v != setxl[k].end()){
                        lpos = std::min(lpos, v -> second);
                        lpos = std::max(left, lpos);
                    }
                    last -= l * (rec[k][lpos - 1].prel1 - rec[k][left - 1].prel1);
                    last -= rec[k][right].prel2 - rec[k][lpos - 1].prel2;
                    v = setxr[k].lower_bound({r, INT_MIN});
                    int rpos = right + 1;
                    if (v != setxr[k].end()){
                        rpos = std::min(rpos, v -> second);
                        rpos = std::max(rpos, left);
                    }
                    last += rec[k][rpos - 1].prer2 - rec[k][left - 1].prer2;
                    last += (r + 1) * (rec[k][right].prer1 - rec[k][rpos - 1].prer1);
                }
            }
        }
        printf("%lld\n", last);
        if (has_tmp){
            Rectangle rect = rec[k].back();
            rec[k].pop_back();
            setxl[k].erase({rect.xl, rect.id});
            setxr[k].erase({rect.xr, rect.id});
            setyl[k].erase({rect.yl, rect.id});
            setyr[k].erase({rect.yr, rect.id});
        }
    }
}