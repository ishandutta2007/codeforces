#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e3 + 5;

int n;

ll ask(int t, int i, int j, int k){
    cout << t << ' ' << i << ' ' << j << ' ' << k << endl;
    ll ans; cin >> ans; return ans;
}

void answer(vi vans){
    cout << 0 << ' ';
    Fora(&v, vans) cout << v << ' ';
    cout << endl;
}

ll area[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> n;
    int nxt = 2;
    ForE(i, 3, n){
        int sign = ask(2, 1, nxt, i);
        if (sign == -1){
            nxt = i;
        }
    }
    ll mxarea = 0; int idxmxarea = 0;
    ForE(i, 2, n){
        if (i != nxt){
            area[i] = ask(1, 1, nxt, i);
            if (area[i] > mxarea){
                mxarea = area[i];
                idxmxarea = i;
            }
        }
    }
    vector <pair <ll, int>> nxt1, nxt2; vi ans;
    ForE(i, 2, n){
        if (i != nxt && i != idxmxarea){
            int sign = ask(2, 1, idxmxarea, i);
            if (sign == 1){
                nxt2.emplace_back(area[i], i);
            }
            else{
                nxt1.emplace_back(area[i], i);
            }
        }
    }
    ans.push_back(1); ans.push_back(nxt);
    sort(bend(nxt1));
    Fora(&v, nxt1){
        ans.push_back(v.se);
    }
    ans.push_back(idxmxarea);
    sort(bend(nxt2)); reverse(bend(nxt2));
    Fora(&v, nxt2){
        ans.push_back(v.se);
    }
    answer(ans);
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