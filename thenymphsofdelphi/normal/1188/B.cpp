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

const int N = 3e5 + 5;

int n, p, k;

int a[N];

void readTest(){
    cin >> n >> p >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }
}

void resetTest(){
    
}

void solveTest(){
    map <int, int> mpp;
    ForE(i, 1, n){
        mpp[((ll)a[i] * a[i] % p * a[i] % p * a[i] % p - (ll)k * a[i] % p + p) % p]++;
    }
    ll ans = 0;
    Fora(&v, mpp){
        ans += (ll)v.se * (v.se - 1) / 2;
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    readTest();
    resetTest();
    solveTest();
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