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

constexpr int MAX_N = 1005;
constexpr int LCM = 2520;

Pii nxt[MAX_N][LCM];
int seen[MAX_N][LCM], ans[MAX_N][LCM];
int inSet[MAX_N];
int cnt;

void compute(int i, int j) {
    cnt++;
    while (!seen[i][j]) {
        seen[i][j] = cnt;
        tie(i, j) = nxt[i][j];
    }

    if (seen[i][j] != cnt) {
        return;
    }

    cnt++;
    int tot = 0;

    while (seen[i][j] != cnt) {
        if (inSet[i] != cnt) {
            inSet[i] = cnt;
            tot++;
        }
        seen[i][j] = cnt;
        tie(i, j) = nxt[i][j];
    }

    assert(tot > 0);
    cnt++;

    while (seen[i][j] != cnt) {
        seen[i][j] = cnt;
        ans[i][j] = tot;
        tie(i, j) = nxt[i][j];
    }
}

void dfs(int i, int j) {
    if (ans[i][j]) return;
    Pii t = nxt[i][j];
    dfs(t.x, t.y);
    ans[i][j] = ans[t.x][t.y];
}

void run() {
    int n; cin >> n;
    Vi add(n);
    Vi edges;

    each(a, add) {
        cin >> a;
        a %= LCM;
        if (a < 0) a += LCM;
    }

    rep(i, 0, n) {
        int k; cin >> k;
        edges.resize(k);

        each(e, edges) {
            cin >> e;
            e--;
        }

        rep(j, 0, LCM) {
            int tmp = (j + add[i]) % LCM;
            int e = edges[tmp%k];
            nxt[i][j] = {e, tmp};
        }
    }

    rep(i, 0, n) rep(j, 0, LCM) {
        compute(i, j);
    }

    rep(i, 0, n) rep(j, 0, LCM) {
        dfs(i, j);
    }

    int q; cin >> q;

    while (q--) {
        int x, y; cin >> x >> y;
        x--;
        y %= LCM;
        if (y < 0) y += LCM;
        cout << ans[x][y] << '\n';
    }
}