#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 4e5 + 5, mod = 998244353;

void sadd(int& x, int y){
    if ((x += y) >= mod) x -= mod;
    return;
}

int add(int x, int y){
    if ((x += y) >= mod) x -= mod;
    return x;
}

void ssub(int& x, int y){
    if ((x -= y) < 0) x += mod;
    return;
}

int sub(int x, int y){
    if ((x -= y) < 0) x += mod;
    return x;
}

int mul(int x, int y){
    return 1ll * x * y % mod;
}

int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}

int inv(int x){
    return binpow(x, mod - 2);
}

#define div __div__
int div(int x, int y){
    return mul(x, binpow(y, mod - 2));
}

struct portal{
    char type; int id, pos;

    portal(char type = '?', int id = 0, int pos = 0): type(type), id(id), pos(pos){

    }
};

bool operator< (const portal& lhs, const portal& rhs){
    return lhs.pos < rhs.pos;
}

int n;
int x[N], y[N], s[N];

portal a[N];
int posx[N], posy[N];

int dp[N], prefdp[N];
int ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> x[i] >> y[i] >> s[i];
    }
    ForE(i, 1, n){
        a[i] = portal('x', i, x[i]);
        a[i + n] = portal('y', i, y[i]);
    }
    sort(a + 1, a + 2 * n + 1);
    ForE(i, 1, 2 * n){
        if (a[i].type == 'x'){
            posx[a[i].id] = i;
        }
        else{
            posy[a[i].id] = i;
        }
    }

    ans = (x[n] + 1) % mod;
    ForE(i, 1, 2 * n){
        if (a[i].type == 'x'){
            dp[i] = add((a[i].pos - a[posy[a[i].id]].pos) % mod, sub(prefdp[i - 1], prefdp[posy[a[i].id]]));
            if (s[a[i].id]){
                ans = add(ans, dp[i]);
            }
        }
        prefdp[i] = add(prefdp[i - 1], dp[i]);
    }
    cout << ans << endl;
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------+

--------------------------------------------------+
==================================================+
OUTPUT                                            |
--------------------------------------------------+

--------------------------------------------------+
==================================================+
*/