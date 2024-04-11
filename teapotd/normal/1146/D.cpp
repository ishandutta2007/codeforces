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

bool seen[500005];
int cnt = 1, lim, a, b, m;

int gcd(int x, int y) {
    while (y) {
        x %= y;
        swap(x, y);
    }
    return x;
}

void dfs(int i) {
    if (i < 0 || i > lim || seen[i]) return;
    seen[i] = 1;
    cnt++;
    dfs(i-b);
    dfs(i+a);
}

ll sq(ll to, ll g) {
    ll parts = to/g;
    ll ret = parts*(parts+1) / 2 * g;
    for (ll k = parts*g; k < to; k++) ret += k/g+1;
    return ret;
}

void run() {
    cin >> m >> a >> b;

    int naive = min(m, (a+b)*2+1);
    ll ans = 1;
    seen[0] = 1;

    rep(i, 1, naive+1) {
        if (i-a >= 0 && seen[i-a]) {
            lim = i;
            dfs(i);
        }
        ans += cnt;
    }

    int g = gcd(a, b);
    ans += sq(m+1, g);
    ans -= sq(naive+1, g);
    cout << ans << endl;
}