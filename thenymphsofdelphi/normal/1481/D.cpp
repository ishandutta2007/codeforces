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

const int N = 1e3 + 5;

int n, m;
char a[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n >> m;
    ForE(i, 1, n){
        ForE(j, 1, n){
            cin >> a[i][j];
        }
    }
    bool ck = 0;
    ForE(i, 1, n){
        ForE(j, i + 1, n){
            if (a[i][j] == a[j][i]){
                cout << "YES" << endl;
                ForE(k, 1, m + 1){
                    if (k & 1){
                        cout << i << ' ';
                    }
                    else{
                        cout << j << ' ';
                    }
                } cout << endl;
                ck = 1;
                break;
            }
        }
        if (ck){
            break;
        }
    }
    if (ck){
        continue;
    }
    if (m & 1){
        cout << "YES" << endl;
        ForE(k, 1, m + 1){
            if (k & 1){
                cout << 1 << ' ';
            }
            else{
                cout << 2 << ' ';
            }
        } cout << endl;
        continue;
    }
    if (n == 2){
        cout << "NO" << endl;
        continue;
    }
    int x = -1, y = -1, z = -1;
    if (a[1][2] == 'a'){
        if (a[2][3] == 'a'){
            x = 1; y = 2; z = 3;
        }
        else if (a[1][3] == 'a'){
            x = 1; y = 3; z = 2;
        }
        else{
            x = 3; y = 1; z = 2;
        }
    }
    else{
        if (a[1][3] == 'a'){
            x = 2; y = 1; z = 3;
        }
        else if (a[2][3] == 'a'){
            x = 2; y = 3; z = 1;
        }
        else{
            x = 3; y = 2; z = 1;
        }
    }
    cout << "YES" << endl;
    if ((m / 2) & 1){
        ForE(k, 1, m / 2){
            if (k & 1){
                cout << x << ' ';
            }
            else{
                cout << y << ' ';
            }
        }
        cout << y << ' ';
        ForE(k, 1, m / 2){
            if (k & 1){
                cout << z << ' ';
            }
            else{
                cout << y << ' ';
            }
        }
    }
    else{
        ForE(k, 1, m / 2){
            if (k & 1){
                cout << y << ' ';
            }
            else{
                cout << x << ' ';
            }
        }
        cout << y << ' ';
        ForE(k, 1, m / 2){
            if (k & 1){
                cout << z << ' ';
            }
            else{
                cout << y << ' ';
            }
        }
    }
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