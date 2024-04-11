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

const int N = 1e3 + 5;

int n;
int a[N], b[N];

vector <pair <pii, pii>> vans;

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
        cin >> b[i];
    }

    ForE(i, 1, n){
        int posa = -1, posb = -1;
        ForE(j, i, n){
            if (a[j] == i){
                posa = j;
            }
            if (b[j] == i){
                posb = j;
            }
        }
        if (posa == i and posb == i){
            continue;
        }
        vans.emplace_back(make_pair(posa, i), make_pair(i, posb));
        a[posa] = a[i];
        b[posb] = b[i];
    }
    cout << isz(vans) << endl;
    Fora(elem, vans){
        cout << elem.fi.fi << ' ' << elem.fi.se << ' ' << elem.se.fi << ' ' << elem.se.se << endl;
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