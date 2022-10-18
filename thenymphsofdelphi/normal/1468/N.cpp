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

int c1, c2, c3;
int a1, a2, a3, a4, a5;
int x;

void readTest(){
    cin >> c1 >> c2 >> c3 >> a1 >> a2 >> a3 >> a4 >> a5;
}

void resetTest(){
    
}

void solveTest(){
    c1 -= a1;
    if (c1 < 0){
        cout << "NO" << endl;
        return;
    }
    c2 -= a2;
    if (c2 < 0){
        cout << "NO" << endl;
        return;
    }
    c3 -= a3;
    if (c3 < 0){
        cout << "NO" << endl;
        return;
    }
    x = min(a4, c1);
    c1 -= x; a4 -= x;
    c3 -= a4;
    if (c3 < 0){
        cout << "NO" << endl;
        return;
    }
    x = min(a5, c2);
    c2 -= x; a5 -= x;
    c3 -= a5;
    if (c3 < 0){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    readTest();
    resetTest();
    solveTest();
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