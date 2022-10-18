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

const int N = 5e3 + 5;

int n, m;
int a[N], b[N];

int c[N];

unordered_map <int, int> mpp;

int cost(int x){
    if (mpp.count(x)){
        return mpp[x];
    }
    int tx = x;
    int ans = 0;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0){
            int cnt = 0;
            while (x % i == 0){
                cnt++; x /= i;
            }
            if (b[lower_bound(b + 1, b + m + 1, i) - b] == i){
                ans -= cnt;
            }
            else{
                ans += cnt;
            }
        }
    }
    if (x != 1){
        if (b[lower_bound(b + 1, b + m + 1, x) - b] == x){
            ans--;
        }
        else{
            ans++;
        }
    }
    return (mpp[tx] = ans);
}

int ans = 0;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, m){
        cin >> b[i];
    }

    ForE(i, 1, n){
        c[i] = __gcd(c[i - 1], a[i]);
    }
    ForE(i, 1, n){
        ans += cost(a[i]);
    }
    int t = 1;
    FordE(i, n, 1){
        int tans = cost(c[i] / t) * i;
        if (tans < 0){
            ans -= tans;
            t = c[i];
        }
    }
    cout << ans << endl;
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