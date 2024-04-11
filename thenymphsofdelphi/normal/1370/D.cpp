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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int maxN = 2e5 + 5;

int n, k, mn = 1e9, mx = 1;
int a[maxN], b[maxN], dp[maxN][2];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    int l = mn, r = mx;
    while (l < r){
        int mid = (l + r) >> 1, t, type;
        ForE(i, 1, n){
            b[i] = (a[i] <= mid);
        }
        t = 0; type = 0;
        ForE(i, 1, n){
            if (type == 0 || (type == 1 && b[i] == 1)){
                t++;
                type = 1 - type;
                continue;
            }
        }
        if (t >= k){
            r = mid;
            continue;
        }
        t = 0; type = 1;
        ForE(i, 1, n){
            if (type == 0 || (type == 1 && b[i] == 1)){
                t++;
                type = 1 - type;
                continue;
            }
        }
        if (t >= k){
            r = mid;
            continue;
        }
        l = mid + 1;
    }
    cout << l;
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