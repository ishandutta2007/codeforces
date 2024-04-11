#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5;

int n, ca, cb, cc;
string s;

vpii a;
vi vcp0;

ll ans;

ll cal(int cnt0, int cnt1, int turn, int cntmv3end, bool mv3mid){
    bool deb = 0;
    // if (turn == 1 and cntmv3end == 0 and mv3mid == 1){
    //     deb = 1;
    // }
    ll tans = 0;
    vi cp0 = vcp0;
    int idx = 0;
    while (1){
        if (deb){
            cout << "A " << turn << ' ' << idx << ' ' << cnt0 << ' ' << cnt1 << ' ' << tans << endl;
        }
        if (turn == 0){
            if (idx < isz(cp0)){
                if (cp0[idx] >= 2){
                    tans += ca;
                    cp0[idx]--;
                    cnt0--;
                }
                else{
                    if (mv3mid){
                        tans -= cc;
                        cp0[idx] = 0;
                        idx++;
                        cnt1++;
                    }
                    else{
                        idx++;
                        continue;
                    }
                }
            }
            else{
                if (cnt0){
                    tans += ca;
                    cnt0--;
                }
                else{
                    if (cntmv3end){
                        tans -= cc;
                        cntmv3end--;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        else{
            if (cnt1){
                tans += cb;
                cnt1--;
            }
            else{
                break;
            }
        }
        turn = 1 - turn;
    }
    return tans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> ca >> cb >> cc;
    cin >> s;

    a.clear();
    vcp0.clear();
    ans = 0;

    {
        int x = s[0] - '0', len = 1;
        ForE(i, 1, n){
            if (i == n or s[i] != s[i - 1]){
                a.emplace_back(x, len);
                if (i != n){
                    x = s[i] - '0'; len = 1;
                }
            }
            else{
                len++;
            }
        }
    }
    int cnt0 = 0, cnt1 = 0, cntmv3end = 0;
    For(i, 0, isz(a)){
        if (a[i].fi == 0){
            cnt0 += a[i].se - 1;
            if (i != 0 and i != isz(a) - 1){
                vcp0.emplace_back(a[i].se);
            }
            else{
                cntmv3end++;
            }
        }
        else{
            cnt1 += a[i].se - 1;
        }
    }
    sort(bend(vcp0));
    ForE(turn, 0, 1){
        ForE(tcntmv3end, 0, cntmv3end){
            ForE(mv3mid, 0, 1){
                ll tans = cal(cnt0, cnt1, turn, tcntmv3end, mv3mid);
                // cout << cnt0 << ' ' << cnt1 << ' ' << turn << ' ' << tcntmv3end << ' ' << mv3mid << ' ' << tans << endl;
                ans = max(ans, tans);
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