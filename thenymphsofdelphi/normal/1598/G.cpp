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

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int randt(int l, int r){
    return rando() % (r - l + 1) + l;
}

const int N = 5e5 + 5, M = 2e5 + 5;

int z[N + M];

void z_function(string s){
    int n = s.length(); s = ' ' + s;
    z[1] = 0;
    int l = 0, r = 0;
    ForE(i, 2, n){
        if (r < i){
            l = i;
            r = i;
            while (r <= n && s[r] == s[r - l + 1]){
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else{
            int k = i - l + 1;
            if (z[k] < r - i){
                z[i] = z[k];
            }
            else{
                l = i;
                while (r <= n && s[r] == s[r - l + 1]){
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
}

int n;
string s;
int m;
string sx;

pii mod;

bool isprime(int x){
    if (x <= 1){
        return 0;
    }
    if (x <= 3){
        return 1;
    }
    if (x % 2 == 0 or x % 3 == 0){
        return 0;
    }
    for (int i = 5; i * i <= x; i += 6){
        if (x % i == 0 or x % (i + 2) == 0){
            return 0;
        }
    }
    return 1;
}

pii pw10[N];
pii hashs[N], hashsx;

pii calhashs(int l, int r){
    pii ans = {hashs[r].fi - (ll)hashs[l - 1].fi * pw10[r - l + 1].fi % mod.fi, hashs[r].se - (ll)hashs[l - 1].se * pw10[r - l + 1].se % mod.se};
    if (ans.fi < 0){
        ans.fi += mod.fi;
    }
    if (ans.se < 0){
        ans.se += mod.se;
    }
    return ans;
}

void check(int l1, int r1, int l2, int r2){
    if (1 > l1 or l1 > r1 or r1 != l2 - 1 or l2 > r2 or r2 > n){
        return;
    }
    pii hash1 = calhashs(l1, r1), hash2 = calhashs(l2, r2);
    hash1.fi += hash2.fi;
    if (hash1.fi >= mod.fi){
        hash1.fi -= mod.fi;
    }
    hash1.se += hash2.se;
    if (hash1.se >= mod.se){
        hash1.se -= mod.se;
    }
    if (hash1 == hashsx){
        cout << l1 << ' ' << r1 << endl << l2 << ' ' << r2 << endl;
        exit(0);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> s >> sx;
    n = isz(s); m = isz(sx);
    z_function(sx + '#' + s);
    s = ' ' + s; sx = ' ' + sx;
    {
        mod.fi = randt(500000000, 1000000000);
        while (!isprime(mod.fi)){
            mod.fi++;
        }
        mod.se = randt(500000000, 1000000000);
        while (!isprime(mod.se)){
            mod.se++;
        }
        pw10[0] = {1, 1};
        For(i, 1, N){
            pw10[i] = {(ll)pw10[i - 1].fi * 10 % mod.fi, (ll)pw10[i - 1].se * 10 % mod.se};
        }
        ForE(i, 1, n){
            hashs[i] = {((ll)hashs[i - 1].fi * 10 + s[i] - '0') % mod.fi, ((ll)hashs[i - 1].se * 10 + s[i] - '0') % mod.se};
        }
        ForE(i, 1, m){
            hashsx = {((ll)hashsx.fi * 10 + sx[i] - '0') % mod.fi, ((ll)hashsx.se * 10 + sx[i] - '0') % mod.se};
        }
    }

    ForE(i, 1, n){
        check(i - m + 1, i - 1, i, i + m - 2);
        int len = m - z[m + 1 + i];
        check(i - len, i - 1, i, i + m - 1);
        check(i - len + 1, i - 1, i, i + m - 1);
        check(i, i + m - 1, i + m, i + m + len - 1);
        check(i, i + m - 1, i + m, i + m + len - 2);
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