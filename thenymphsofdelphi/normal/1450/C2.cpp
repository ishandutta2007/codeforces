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

const int N = 3e2 + 5;

int n, cnt;
char a[N][N];
int x[3], o[3];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cnt = 0;
    memset(x, 0, sizeof(x)); memset(o, 0, sizeof(o));
    
    cin >> n;
    ForE(i, 1, n){
        ForE(j, 1, n){
            cin >> a[i][j];
            if (a[i][j] != '.'){
                cnt++;
            }
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, n){
            if (a[i][j] == 'X'){
                x[(i + j) % 3]++;
            }
            else if (a[i][j] == 'O'){
                o[(i + j) % 3]++;
            }
        }
    }
    bool ck = 0;
    For(p, 0, 3){
        For(q, 0, 3){
            if (p == q){
                continue;
            }
            if (x[p] + o[q] <= cnt / 3){
                ForE(i, 1, n){
                    ForE(j, 1, n){
                        if (a[i][j] == 'X' && (i + j) % 3 == p){
                            a[i][j] = 'O';
                        }
                        else if (a[i][j] == 'O' && (i + j) % 3 == q){
                            a[i][j] = 'X';
                        }
                    }
                }
                ck = 1;
                break;
            }
        }
        if (ck){
            break;
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, n){
            cout << a[i][j];
        } cout << endl;
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