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

const int N = 1e5 + 5, inf = 1e9 + 7;

int n, m;
int a[N];
vi b[N];

pair <pair <ll, int>, int> sumb[N]; int possumb[N];
int ispos[3][N];

bool cmp(const pair <pair <ll, int>, int>& lhs, const pair <pair <ll, int>, int>& rhs){
    if (lhs.fi.fi * rhs.fi.se != rhs.fi.fi * lhs.fi.se){
        return lhs.fi.fi * rhs.fi.se < rhs.fi.fi * lhs.fi.se;
    }
    return lhs.se < rhs.se;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, m){
        b[i].clear();
        int k; cin >> k;
        while (k--){
            int x; cin >> x; b[i].emplace_back(x);
        }
    }

    ForE(i, 1, n){
        ispos[0][i] = ispos[1][i] = ispos[2][i] = 0;
    }
    ForE(i, 1, m){
        sumb[i] = make_pair(make_pair(accumulate(bend(b[i]), 0ll), isz(b[i])), i);
    }
    sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1); reverse(a + 1, a + m + 1);
    sort(sumb + 1, sumb + m + 1, cmp);
    ForE(i, 1, m){
        possumb[sumb[i].se] = i;
    }
    ForE(i, 1, m){
        ispos[0][i] = ispos[0][i - 1] + (i > 1 and (ll)a[i] * sumb[i - 1].fi.se >= sumb[i - 1].fi.fi);
        ispos[1][i] = ispos[1][i - 1] + ((ll)a[i] * sumb[i].fi.se >= sumb[i].fi.fi);
        ispos[2][i] = ispos[2][i - 1] + (i < m and (ll)a[i] * sumb[i + 1].fi.se >= sumb[i + 1].fi.fi);
    }
    ForE(i, 1, m){
        Fora(x, b[i]){
            ll tsumb = sumb[possumb[i]].fi.fi - x, tsz = isz(b[i]) - 1;
            int pos = lower_bound(sumb + 1, sumb + m + 1, make_pair(make_pair(tsumb, tsz), i), cmp) - sumb;
            if (pos == possumb[i]){
                cout << (ispos[1][pos - 1] + ((ll)a[pos] * tsz >= tsumb) + ispos[1][m] - ispos[1][pos] == m);
            }
            else if (pos < possumb[i]){
                cout << (ispos[1][pos - 1] + ((ll)a[pos] * tsz >= tsumb) + ispos[0][possumb[i]] - ispos[0][pos] + ispos[1][m] - ispos[1][possumb[i]] == m);
            }
            else{
                pos--;
                cout << (ispos[1][possumb[i] - 1] + ispos[2][pos - 1] - ispos[2][possumb[i] - 1] + ((ll)a[pos] * tsz >= tsumb) + ispos[1][m] - ispos[1][pos] == m);
            }
        }
    } cout << endl;
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