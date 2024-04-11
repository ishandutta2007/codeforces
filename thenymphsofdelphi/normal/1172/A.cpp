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
int a[N], b[N];



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }

    int x = 0;
    ForE(i, 1, n){
        if (b[i] == x + 1){
            x++;
        }
        else if (x != 0){
            x = 0;
        }
    }
    if (x != 0){
        set <int> stt;
        ForE(i, 1, n){
            if (a[i] != 0){
                stt.emplace(a[i]);
            }
        }
        int y = x;
        bool ck = 1;
        ForE(i, 1, n - x){
            if (stt.find(y + 1) == stt.end()){
                ck = 0;
                break;
            }
            stt.erase(y + 1); y++;
            if (b[i] != 0){
                stt.emplace(b[i]);
            }
        }
        if (ck){
            cout << n - x << endl;
            return 0;
        }
    }
    set <int> stt;
    ForE(i, 1, n){
        if (a[i] != 0){
            stt.emplace(a[i]);
        }
    }
    x = 0;
    int ans = 0, i = 1;
    while (x < n){
        ans++;
        if (stt.find(x + 1) != stt.end()){
            stt.erase(x + 1);
            x++;
        }
        if (i <= n and b[i] != 0){
            stt.insert(b[i]);
        }
        i++;
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