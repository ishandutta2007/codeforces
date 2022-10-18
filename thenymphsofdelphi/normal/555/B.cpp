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

int n, m;
ll l[N], r[N];
pair <ll, int> a[N];

tuple <ll, ll, int> d[N];

priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater <pair <ll, int>>> pq;
ll ans[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> l[i] >> r[i];
    }
    ForE(i, 1, m){
        cin >> a[i].fi; a[i].se = i;
    }

    ForE(i, 2, n){
        d[i - 1] = make_tuple(l[i] - r[i - 1], r[i] - l[i - 1], i - 1);
    }
    sort(d + 1, d + n);
    sort(a + 1, a + m + 1);
    int i = 1, j = 1;
    while (i < n or j <= m){
        if (i >= n){
            if (!pq.empty()){
                pair <ll, int> cac = pq.top(); pq.pop();
                if (cac.fi < a[j].fi){
                    cout << "No" << endl;
                    return 0;
                }
                ans[cac.se] = a[j].se;
            }
            j++;
            continue;
        }
        if (j > m){
            pq.emplace(get<1>(d[i]), get<2>(d[i]));
            i++;
            continue;
        }
        if (get<0>(d[i]) <= a[j].fi){
            pq.emplace(get<1>(d[i]), get<2>(d[i]));
            i++;
        }
        else{
            if (!pq.empty()){
                pair <ll, int> cac = pq.top(); pq.pop();
                if (cac.fi < a[j].fi){
                    cout << "No" << endl;
                    return 0;
                }
                ans[cac.se] = a[j].se;
            }
            j++;
        }
    }
    if (!pq.empty()){
        cout << "No" << endl;
        return 0;
    }
    For(i, 1, n){
        if (ans[i] == 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    For(i, 1, n){
        cout << ans[i] << ' ';
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