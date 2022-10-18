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

int n, ans;
int pa[N], pb[N];
vi adja[N], adjb[N];

int timb, lb[N], rb[N];

void dfsb(int u){
    lb[u] = ++timb;
    Fora(&v, adjb[u]){
        dfsb(v);
    }
    rb[u] = timb;
}

set <pii> stt;
int stterase[N];

void insert(int u){
    stterase[u] = -1;
    if (isz(stt)){
        auto itr = stt.lower_bound(make_pair(lb[u], u));
        if (itr != stt.begin()){
            itr--;
            if (rb[itr->se] >= rb[u]){
                stterase[u] = itr->se;
                stt.erase(itr);
            }
        }
    }
    stt.insert(make_pair(lb[u], u));
}

void erase(int u){
    if (stterase[u] != -1){
        stt.insert(make_pair(lb[stterase[u]], stterase[u]));
    }
    stt.erase(make_pair(lb[u], u));
}

void dfsa(int u){
    insert(u);
    ans = max(ans, isz(stt));
    Fora(&v, adja[u]){
        dfsa(v);
    }
    erase(u);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n;
    ForE(i, 1, n){
        adja[i].clear();
        adjb[i].clear();
    }
    ForE(i, 2, n){
        cin >> pa[i];
        adja[pa[i]].emplace_back(i);
    }
    ForE(i, 2, n){
        cin >> pb[i];
        adjb[pb[i]].emplace_back(i);
    }
    timb = 0;
    dfsb(1);
    ans = 0;
    dfsa(1);
    cout << ans << endl;
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