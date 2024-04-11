#pragma GCC optimize("Ofast")
/* #pragma GCC optimize("inline")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native") */

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (int)1e9
#define mod 998244353
#define maxn 300010
#define maxc 26

int i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
int q, ty, f[maxn], cr[maxn];
char c;
string s;

struct node {
    int jm[maxc], go[maxc], pr = -1, lk = -1, lkf = -1;
    multiset<int> ss;
    bool lf = false;
    char pc = '$';

    node(int pr = -1, char pc = '$'): pr(pr), pc(pc) {
        int i;
        for (i = 0; i < maxc; i++) {
            jm[i] = -1; go[i] = -1;
        }
    }
};

vector<node> tr(1);

int ins(string s) {
    int p = 0;
    for (auto c : s) {
        int x = (int)c - 'a';
        if (tr[p].jm[x] == -1) {
            tr[p].jm[x] = tr.size(); tr.emplace_back(p, c);
        }
        p = tr[p].jm[x];
    }
    tr[p].lf = true; tr[p].ss.insert(0); return p;
}

int find_go(int p, char c);

int find_lk(int p) {
    // cout << "find_lk" _ p << nf;
    if (tr[p].lk == -1) {
        if (p == 0 || tr[p].pr == 0) tr[p].lk = 0;
        else tr[p].lk = find_go(find_lk(tr[p].pr), tr[p].pc);
    }
    return tr[p].lk;
}

int find_go(int p, char c) {
    // cout << "find_go" _ p _ c << nf;
    int x = (int)c - 'a';
    if (tr[p].go[x] == -1) {
        if (tr[p].jm[x] != -1) tr[p].go[x] = tr[p].jm[x];
        else if (p == 0) tr[p].go[x] = 0;
        else tr[p].go[x] = find_go(find_lk(p), c);
    }
    return tr[p].go[x];
}

int find_lkf(int p) {
    // cout << "find_lkf" _ p << nf;
    if (p == 0) return 0;
    if (tr[p].lkf == -1) {
        find_lk(p);
        if (tr[tr[p].lk].lf) tr[p].lkf = tr[p].lk;
        else tr[p].lkf = find_lkf(tr[p].lk);
    }
    // cout << "lkf =" _ tr[p].lkf << nf;
    return tr[p].lkf;
}

int find_max(int p) {
    int r = -1;
    // cout << "find_max" _ p << nf;
    while (true) {
        if (p == -1) return r;
        find_lkf(p);
        if (!tr[p].lf) {
            p = tr[p].lkf; continue;
        }
        auto it = tr[p].ss.end(); it--;
        // cout << "find_max found" _ (*it) << nf;
        r = max(r, (*it)); p = tr[p].lkf;
    }
}

int inspect(string t) {
    int p = 0, r = -1;
    for (auto c : t) {
        int x = (int)c - 'a';
        find_go(p, c);
        p = tr[p].go[x]; r = max(r, find_max(p));
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n >> q;
    for (i = 1; i <= n; i++) {
        cin >> s; f[i] = ins(s);
    }

    /* for (i = 1; i <= n; i++) cout << f[i] << ' ';
    cout << nl; */

    /* for (i = 0; i < tr.size(); i++) {
        cout << "node" _ i << nl;
        cout << tr[i].lf _ tr[i].lk _ tr[i].lkf << nl;
    } */

    while (q--) {
        cin >> ty;
        if (ty == 1) {
            cin >> a >> b;
            tr[f[a]].ss.erase(tr[f[a]].ss.find(cr[a]));
            tr[f[a]].ss.insert(b); cr[a] = b;
        } else {
            cin >> s;
            cout << inspect(s) << nl;
        }
    }

    return 0;
}