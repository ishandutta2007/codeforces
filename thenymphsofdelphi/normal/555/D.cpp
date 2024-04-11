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

const int N = 2e5 + 5;

int n, q;
pii b[N];
int a[N], idx[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> b[i].fi; b[i].se = i;
    }

    sort(b + 1, b + n + 1);
    ForE(i, 1, n){
        a[i] = b[i].fi;
        idx[b[i].se] = i;
    }

    while (q--){
        int i, len; cin >> i >> len; i = idx[i];
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        set <tuple <int, int, int>> stt;
        int ans = -1;
        int dir = 1;
        while (1){
            if (stt.find(make_tuple(i, len, dir)) != stt.end()){
                ans = i;
                break;
            }
            stt.emplace(i, len, dir);
            if (dir == 1){
                int j = upper_bound(a + 1, a + n + 1, a[i] + len) - a - 1;
                if (j == i){
                    dir *= -1;
                    continue;
                }
                int lenseg = a[j] - a[i];
                int k = lower_bound(a + 1, a + n + 1, a[j] - (len - lenseg)) - a;
                if (k == i){
                    int turn = len / lenseg;
                    if (turn & 1){
                        i = j; len %= lenseg; dir *= -1;
                    }
                    else{
                        len %= lenseg;
                    }
                }
                else{
                    i = j; len -= lenseg; dir *= -1;
                }
            }
            else{
                int j = lower_bound(a + 1, a + n + 1, a[i] - len) - a;
                if (j == i){
                    dir *= -1;
                    continue;
                }
                int lenseg = a[i] - a[j];
                int k = upper_bound(a + 1, a + n + 1, a[j] + (len - lenseg)) - a - 1;
                if (k == i){
                    int turn = len / lenseg;
                    if (turn & 1){
                        i = j; len %= lenseg; dir *= -1;
                    }
                    else{
                        len %= lenseg;
                    }
                }
                else{
                    i = j; len -= lenseg; dir *= -1;
                }
            }
        }
        cout << b[ans].se << endl;
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