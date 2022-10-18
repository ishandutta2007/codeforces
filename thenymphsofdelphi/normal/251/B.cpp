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

const int N = 1e2 + 5;

int n, k;
vi a, b;

int cal(vi p){
    vi a(n + 1);
    iota(bend(a), 0);
    ForE(turn, 1, k){
        vi ta(n + 1, 0);
        ForE(i, 1, n){
            ta[i] = a[p[i]];
        }
        if (ta == b){
            return turn;
        }
        a = ta;
    }
    return k + 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    a.resize(n + 1); b.resize(n + 1);
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }

    {
        bool ck = 1;
        ForE(i, 1, n){
            ck &= (b[i] == i);
        }
        if (ck){
            cout << "NO" << endl;
            return 0;
        }
    }
    vi ra(n + 1, 0);
    ForE(i, 1, n){
        ra[a[i]] = i;
    }

    int vala = cal(a), valra = cal(ra);
    if (vala > k and valra > k){
        cout << "NO" << endl;
        return 0;
    }
    if (vala == k or valra == k){
        cout << "YES" << endl;
        return 0;
    }
    if (vala % 2 == k % 2){
        if (vala > 1){
            cout << "YES" << endl;
            return 0;
        }
        if (valra > 1){
            cout << "YES" << endl;
            return 0;
        }
    }
    if (valra % 2 == k % 2){
        if (valra > 1){
            cout << "YES" << endl;
            return 0;
        }
        if (vala > 1){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
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