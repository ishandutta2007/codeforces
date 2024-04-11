#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

struct interval_t{
    int l, r;
    char dirl, dirr; int boundl, boundr;

    interval_t(){

    }

    interval_t(int l, int r): l(l), r(r), dirl('U'), dirr('L'), boundl(-1), boundr(-1){

    }

    interval_t(int l, int r, char dirl, char dirr, int boundl, int boundr): l(l), r(r), dirl(dirl), dirr(dirr), boundl(boundl), boundr(boundr){

    }

    friend bool operator< (const interval_t &lhs, const interval_t &rhs){
        return lhs.l < rhs.l;
    }
};

int n, q;
set <interval_t> stt;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    stt.emplace(1, n);
    while (q--){
        int x, y; char dir; cin >> x >> y >> dir;
        auto itr = stt.upper_bound(interval_t(x, x));
        if (itr == stt.begin() or prev(itr)->r < x){
            cout << 0 << endl;
            continue;
        }
        itr = prev(itr);
        interval_t itv = *itr; stt.erase(itr);
        int ans = 0;

        if (itv.dirl == 'L' and itv.dirr == 'U'){
            if (dir == 'U'){
                ans += y - itv.boundr + 1;
                if (x > itv.l){
                    stt.emplace(itv.l, x - 1, 'L', 'U', itv.boundl, itv.boundr);
                }
                if (x < itv.r){
                    stt.emplace(x + 1, itv.r, 'U', 'U', -1, itv.boundr);
                }
            }
            else{
                ans += x - itv.boundl + 1;
                if (x > itv.l){
                    stt.emplace(itv.l, x - 1, 'L', 'L', itv.boundl, -1);
                }
                if (x < itv.r){
                    stt.emplace(x + 1, itv.r, 'L', 'U', itv.boundl, itv.boundr);
                }
            }
        }
        else if (itv.dirl == 'L'){
            if (dir == 'U'){
                ans += y - (n + 1 - itv.r) + 1;
                if (x > itv.l){
                    stt.emplace(itv.l, x - 1, 'L', 'U', itv.boundl, n + 1 - itv.r);
                }
                if (x < itv.r){
                    stt.emplace(x + 1, itv.r);
                }
            }
            else{
                ans += x - itv.boundl + 1;
                if (x > itv.l){
                    stt.emplace(itv.l, x - 1, 'L', 'L', itv.boundl, -1);
                }
                if (x < itv.r){
                    stt.emplace(x + 1, itv.r, 'L', 'L', itv.boundl, -1);
                }
            }
        }
        else if (itv.dirr == 'U'){
            if (dir == 'U'){
                ans += y - itv.boundr + 1;
                if (x > itv.l){
                    stt.emplace(itv.l, x - 1, 'U', 'U', -1, itv.boundr);
                }
                if (x < itv.r){
                    stt.emplace(x + 1, itv.r, 'U', 'U', -1, itv.boundr);
                }
            }
            else{
                ans += x - itv.l + 1;
                if (x > itv.l){
                    stt.emplace(itv.l, x - 1);
                }
                if (x < itv.r){
                    stt.emplace(x + 1, itv.r, 'L', 'U', itv.l, itv.boundr);
                }
            }
        }
        else{
            if (dir == 'U'){
                ans += y - (n + 1 - itv.r) + 1;
                if (x > itv.l){
                    stt.emplace(itv.l, x - 1, 'U', 'U', -1, n + 1 - itv.r);
                }
                if (x < itv.r){
                    stt.emplace(x + 1, itv.r);
                }
            }
            else{
                ans += x - itv.l + 1;
                if (x > itv.l){
                    stt.emplace(itv.l, x - 1);
                }
                if (x < itv.r){
                    stt.emplace(x + 1, itv.r, 'L', 'L', itv.l, -1);
                }
            }
        }
        cout << ans << endl;
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/