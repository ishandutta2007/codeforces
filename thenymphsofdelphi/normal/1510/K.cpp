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

const int N = 2e3 + 5;

int n;
int a[2][N];

void ope1(int j){
    ForE(i, 1, n / 2){
        swap(a[j][2 * i - 1], a[j][2 * i]);
    }
}

void ope2(int j){
    ForE(i, 1, n / 2){
        swap(a[j][i], a[j][n / 2 + i]);
    }
}

bool is_sorted(int j){
    ForE(i, 2, n){
        if (a[j][i] < a[j][i - 1]){
            return 0;
        }
    }
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n; n *= 2;
    ForE(i, 1, n){
        cin >> a[0][i]; a[1][i] = a[0][i];
    }
    ForE(i, 0, 2 * n){
        if (is_sorted(0) or is_sorted(1)){
            cout << i << endl;
            return 0;
        }
        if (i & 1){
            ope1(0); ope2(1);
        }
        else{
            ope2(0); ope1(1);
        }
    }
    cout << -1 << endl;
    return 0;
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
*/