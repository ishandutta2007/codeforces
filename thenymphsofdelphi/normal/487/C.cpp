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

int n;

void readTest(){
    cin >> n;
}

bool is_prime(int x){
    if (x <= 1){
        return 0;
    }
    if (x <= 3){
        return 1;
    }
    if (!(x % 2) || !(x % 3)){
        return 0;
    }
    for (int i = 5; i * i <= x; i += 6){
        if (!(x % i) || !(x % (i + 2))){
            return 0;
        }
    }
    return 1;
}

int binpow(int x, int y, int p){
    int ans = 1;
    while (y){
        if (y & 1) ans = (ll)ans * x % p;
        x = (ll)x * x % p;
        y >>= 1;
    }
    return ans;
}

void resetTest(){
    
}

void solveTest(){
    if (n == 1){
        cout << "YES" << endl;
        cout << 1 << endl;
        return;
    }
    if (n == 2){
        cout << "YES" << endl;
        cout << 1 << endl << 2 << endl;
        return;
    }
    if (n == 3){
        cout << "YES" << endl;
        cout << 1 << endl << 2 << endl << 3 << endl;
        return;
    }
    if (n == 4){
        cout << "YES" << endl;
        cout << 1 << endl << 3 << endl << 2 << endl << 4 << endl;
        return;
    }
    if (!is_prime(n)){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << 1 << endl;
    For(i, 2, n){
        cout << (ll)i * binpow(i - 1, n - 2, n) % n << endl;
    }
    cout << n << endl;
    return;
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