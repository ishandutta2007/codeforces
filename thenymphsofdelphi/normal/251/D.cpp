#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = l; i < r; i++)
#define ForE(i, l, r) for (auto i = l; i <= r; i++)
#define FordE(i, l, r) for (auto i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pair <int, int>>;
using vvi = vector <vector <int>>;

const int N = 1e5 + 5, D = 60;

int n;
ll a[N], b[N];

ll c[N], sum, sumc;

struct xor_move: set <int>{
    void merge(const set <int> stt){
        Fora(&elem, stt){
            if (find(elem) == end()){
                insert(elem);
            }
            else{
                erase(elem);
            }
        }
    }
};

struct xor_basis{
    ll basis[D];
    xor_move vpos[D];

    xor_basis(){
        memset(basis, 0, sizeof(basis));
    }

    bool insert(ll x, int pos){
        ll tx = x;
        FordE(i, D - 1, 0){
            if (!(x & (1ll << i))){
                continue;
            }
            if (basis[i]){
                x ^= basis[i];
            }
            else{
                basis[i] = x;
                vpos[i].clear(); vpos[i].insert(pos);
                FordE(ti, D - 1, i + 1){
                    if (!(tx & (1ll << ti))){
                        continue;
                    }
                    if (basis[ti]){
                        tx ^= basis[ti];
                        vpos[i].merge(vpos[ti]);
                    }
                }
                return 1;
            }
        }
        return 0;
    }

    bool insert(ll x, const xor_move& pos){
        ll tx = x;
        FordE(i, D - 1, 0){
            if (!(x & (1ll << i))){
                continue;
            }
            if (basis[i]){
                x ^= basis[i];
            }
            else{
                basis[i] = x;
                vpos[i] = pos;
                FordE(ti, D - 1, i + 1){
                    if (!(tx & (1ll << ti))){
                        continue;
                    }
                    if (basis[ti]){
                        tx ^= basis[ti];
                        vpos[i].merge(vpos[ti]);
                    }
                }
                return 1;
            }
        }
        return 0;
    }
} cac, cac2, cac3;

ll ans1, ans2;
int cnt[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    ForE(i, 1, n){
        c[i] = a[i] ^ b[i];
        sum ^= a[i];
        sumc ^= c[i];
        cac.insert(c[i], i);
    }
    cac2 = cac;
    ans1 = sum, ans2 = (sum ^ sumc);
    FordE(i, D - 1, 0){
        if ((ans1 & (1ll << i)) and (ans2 & (1ll << i))){
            continue;
        }
        if (!(ans1 & (1ll << i)) and !(ans2 & (1ll << i))){
            if (cac.basis[i]){
                ans1 ^= cac.basis[i]; ans2 ^= cac.basis[i];
                Fora(&elem, cac.vpos[i]){
                    cnt[elem] ^= 1;
                }
            }
        }
        else{
            if (cac.basis[i]){
                ll x = cac.basis[i] ^ (1ll << i);
                cac.basis[i] = 0;
                cac.insert(x, cac.vpos[i]);
            }
        }
    }
    ans1 = 0; ans2 = 0;
    ForE(i, 1, n){
        if (cnt[i]){
            ans1 ^= b[i];
            ans2 ^= a[i];
        }
        else{
            ans1 ^= a[i];
            ans2 ^= b[i];
        }
    }
    FordE(i, D - 1, 0){
        if ((ans1 & (1ll << i)) and (ans2 & (1ll << i))){
            continue;
        }
        if (!(ans1 & (1ll << i)) and !(ans2 & (1ll << i))){
            continue;
        }
    }
    FordE(i, D - 1, 0){
        if ((ans1 & (1ll << i)) and (ans2 & (1ll << i))){
            continue;
        }
        if (!(ans1 & (1ll << i)) and !(ans2 & (1ll << i))){
            continue;
        }
        if (!(ans1 & (1ll << i)) and (ans2 & (1ll << i))){
            continue;
        }
        cac3 = cac2;
        if (cac3.basis[i] == 0){
            continue;
        }
        ll val = 0;
        FordE(j, i, 0){
            if ((ans1 & (1ll << j)) and (ans2 & (1ll << j))){
                continue;
            }
            if (!(ans1 & (1ll << j)) and !(ans2 & (1ll << j))){
                continue;
            }
            val |= (1ll << j);
        }
        xor_move moves = cac3.vpos[i];
        ll tval = cac3.basis[i];
        FordE(j, i - 1, 0){
            if (val & (1ll << j)){
                if (cac3.basis[j]){
                    ll x = cac3.basis[j] ^ (1ll << j);
                    cac3.basis[j] = 0;
                    cac3.insert(x, cac3.vpos[j]);
                }
            }
            else if (!(tval & (1ll << j))){

            }
            else{
                if (cac3.basis[j]){
                    moves.merge(cac3.vpos[j]);
                    tval ^= cac3.basis[j];
                }
                else{
                    moves = xor_move();
                    tval = 0;
                    break;
                }
            }
        }
        tval = 0;
        Fora(&elem, moves){
            tval ^= c[elem];
        }
        ans1 ^= tval; ans2 ^= tval;
        Fora(&elem, moves){
            cnt[elem] ^= 1;
        }
    }
    ForE(i, 1, n){
        cout << cnt[i] + 1 << ' ';
    } cout << endl;
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