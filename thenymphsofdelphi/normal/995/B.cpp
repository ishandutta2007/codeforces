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

const int N = 2e2 + 5;

int n;
int a[N];
int b[N]; bool ck[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, 2 * n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        int x = 0;
        ForE(j, 1, 2 * n){
            if (!ck[j]){
                x = a[j];
                break;
            }
        }
        bool t = 0;
        ForE(j, 1, 2 * n){
            if (a[j] == x){
                if (!t){
                    b[j] = 2 * i - 1;
                    t = 1;
                }
                else{
                    b[j] = 2 * i;
                }
                ck[j] = 1;
            }
        }
    }
    int ans = 0;
    ForE(i, 1, 2 * n){
        ForE(j, i + 1, 2 * n){
            if (b[j] < b[i]){
                ans++;
            }
        }
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