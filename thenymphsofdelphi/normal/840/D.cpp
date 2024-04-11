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

const int N = 3e5 + 5, K = 5;

int n, q;
int a[N];
tuple <int, int, int> queries[N];

vi pos[N];
vpii b[N];

int ans[N];

void solve(int l, int r, const vi& vidxque){
    if (l == r){
        Fora(idxque, vidxque){
            ans[idxque] = a[l];
        }
        return;
    }
    int mid = (l + r) >> 1;
    vi vidxquel, vidxquer, vidxquemid;
    Fora(idxque, vidxque){
        if (get<1>(queries[idxque]) <= mid){
            vidxquel.emplace_back(idxque);
        }
        else if (get<0>(queries[idxque]) >= mid + 1){
            vidxquer.emplace_back(idxque);
        }
        else{
            vidxquemid.emplace_back(idxque);
        }
    }
    if (!vidxquel.empty()){
        solve(l, mid, vidxquel);
    }
    if (!vidxquer.empty()){
        solve(mid + 1, r, vidxquer);
    }
    ForE(i, l, r){
        b[i].clear();
    }
    b[mid].emplace_back(a[mid], 1);
    FordE(i, mid - 1, l){
        bool containi = 0;
        Fora(elem, b[i + 1]){
            if (elem.fi == a[i]){
                containi = 1;
                elem.se++;
            }
            if (elem.se * K > mid - i + 1){
                b[i].emplace_back(elem);
            }
        }
        if (!containi){
            int cnt = distance(lower_bound(bend(pos[a[i]]), i), upper_bound(bend(pos[a[i]]), mid));
            if (cnt * K > mid - i + 1){
                b[i].emplace_back(a[i], cnt);
            }
        }
    }
    b[mid + 1].emplace_back(a[mid + 1], 1);
    ForE(i, mid + 2, r){
        bool containi = 0;
        Fora(elem, b[i - 1]){
            if (elem.fi == a[i]){
                containi = 1;
                elem.se++;
            }
            if (elem.se * K > i - mid){
                b[i].emplace_back(elem);
            }
        }
        if (!containi){
            int cnt = distance(lower_bound(bend(pos[a[i]]), mid + 1), upper_bound(bend(pos[a[i]]), i));
            if (cnt * K > i - mid){
                b[i].emplace_back(a[i], cnt);
            }
        }
    }
    Fora(idxque, vidxquemid){
        ans[idxque] = -1;
        Fora(elem, b[get<0>(queries[idxque])]){
            int cnt = distance(lower_bound(bend(pos[elem.fi]), get<0>(queries[idxque])), upper_bound(bend(pos[elem.fi]), get<1>(queries[idxque])));
            if (cnt * get<2>(queries[idxque]) > get<1>(queries[idxque]) - get<0>(queries[idxque]) + 1){
                if (ans[idxque] == -1 or ans[idxque] > elem.fi){
                    ans[idxque] = elem.fi;
                }
            }
        }
        Fora(elem, b[get<1>(queries[idxque])]){
            int cnt = distance(lower_bound(bend(pos[elem.fi]), get<0>(queries[idxque])), upper_bound(bend(pos[elem.fi]), get<1>(queries[idxque])));
            if (cnt * get<2>(queries[idxque]) > get<1>(queries[idxque]) - get<0>(queries[idxque]) + 1){
                if (ans[idxque] == -1 or ans[idxque] > elem.fi){
                    ans[idxque] = elem.fi;
                }
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, q){
        cin >> get<0>(queries[i]) >> get<1>(queries[i]) >> get<2>(queries[i]);
    }

    ForE(i, 1, n){
        pos[a[i]].emplace_back(i);
    }
    vi vidxque; ForE(i, 1, q) vidxque.emplace_back(i);
    solve(1, n, vidxque);
    ForE(i, 1, q){
        cout << ans[i] << endl;
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