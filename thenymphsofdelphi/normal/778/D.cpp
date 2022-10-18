#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
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

const int N = 50 + 5;

int n, m;
char a[N][N];

bool isswap;

vpii solve(){
    vpii vans;
    ForE(i, 1, n){
        for (int j = 1; j <= m; j += 2){
            if (a[i][j] == 'L'){
                continue;
            }
            vpii tvans;
            int x = i, y = j;
            while (1){
                tvans.emplace_back(x, y);
                if (a[x][y + 1] == 'U'){
                    break;
                }
                tvans.emplace_back(x, y + 1);
                if (a[x + 1][y + 1] == 'L'){
                    break;
                }
                x++; y++;
            }
            reverse(bend(tvans));
            Fora(&cell, tvans){
                int x, y; tie(x, y) = cell;
                if (a[x][y] == 'L'){
                    a[x][y] = a[x][y + 1] = 'U';
                    a[x + 1][y] = a[x + 1][y + 1] = 'D';
                }
                else{
                    a[x][y] = a[x + 1][y] = 'L';
                    a[x][y + 1] = a[x + 1][y + 1] = 'R';
                }
            }
            vans.insert(vans.end(), bend(tvans));
        }
    }
    return vans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    if (m % 2 == 1){
        isswap = 1;
        swap(n, m);
    }
    if (isswap){
        ForE(j, 1, m){
            ForE(i, 1, n){
                cin >> a[i][j];
                if (a[i][j] == 'U'){
                    a[i][j] = 'L';
                }
                else if (a[i][j] == 'D'){
                    a[i][j] = 'R';
                }
                else if (a[i][j] == 'L'){
                    a[i][j] = 'U';
                }
                else{
                    a[i][j] = 'D';
                }
            }
        }
    }
    else{
        ForE(i, 1, n){
            ForE(j, 1, m){
                cin >> a[i][j];
            }
        }
    }

    vpii vans1 = solve();
    if (isswap){
        ForE(j, 1, m){
            ForE(i, 1, n){
                cin >> a[i][j];
                if (a[i][j] == 'U'){
                    a[i][j] = 'L';
                }
                else if (a[i][j] == 'D'){
                    a[i][j] = 'R';
                }
                else if (a[i][j] == 'L'){
                    a[i][j] = 'U';
                }
                else{
                    a[i][j] = 'D';
                }
            }
        }
    }
    else{
        ForE(i, 1, n){
            ForE(j, 1, m){
                cin >> a[i][j];
            }
        }
    }
    vpii vans2 = solve();
    if (isswap){
        cout << isz(vans1) + isz(vans2) << endl;
        For(i, 0, isz(vans1)){
            cout << vans1[i].se << ' ' << vans1[i].fi << endl;
        }
        FordE(i, isz(vans2) - 1, 0){
            cout << vans2[i].se << ' ' << vans2[i].fi << endl;
        }
    }
    else{
        cout << isz(vans1) + isz(vans2) << endl;
        For(i, 0, isz(vans1)){
            cout << vans1[i].fi << ' ' << vans1[i].se << endl;
        }
        FordE(i, isz(vans2) - 1, 0){
            cout << vans2[i].fi << ' ' << vans2[i].se << endl;
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