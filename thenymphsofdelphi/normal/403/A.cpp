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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    int n, p; cin >> n >> p;

    vpii vans;
    set <pii> stt;
    ForE(i, 1, n){
        ForE(j, i + 1, n){
            stt.emplace(i, j);
        }
    }
    ForE(i, 1, n){
        int j = i + 1; if (j > n) j -= n;
        vans.emplace_back(make_pair(min(i, j), max(i, j))); stt.erase(make_pair(min(i, j), max(i, j)));
        j++; if (j > n) j -= n;
        vans.emplace_back(make_pair(min(i, j), max(i, j))); stt.erase(make_pair(min(i, j), max(i, j)));
    }
    while (isz(vans) < 2 * n + p){
        pii cac = *stt.begin(); stt.erase(stt.begin());
        vans.emplace_back(cac);
    }
    Fora(elem, vans){
        cout << elem.fi << ' ' << elem.se << endl;
    }
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