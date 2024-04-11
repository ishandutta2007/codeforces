#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
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

const int N = 1e4 + 5, inf = 1e9 + 7;

int n;
int p[N], q[N];

int ask(int u){
    cout << "? " << u << endl;
    int ans; cin >> ans; return ans;
}

void answer(){
    cout << "! ";
    ForE(i, 1, n){
        cout << p[i] << ' ';
    } cout << endl;
}

signed main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;

    ForE(i, 1, n){
        p[i] = 0;
        q[i] = 0;
    }
    ForE(i, 1, n){
        if (p[i] != 0){
            continue;
        }
        vi a;
        int tx = ask(i), x = tx; 
        do{
            a.emplace_back(x); x = ask(i);
        } while (x != tx);
        For(i, 0, isz(a) - 1){
            p[a[i]] = a[i + 1];
        }
        p[a.back()] = a[0];
    }
    answer();
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