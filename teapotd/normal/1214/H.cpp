#define _USE_MATH_DEFINES
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

int n, k;
vector<Vi> G;
Vi dist, longest, par, col;

int dfs(int v, int p) {
    int far = v;
    longest[v] = 1;
    par[v] = p;

    each(e, G[v]) if (e != p) {
        dist[e] = dist[v]+1;
        col[e] = !col[v];
        int alt = dfs(e, v);
        if (dist[alt] > dist[far]) far = alt;
        longest[v] = max(longest[v], longest[e]+1);
    }

    return far;
}

void check(int v, int p, int up) {
    int l1 = up, l2 = 0, l3 = 0;

    each(e, G[v]) if (e != p) {
        int alt = longest[e];
        if (alt >= l1) {
            l3 = l2;
            l2 = l1;
            l1 = alt;
        } else if (alt >= l2) {
            l3 = l2;
            l2 = alt;
        } else if (alt >= l3) {
            l3 = alt;
        }
    }

    if (l3 > 0 && l2+l3 >= k-1) {
        cout << "No" << endl;
        exit(0);
    }

    each(e, G[v]) if (e != p) {
        int tmp = (longest[e] == l1 ? l2 : l1);
        check(e, v, tmp+1);
    }
}

void color(int v, int p, int c, int inc) {
    int nc = (c+inc+k) % k;
    col[v] = c;

    each(e, G[v]) if (e != p) {
        color(e, v, nc, inc);
    }
}

void run() {
    cin >> n >> k;
    G.resize(n);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    dist.resize(n);
    longest.resize(n);
    par.resize(n);
    col.resize(n);

    int far1 = dfs(0, -1);

    if (k > 2) {
        check(0, -1, 0);

        int far2 = dfs(far1, -1);
        Vi diameter;

        for (int v = far2; v != -1; v = par[v]) {
            diameter.pb(v);
        }

        int m = sz(diameter);
        int a = diameter[m/2], b = diameter[m/2-1];

        color(a, b, 0, -1);
        color(b, a, 1, 1);
    }

    cout << "Yes\n";
    each(c, col) cout << c+1 << ' ';
    cout << '\n';
}