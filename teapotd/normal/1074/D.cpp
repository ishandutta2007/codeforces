#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

struct Node {
    int par{-1}, val{0};
};

map<int, Node> fau;
int last = 0;

Pii find(int i) {
    auto& n = fau[i];
    if (n.par == -1) return {i, n.val};

    auto xd = find(n.par);
    Pii ret = { xd.x, xd.y^n.val };
    n.val ^= xd.y ^ fau[xd.x].val;
    n.par = xd.x;
    return ret;
}

void handle() {
    int t, l, r, x;
    cin >> t >> l >> r;
    l ^= last;
    r ^= last;

    if (l > r) swap(l, r);
    r++;

    if (t == 1) {
        cin >> x;
        x ^= last;

        Pii a = find(l), b = find(r);

        if (a.x != b.x) {
            if (rand()%2) swap(a, b);
            auto& n = fau[b.x];
            n.par = a.x;
            n.val ^= a.y^b.y^x;
        }
    } else {
        Pii a = find(l), b = find(r);

        if (a.x != b.x) {
            cout << -1 << '\n';
            last = 1;
        } else {
            last = a.y^b.y;
            cout << last << '\n';
        }
    }
}

void run() {
    int q; cin >> q;
    while (q--) handle();
}