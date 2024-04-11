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

struct FAU {
    Vi G;
    FAU(int n = 0) : G(n, -1) {}
    int size(int i) { return -G[find(i)]; }
    int find(int i) { return G[i] < 0 ? i : G[i] = find(G[i]); }
    bool join(int i, int j) {
        i = find(i); j = find(j);
        if (i == j) return 0;
        if (G[i] > G[j]) swap(i, j);
        G[i] += G[j]; G[j] = i;
        return 1;
    }
};

ll ch2(ll k) {
    return k*(k-1) / 2;
}

void run() {
    int n, m; cin >> n >> m;
    vector<pair<int, Pii>> edges(n-1);

    each(e, edges) {
        cin >> e.y.x >> e.y.y >> e.x;
        e.y.x--; e.y.y--;
    }

    FAU fau(n);
    ll cnt = 0;
    sort(all(edges));

    vector<pair<int, ll>> ans;
    ans.pb({0, 0});

    each(e, edges) {
        int a = fau.find(e.y.x), b = fau.find(e.y.y);
        assert(a != b);

        int s1 = fau.size(a), s2 = fau.size(b);
        cnt += ch2(s1+s2) - ch2(s1) - ch2(s2);
        fau.join(a, b);

        if (ans.back().x < e.x) {
            ans.pb({e.x, cnt});
        } else {
            ans.back().y = cnt;
        }
    }

    rep(i, 0, m) {
        int k; cin >> k;
        auto it = --upper_bound(all(ans), make_pair(k, ll(1e18)));
        cout << it->y << ' ';
    }
    cout << endl;
}