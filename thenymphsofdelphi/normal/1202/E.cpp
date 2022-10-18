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

const int N = 2e5 + 5, base = 26;

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

void add_string(vector <node_aho>& aho, const string& s){
    assert(isz(aho) >= 1);
    int u = 0;
    Fora(c, s){
        if (aho[u].nxt[c - 'a'] == -1){
            aho.emplace_back(u, c - 'a');
            aho[u].nxt[c - 'a'] = isz(aho) - 1;
        }
        u = aho[u].nxt[c - 'a'];
    }
    aho[u].cntend++;
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

string t;
int n;
string s[N];

vector <node_aho> aho(1);
vector <node_aho> raho(1);

vi vcnt, vrcnt;

void traverse(vector <node_aho>& aho, const string& t, vi& vcnt){
    int u = 0;
    For(i, 0, isz(t)){
        u = go(aho, u, t[i] - 'a');
        int tu = u;
        while (tu){
            if (aho[tu].cntend){
                vcnt[i] += aho[tu].cntend;
            }
            tu = exlink(aho, tu);
        }
    }
}

ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> t;
    cin >> n;
    ForE(i, 1, n){
        cin >> s[i];
        add_string(aho, s[i]);
        reverse(bend(s[i]));
        add_string(raho, s[i]);
    }
    vcnt.resize(isz(t));
    vrcnt.resize(isz(t));
    traverse(aho, t, vcnt);
    reverse(bend(t));
    traverse(raho, t, vrcnt);
    reverse(bend(vrcnt));
    For(i, 1, isz(t)){
        ans += (ll)vcnt[i - 1] * vrcnt[i];
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