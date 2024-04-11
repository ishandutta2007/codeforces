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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e2 + 5;

int n, cnt1, cnt2;
int a[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n; cnt2 = n * n / 2; cnt1 = n * n - cnt2;
    ForE(turn, 1, n * n){
        int c; cin >> c;
        bool ck = 0;
        if (c == 1){
            if (!cnt2){
                ForE(i, 1, n){
                    ForE(j, 1, n){
                        if ((i + j) % 2 == 0 and !a[i][j]){
                            cout << 3 << ' ' << i << ' ' << j << endl;
                            a[i][j] = 3;
                            ck = 1;
                            break;
                        }
                    }
                    if (ck){
                        break;
                    }
                }
                cnt1--;
            }
            else{
                ForE(i, 1, n){
                    ForE(j, 1, n){
                        if ((i + j) % 2 == 1 and !a[i][j]){
                            cout << 2 << ' ' << i << ' ' << j << endl;
                            a[i][j] = 2;
                            ck = 1;
                            break;
                        }
                    }
                    if (ck){
                        break;
                    }
                }
                cnt2--;
            }
        }
        else{
            if (!cnt1){
                ForE(i, 1, n){
                    ForE(j, 1, n){
                        if ((i + j) % 2 == 1 and !a[i][j]){
                            cout << 5 - c << ' ' << i << ' ' << j << endl;
                            a[i][j] = 5 - c;
                            ck = 1;
                            break;
                        }
                    }
                    if (ck){
                        break;
                    }
                }
                cnt2--;
            }
            else{
                ForE(i, 1, n){
                    ForE(j, 1, n){
                        if ((i + j) % 2 == 0 and !a[i][j]){
                            cout << 1 << ' ' << i << ' ' << j << endl;
                            a[i][j] = 1;
                            ck = 1;
                            break;
                        }
                    }
                    if (ck){
                        break;
                    }
                }
                cnt1--;
            }
        }
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/