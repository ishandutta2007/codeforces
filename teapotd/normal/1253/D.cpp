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
#define mp make_pair/////////////////////////////////////////////
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

int n, m, cnt;
vector<Vi> G;
Vi seen;
int sm, gr;

Vi kek, ver;
int curVer, ans;

void dfs(int v) {
    if (seen[v]) return;
    seen[v] = cnt;
    sm = min(sm, v);
    gr = max(gr, v);
    each(e, G[v]) dfs(e);
}

void check(int begin, int end) {
    if (begin >= end) return;
    curVer++;
    ans--;
    rep(i, begin, end) {
        int e = seen[i];
        if (ver[e] != curVer) {
            ver[e] = curVer;
            kek[e] = 0;
        }
        if (kek[e] == 0) {
            ans++;
        }
        kek[e]++;
    }
}

void run() {
    cin >> n >> m;
    G.resize(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }

    Vi events(n);
    seen.resize(n);

    rep(i, 0, n) {
        if (!seen[i]) {
            cnt++;
            sm = INT_MAX;
            gr = INT_MIN;
            dfs(i);
            events[sm]++;
            events[gr]--;
        }
    }

    int sum = 0;
    int left = 0;

    kek.resize(n+5);
    ver.resize(n+5);

    rep(i, 0, n) {
        sum += events[i];
        if (sum == 0) {
            check(left, i+1);
            left = i+1;
        }
    }

    check(left, n);
    cout << ans << endl;
}