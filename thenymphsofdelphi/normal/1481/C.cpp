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
int a[N], b[N];
int c[N];

vi all[N], need[N];
int lst;
int ans[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }
    ForE(i, 1, m){
        cin >> c[i];
    }
    
    ForE(i, 1, n){
        all[i].clear();
        need[i].clear();
    }
    lst = 0;
    ForE(i, 1, n){
        all[b[i]].push_back(i);
        if (a[i] != b[i]){
            need[b[i]].push_back(i);
        }
    }
    bool ck = 1;
    FordE(i, m, 1){
        if (!lst && !isz(all[c[i]])){
            ck = 0;
            break;
        }
        if (isz(need[c[i]])){
            lst = ans[i] = need[c[i]].back();
            need[c[i]].pop_back();
        }
        else if (lst){
            ans[i] = lst;
        }
        else{
            lst = ans[i] = all[c[i]].back();
        }
    }
    ForE(i, 1, n){
        if (isz(need[i])){
            ck = 0;
            break;
        }
    }
    if (!ck){
        cout << "NO" << endl;
        continue;
    }
    cout << "YES" << endl;
    ForE(i, 1, m){
        cout << ans[i] << ' ';
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