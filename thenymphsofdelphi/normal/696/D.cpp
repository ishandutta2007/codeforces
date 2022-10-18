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

const int N = 2e2 + 5, base = 26;
const ll infll = (ld)1e18 + 7;

struct node_aho{
    int par, vpar;
    int nxt[base];
    int cntend = 0;
    int go[base], link, exlink;

    node_aho(int par = -1, int vpar = -1): par(par), vpar(vpar){
        memset(nxt, -1, sizeof(nxt));
        memset(go, -1, sizeof(go)); link = exlink = -1;
    }
};

void add_string(vector <node_aho>& aho, const string& s, int val){
    assert(isz(aho) >= 1);
    int u = 0;
    Fora(c, s){
        if (aho[u].nxt[c - 'a'] == -1){
            aho.emplace_back(u, c - 'a');
            aho[u].nxt[c - 'a'] = isz(aho) - 1;
        }
        u = aho[u].nxt[c - 'a'];
    }
    aho[u].cntend += val;
}

int link(vector <node_aho>& aho, int u);

int go(vector <node_aho>& aho, int u, int c){
    if (aho[u].go[c] != -1){
        return aho[u].go[c];
    }
    if (aho[u].nxt[c] != -1){
        return (aho[u].go[c] = aho[u].nxt[c]);
    }
    if (u == 0){
        return (aho[u].go[c] = 0);
    }
    return (aho[u].go[c] = go(aho, link(aho, u), c));
}

int link(vector <node_aho>& aho, int u){
    if (aho[u].link != -1){
        return aho[u].link;
    }
    if (u == 0 or aho[u].par == 0){
        return (aho[u].link = 0);
    }
    return (aho[u].link = go(aho, link(aho, aho[u].par), aho[u].vpar));
}

int exlink(vector <node_aho>& aho, int u){
    if (aho[u].exlink != -1){
        return aho[u].exlink;
    }
    if (u == 0 or aho[u].par == 0){
        return (aho[u].exlink = 0);
    }
    if (aho[link(aho, u)].cntend){
        return (aho[u].exlink = aho[u].link);
    }
    return (aho[u].exlink = exlink(aho, aho[u].link));
}

void cal_aho(vector <node_aho>& aho){
    For(u, 0, isz(aho)){
        exlink(aho, u);
    }
}

struct matrix: vector <vector <ll>>{
    matrix(int n = 0){
        this->assign(n, vector <ll>(n));
    }

    friend matrix operator* (const matrix& lhs, const matrix& rhs){
        matrix ans(isz(lhs));
        For(i, 0, isz(lhs)){
            For(j, 0, isz(lhs)){
                ans[i][j] = -infll;
                For(k, 0, isz(lhs)){
                    ans[i][j] = max(ans[i][j], lhs[i][k] + rhs[k][j]);
                }
            }
        }
        return ans;
    }

    friend matrix pow(matrix lhs, ll rhs){
        matrix ans(isz(lhs));
        For(i, 0, isz(lhs)){
            For(j, 0, isz(lhs)){
                if (i == j){
                    ans[i][j] = 0;
                }
                else{
                    ans[i][j] = -infll;
                }
            }
        }
        while (rhs){
            if (rhs & 1){
                ans = ans * lhs;
            }
            lhs = lhs * lhs;
            rhs >>= 1;
        }
        return ans;
    }

    friend vector <ll> operator* (const matrix& lhs, const vector <ll>& rhs){
        vector <ll> ans(isz(lhs));
        For(i, 0, isz(lhs)){
            ans[i] = -infll;
            For(k, 0, isz(lhs)){
                ans[i] = max(ans[i], lhs[i][k] + rhs[k]);
            }
        }
        return ans;
    }
};

int n; ll k;
int a[N];
string s[N];

int val[N];
vector <node_aho> aho(1);

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> s[i];
        add_string(aho, s[i], a[i]);
    }
    cal_aho(aho);
    matrix ma(isz(aho));
    vector <ll> mb(isz(aho));
    For(i, 0, isz(aho)){
        For(j, 0, isz(aho)){
            ma[i][j] = -infll;
        }
        mb[i] = -infll;
    }
    mb[0] = 0;
    For(i, 0, isz(aho)){
        int u = i;
        while (u){
            if (aho[u].cntend){
                val[i] += aho[u].cntend;
            }
            u = exlink(aho, u);
        }
    }
    For(u, 0, isz(aho)){
        For(j, 0, 26){
            int v = go(aho, u, j);
            ma[v][u] = val[v];
        }
    }
    ma = pow(ma, k);
    mb = ma * mb;
    ll ans = 0;
    For(i, 0, isz(aho)){
        ans = max(ans, mb[i]);
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