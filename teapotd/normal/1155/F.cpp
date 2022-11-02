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

constexpr int MAX_N = 14;
constexpr int INF = 10000;

bool G[MAX_N][MAX_N], H[MAX_N][MAX_N];
bool ham[1<<MAX_N][MAX_N][MAX_N];
int dp[1<<MAX_N];
int n, m;

int hamPrev[1<<MAX_N][MAX_N][MAX_N];
pair<int, pair<int, int>> dpPrev[1<<MAX_N];

void run() {
    cin >> n >> m;
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        G[a-1][b-1] = G[b-1][a-1] = 1;
    }

    rep(i, 0, n) {
        ham[1<<i][i][i] = 1;
        hamPrev[1<<i][i][i] = -1;
    }

    rep(i, 0, 1<<n) {
        if (__builtin_popcount(i) < 2) continue;
        rep(a, 0, n) rep(b, 0, n) {
            if (a == b || !((i>>a)&1) || !((i>>b)&1)) continue;
            int tmp = i & ~(1 << b);
            rep(j, 0, n) {
                if (G[b][j] && ham[tmp][a][j]) {
                    ham[i][a][b] = 1;
                    hamPrev[i][a][b] = j;
                    break;
                }
            }
        }
    }

    rep(i, 0, 1<<n) {
        if (__builtin_popcount(i) <= 2) continue;
        rep(a, 0, n) rep(b, 0, n) {
            if (a != b && ham[i][a][b] && G[a][b]) {
                ham[i][a][a] = 1;
                hamPrev[i][a][a] = b;
            }
        }
    }

    rep(i, 0, 1<<n) dp[i] = INF;

    dp[0] = 0;
    dpPrev[0] = {-1, {-1, -1}};

    rep(i, 0, n) {
        dp[1<<i] = 0;
        dpPrev[1<<i] = {-1, {-1, -1}};
    }

    rep(i, 0, 1<<n) {
        if (__builtin_popcount(i) < 2) continue;

        for (int j = i; j > 0; j = (j-1) & i) {
            int add = __builtin_popcount(j) - 1;

            rep(a, 0, n) {
                if (!((j>>a)&1)) continue;
                rep(b, 0, n) {
                    if (!((j>>b)&1)) continue;

                    int k = j & ~(1<<a) & ~(1<<b);
                    if (k == 0) continue;

                    if (ham[j][a][b]) {
                        int alt = dp[i&~k] + add + (a == b);
                        if (alt < dp[i]) {
                            dp[i] = alt;
                            dpPrev[i] = {j, {a,b}};
                        }
                    }
                }
            }
        }
    }

    int cur = (1<<n)-1;

    while (__builtin_popcount(cur) > 1) {
        int mask = dpPrev[cur].x;
        int a = dpPrev[cur].y.x, b = dpPrev[cur].y.y;

        while (__builtin_popcount(mask) > 1) {
            int p = hamPrev[mask][a][b];
            H[p][b] = H[b][p] = 1;
            if (a != b) mask &= ~(1 << b);
            b = p;
        }

        int nxt = cur & ~dpPrev[cur].x;
        nxt |= (1 << dpPrev[cur].y.x) | (1 << dpPrev[cur].y.y);
        cur = nxt;
    }

    cout << dp[(1<<n)-1] << '\n';

    rep(i, 0, n) rep(j, i+1, n) {
        if (H[i][j]) {
            cout << i+1 << ' ' << j+1 << '\n';
        }
    }
}