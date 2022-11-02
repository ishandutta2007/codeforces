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

mt19937 rnd(int(time(0)));

bool check(vector<Pii>& cells) {
    vector<Pii> seen;
    rep(i, 1, sz(cells)) {
        Pii a = cells[i-1], b = cells[i];
        seen.pb({b.x-a.x, b.y-a.y});
    }
    sort(all(seen));
    return unique(all(seen)) == seen.end();
}

void solve(int n, int m) {
    vector<Pii> ans;

    for (int i = 0; i <= n-i-1; i++) {
        if (i != n-i-1) {
            rep(j, 0, m) {
                ans.pb({i, j});
                ans.pb({n-i-1, m-j-1});
            }
        } else {
            for (int j = 0; j <= m-j-1; j++) {
                ans.pb({i, j});
                if (j != m-j-1) ans.pb({i, m-j-1});
            }
        }
    }

    //assert(sz(ans) == n*m);
    //assert(check(ans));

    each(p, ans) {
        cout << p.x+1 << ' ' << p.y+1 << '\n';
    }
}

void run() {
    int n, m; cin >> n >> m;
    solve(n, m);
}