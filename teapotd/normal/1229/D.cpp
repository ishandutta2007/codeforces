#define _USE_MATH_DEFINES////////////////////////////////////////
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

using Perm = array<int, 5>;

struct Subgroup {
    Vi elems, base;
    bool operator==(const Subgroup& r) const { return elems < r.elems; }
    bool operator<(const Subgroup& r) const { return elems < r.elems; }
};

vector<Perm> perms;
vector<Vi> comp, prod;
vector<Subgroup> subgroups;
Vi single;

Perm compose(Perm a, Perm b) {
    Perm c;
    rep(i, 0, 5) c[i] = a[b[i]];
    return c;
}

int permInd(Perm p) {
    return int(lower_bound(all(perms), p) - perms.begin());
}

Subgroup genSubgroup(Vi base) {
    sort(all(base));
    base.erase(unique(all(base)), base.end());

    set<int> seen = {0};
    queue<int> que;
    each(e, base) que.push(e);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (!seen.insert(v).y) continue;
        each(e, base) que.push(comp[e][v]);
    }

    return {Vi(all(seen)), base};
}

void precomp() {
    Perm perm = {0,1,2,3,4};
    do {
        perms.pb(perm);
    } while (next_permutation(all(perm)));

    comp.resize(sz(perms), Vi(sz(perms)));

    rep(i, 0, sz(perms)) rep(j, 0, sz(perms)) {
        comp[i][j] = permInd(compose(perms[i], perms[j]));
    }

    set<Subgroup> seen;
    queue<Subgroup> que;
    rep(i, 0, sz(perms)) que.push(genSubgroup({i}));

    while (!que.empty()) {
        auto v = que.front();
        que.pop();
        if (!seen.insert(v).y) continue;
        rep(i, 1, sz(perms)) {
            Vi tmp = v.base;
            tmp.pb(i);
            que.push(genSubgroup(tmp));
        }
    }

    subgroups = {all(seen)};
    prod.resize(sz(subgroups), Vi(sz(subgroups)));

    rep(i, 0, sz(prod)) rep(j, 0, sz(prod)) {
        Vi tmp = subgroups[i].base;
        tmp.insert(tmp.end(), all(subgroups[j].base));
        Subgroup sub = genSubgroup(tmp);
        auto it = lower_bound(all(subgroups), sub);
        prod[i][j] = int(it - subgroups.begin());
    }

    single.resize(sz(perms));

    rep(i, 0, sz(perms)) {
        Subgroup sub = genSubgroup({i});
        auto it = lower_bound(all(subgroups), sub);
        single[i] = int(it - subgroups.begin());
    }
}

void run() {
    precomp();

    int n, k; cin >> n >> k;
    Vi elems(n);

    rep(j, 0, n) {
        Perm perm;
        rep(i, 0, k) {
            cin >> perm[i];
            perm[i]--;
        }

        rep(i, k, 5) perm[i] = i;

        int p = int(lower_bound(all(perms), perm) - perms.begin());
        elems[j] = single[p];
    }

    vector<Pii> segs, old;
    ll ans = 0;

    rep(i, 0, n) {
        int e = elems[i];
        segs.swap(old);
        segs.clear();

        each(s, old) {
            int alt = prod[s.x][e];
            if (segs.empty() || segs.back().x != alt) {
                segs.pb({alt, s.y});
            }
        }

        if (segs.empty() || segs.back().x != e) {
            segs.pb({e, i});
        }

        rep(j, 0, sz(segs)) {
            int end = (j+1 < sz(segs) ? segs[j+1].y : i+1);
            ans += ll(end-segs[j].y) * sz(subgroups[segs[j].x].elems);
        }
    }

    cout << ans << endl;
}