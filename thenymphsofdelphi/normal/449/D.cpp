#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")

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

const int N = (1 << 20), mod = 1e9 + 7;

int pw2[N];
int n;
int a[N], b[N], c[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    pw2[0] = 1;
    For(i, 1, N){
        pw2[i] = pw2[i - 1] * 2;
        if (pw2[i] >= mod) pw2[i] -= mod;
    }
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        a[i] ^= (N - 1);
        b[a[i]]++;
    }
    For(i, 0, 20){
        For(j, 0, N){
            if (j & (1 << i)){
                b[j] += b[j ^ (1 << i)];
            }
        }
    }
    For(i, 0, N){
        c[i] = pw2[b[i]] - 1;
    }
    For(i, 0, N){
        if (__builtin_popcount(i) & 1){
            c[i] *= -1;
            if (c[i] < 0) c[i] += mod;
        }
    }
    For(i, 0, 20){
        For(j, 0, N){
            if (j & (1 << i)){
                c[j] += c[j ^ (1 << i)];
                if (c[j] >= mod) c[j] -= mod;
            }
        }
    }
    For(i, 0, N){
        if (__builtin_popcount(i) & 1){
            c[i] *= -1;
            if (c[i] < 0) c[i] += mod;
        }
    }
    cout << c[N - 1] << endl;
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