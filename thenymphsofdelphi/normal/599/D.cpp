#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define Ptest(x) return cout << x << endl, 0;

typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

vii b;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x;
    cin >> x;
    for (int i = 1; i * i * i <= 8 * x; i++){
        if ((6 * x) % (i * (i + 1))){
            continue;
        }
        int a = (6 * x) / (i * (i + 1));
        a = a + i - 1;
        if (a % 3){
            continue;
        }
        if (i > a / 3){
            break;
        }
        b.pb({i, a / 3});
    }
    if (b[b.size() - 1].fi == b[b.size() - 1].se){
        cout << 2 * b.size() - 1 << endl;
    }
    else{
        cout << 2 * b.size() << endl;
    }
    for (int i = 0; i < b.size(); i++){
        if (b[i].fi == b[i].se){
            continue;
        }
        cout << b[i].fi << " " << b[i].se << endl;
    }
    for (int i = b.size() - 1; i >= 0; i--){
        cout << b[i].se << " " << b[i].fi << endl;
    }
}

/*
----------------------------------+
INPUT:                            |
==============================    |

==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |

==============================    |
----------------------------------+
*/