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

// codechef DOOFST

vector<Vi> G;
set<int> avail;
Vi id;
int cnt = 0;

void dfs(int v) {
    int u = -1;
    avail.erase(v);
    id[v] = cnt;

    while (true) {
        auto it = avail.upper_bound(u);
        if (it == avail.end()) break;

        u = *it;
        auto fb = lower_bound(all(G[v]), u);

        if (fb == G[v].end() || *fb != u) {
            dfs(u);
        }
    }
}

void run() {
    int n, m; cin >> n >> m;
    G.resize(n);
    id.resize(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    rep(i, 0, n) {
        sort(all(G[i]));
        avail.insert(i);
    }

    while (!avail.empty()) {
        dfs(*avail.begin());
        cnt++;
    }

    if (cnt != 3) {
        cout << "-1\n";
        return;
    }

    rep(v, 0, n) {
        each(e, G[v]) {
            if (id[v] == id[e]) {
                cout << "-1\n";
                return;
            }
        }
    }

    rep(i, 0, n) {
        cout << id[i]+1 << ' ';
    }
    cout << '\n';
}