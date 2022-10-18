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

const int N = 5e5 + 5;

int n; ll k;
ll a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    {
        ll tk = k, x = a[1];
        ForE(i, 2, n + 1){
            if (i == n + 1 or (a[i] != a[i - 1])){
                if (i != n + 1 and tk > (ll)(i - 1) * (a[i] - a[i - 1])){
                    tk -= (ll)(i - 1) * (a[i] - a[i - 1]);
                    x = a[i];
                    continue;
                }
                ll y = tk / (i - 1);
                tk -= y * (i - 1);
                x += y;
                For(j, 1, i){
                    a[j] = x;
                }
                FordE(j, i - 1, i - tk){
                    a[j]++;
                }
                break;
            }
        }
    }
    {
        ll tk = k, x = a[n];
        FordE(i, n - 1, 0){
            if (i == 0 or (a[i] != a[i + 1])){
                if (i != 0 and tk > (ll)(n - i) * (a[i + 1] - a[i])){
                    tk -= (ll)(n - i) * (a[i + 1] - a[i]);
                    x = a[i];
                    continue;
                }
                ll y = tk / (n - i);
                tk -= y * (n - i);
                x -= y;
                ForE(j, i + 1, n){
                    a[j] = x;
                }
                ForE(j, i + 1, i + tk){
                    a[j]--;
                }
                break;
            }
        }
    }
    cout << a[n] - a[1] << endl;
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