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

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int randt(int l, int r){ return rando() % (r - l + 1) + l; }

const int N = 1e4 + 5, M = 24;

int n;
string s[N];
int a[1 << M], b[1 << M];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> s[i];
        vi c; c.push_back(s[i][0] - 'a'); c.push_back(s[i][1] - 'a'); c.push_back(s[i][2] - 'a');
        sort(bend(c)); c.erase(unique(bend(c)), c.end());
        if (isz(c) == 1){
            a[1 << c[0]]++;
        }
        else if (isz(c) == 2){
            a[1 << c[0]]++;
            a[1 << c[1]]++;
            a[(1 << c[0]) | (1 << c[1])]--;
        }
        else if (isz(c) == 3){
            a[1 << c[0]]++;
            a[1 << c[1]]++;
            a[1 << c[2]]++;
            a[(1 << c[0]) | (1 << c[1])]--;
            a[(1 << c[1]) | (1 << c[2])]--;
            a[(1 << c[2]) | (1 << c[0])]--;
            a[(1 << c[0]) | (1 << c[1]) | (1 << c[2])]++;
        }
    }
    For(i, 0, (1 << M)){
        b[i] = a[i];
    }
    For(j, 0, M){
        For(i, 0, (1 << M)){
            if (i & (1 << j)){
                b[i] += b[i ^ (1 << j)];
            }
        }
    }
    int ans = 0;
    For(i, 0, (1 << M)){
        ans ^= b[i] * b[i];
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