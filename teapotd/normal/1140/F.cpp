#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

struct Node {
    int par{-1}, lvl{0}, odd{0}, even{0};
};

vector<vector<Pii>> tree;
int len;
vector<Node> fau;
vector<ll> ans;
ll cur;

int root(int i) {
    while (fau[i].par != -1) i = fau[i].par;
    return i;
}

void add(int vBegin, int vEnd, Pii p, int i, int begin, int end) {
    if (vBegin >= end || begin >= vEnd) return;

    if (begin >= vBegin && end <= vEnd) {
        tree[i].pb(p);
        return;
    }

    int mid = (begin+end) / 2;
    add(vBegin, vEnd, p, i*2, begin, mid);
    add(vBegin, vEnd, p, i*2+1, mid, end);
}

void solve(int i) {
    vector<pair<int, Node>> toRestore;
    ll oldCur = cur;

    each(e, tree[i]) {
        int a = root(e.x*2), b = root(e.y*2+1);
        if (a == b) continue;
        if (fau[a].lvl < fau[b].lvl) swap(a, b);

        toRestore.push_back({a, fau[a]});
        toRestore.push_back({b, fau[b]});

        cur -= ll(fau[a].odd)*fau[a].even;
        cur -= ll(fau[b].odd)*fau[b].even;

        if (fau[a].lvl == fau[b].lvl) fau[a].lvl++;
        fau[b].par = a;
        fau[a].odd += fau[b].odd;
        fau[a].even += fau[b].even;
        cur += ll(fau[a].odd)*fau[a].even;
    }

    if (i >= len) {
        ans[i-len] = cur;
    } else {
        solve(i*2);
        solve(i*2+1);
    }

    while (!toRestore.empty()) {
        auto& top = toRestore.back();
        fau[top.x] = top.y;
        toRestore.pop_back();
    }
    cur = oldCur;
}

void run() {
    int q; cin >> q;
    map<Pii, int> seen;

    for (len = 1; len < q; len *= 2);
    tree.resize(len*2);

    rep(i, 0, q) {
        Pii p; cin >> p.x >> p.y;
        if (seen.count(p)) {
            int j = seen[p];
            seen.erase(p);
            add(j, i, p, 1, 0, len);
        } else {
            seen[p] = i;
        }
    }

    each(e, seen) {
        add(e.y, q, e.x, 1, 0, len);
    }

    ans.resize(len);
    fau.resize(6*1e5+5);

    rep(i, 0, sz(fau)) {
        if (i%2) fau[i].odd = 1;
        else fau[i].even = 1;
    }

    solve(1);
    rep(i, 0, q) cout << ans[i] << ' ';
    cout << '\n';
}