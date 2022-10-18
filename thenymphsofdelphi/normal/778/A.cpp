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

int n;
string s, t;
int a[N];

bool ck[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> s >> t;
    n = isz(s); s = ' ' + s; t = ' ' + t;
    ForE(i, 1, n){
        cin >> a[i];
    }

    int lo = 0, hi = n;
    while (lo < hi){
        int mid = (lo + hi + 1) >> 1;
        ForE(i, 1, n){
            ck[i] = 0;
        }
        ForE(i, 1, mid){
            ck[a[i]] = 1;
        }
        int idx = 1;
        ForE(i, 1, n){
            if (ck[i]){
                continue;
            }
            if (s[i] == t[idx]){
                idx++;
                if (idx == isz(t)){
                    break;
                }
            }
        }
        if (idx == isz(t)){
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << lo << endl;
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