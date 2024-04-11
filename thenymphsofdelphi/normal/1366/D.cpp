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

const int N = 5e5 + 5, M = 1e7 + 5;

int lpf[M];
vi prime;

void sieve(){
    For(i, 2, M){
        if (!lpf[i]){
            lpf[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < isz(prime) && prime[j] <= i && i * prime[j] < M; j++){
            lpf[i * prime[j]] = prime[j];
        }
    }
}

int n;
int a[N];
int ans1[N], ans2[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        int x = lpf[a[i]];
        ans2[i] = 1;
        while (a[i] % x == 0){
            a[i] /= x;
            ans2[i] *= x;
        }
        if (a[i] != 1){
            ans1[i] = a[i];
        }
        else{
            ans1[i] = ans2[i] = -1;
        }
    }
    ForE(i, 1, n){
        cout << ans1[i] << ' ';
    } cout << endl;
    ForE(i, 1, n){
        cout << ans2[i] << ' ';
    } cout << endl;
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