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

const int N = 1e5 + 5;

int n, m;
vi a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n >> m;
    ForE(i, 1, m){
        int x; cin >> x; a[i].resize(x);
        For(j, 0, x){
            cin >> a[i][j];
        }
    }
    map <int, int> mpponly;
    ForE(i, 1, m){
        if (isz(a[i]) == 1){
            mpponly[a[i][0]]++;
        }
    }
    bool ck = 1;
    Fora(&v, mpponly){
        if (v.se > (m + 1) / 2){
            ck = 0;
        }
    }
    if (!ck){
        cout << "NO" << endl;
        continue;
    }
    cout << "YES" << endl;
    map <int, int> mppcnt;
    ForE(i, 1, m){
        mppcnt[a[i][0]]++;
    }
    int val = -1;
    Fora(&v, mppcnt){
        if (v.se > (m + 1) / 2){
            val = v.fi;
        }
    }
    if (val == -1){
        ForE(i, 1, m){
            cout << a[i][0] << ' ';
        } cout << endl;
        continue;
    }
    int cnt = mppcnt[val] - (m + 1) / 2;
    ForE(i, 1, m){
        if (isz(a[i]) > 1 && a[i][0] == val && cnt){
            cnt--;
            cout << a[i][1] << ' ';
        }
        else{
            cout << a[i][0] << ' ';
        }
    } cout << endl;
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