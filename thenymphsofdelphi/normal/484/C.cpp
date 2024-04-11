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

const int N = 1e6 + 5, M = 20;

int n, m, q;
string s;

int nxt[M][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
cin >> s; n = isz(s);
cin >> q; while (q--){
    int k, d; cin >> k >> d;
    int cnt = 0;
    For(i, 0, d){
        for (int j = i; j < k; j += d){
            nxt[0][j] = cnt++;
        }
    }
    For(i, 0, k){
        nxt[0][i]--;
    }
    For(j, 1, M){
        For(i, 0, k){
            nxt[j][i] = (nxt[j - 1][i] < 0 ? -1 : nxt[j - 1][nxt[j - 1][i]]);
        }
    }
    string ts(n, ' ');
    For(i, 0, n){
        int ti = min(i, k - 1), start = max(0, i - k + 1);
        int idx = 0, pos = ti;
        FordE(j, M - 1, 0){
            if (nxt[j][pos] >= 0){
                idx |= (1 << j);
                pos = nxt[j][pos];
            }
        }
        if (start + idx >= n - k){
            pos = ti;
            FordE(j, M - 1, 0){
                if ((n - k - start + 1) & (1 << j)){
                    pos = nxt[j][pos];
                }
            }
            pos++;
            ts[n - k + pos] = s[i];
        }
        else{
            ts[start + idx] = s[i];
        }
    }
    s = ts;
    cout << s << endl;
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