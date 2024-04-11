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

const int mod = 1e9 + 7;

struct Matrix{
    int mat[3][3];
    
    Matrix(){
        memset(mat, 0, sizeof(mat));
    }
};

Matrix mul(Matrix lhs, Matrix rhs, int mod){
    Matrix ans;
    For(i, 0, 3){
        For(j, 0, 3){
            For(k, 0, 3){
                ans.mat[i][j] += (ll)lhs.mat[i][k] * rhs.mat[k][j] % mod;
                if (ans.mat[i][j] >= mod){
                    ans.mat[i][j] -= mod;
                }
            }
        }
    }
    return ans;
}

Matrix binpow(Matrix a, ll n, int mod){
    Matrix ans; ans.mat[0][0] = ans.mat[1][1] = ans.mat[2][2] = 1;
    while (n){
        if (n & 1){
            ans = mul(ans, a, mod);
        }
        a = mul(a, a, mod);
        n >>= 1;
    }
    return ans;
}

int binpow(int x, ll y, int mod){
    int ans = 1;
    while (y){
        if (y & 1){
            ans = (ll)ans * x % mod;
        }
        x = (ll)x * x % mod;
        y >>= 1;
    }
    return ans;
}

bool isprime(int x){
    if (x <= 1){
        return 0;
    }
    if (x <= 3){
        return 1;
    }
    if (!(x % 2) || x % 3 == 0){
        return 0;
    }
    for (int i = 5; i * i <= x; i += 6){
        if (x % i == 0 || x % (i + 2) == 0){
            return 0;
        }
    }
    return 1;
}

ll n;
int f1, f2, f3, c;

unordered_set <int> stt;

void cal_stt(int x){
    for (int i = 1; i * i <= x; i++){
        if (x % i == 0){
            if (isprime(i)){
                stt.insert(i);
            }
            if (isprime(x / i)){
                stt.insert(x / i);
            }
        }
    }
}

int ans = 1;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> f1 >> f2 >> f3 >> c;
    ans = binpow(binpow(c, n, mod), mod - 2, mod);
    Matrix a; a.mat[1][0] = a.mat[2][1] = a.mat[0][2] = a.mat[1][2] = a.mat[2][2] = 1;
    a = binpow(a, n - 3, mod - 1);
    cal_stt(f1); cal_stt(f2); cal_stt(f3); cal_stt(c);
    Fora(&p, stt){
        int x1 = 0, x2 = 0, x3 = 0;
        while (c % p == 0){
            c /= p;
            x1 += 1; x2 += 2; x3 += 3;
        }
        while (f1 % p == 0){
            f1 /= p;
            x1++;
        }
        while (f2 % p == 0){
            f2 /= p;
            x2++;
        }
        while (f3 % p == 0){
            f3 /= p;
            x3++;
        }
        int xn = 0;
        xn += (ll)x1 * a.mat[0][2] % (mod - 1); if (xn >= mod - 1) xn -= mod - 1;
        xn += (ll)x2 * a.mat[1][2] % (mod - 1); if (xn >= mod - 1) xn -= mod - 1;
        xn += (ll)x3 * a.mat[2][2] % (mod - 1); if (xn >= mod - 1) xn -= mod - 1;
        ans = (ll)ans * binpow(p, xn, mod) % mod;
    }
    cout << ans << endl;
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