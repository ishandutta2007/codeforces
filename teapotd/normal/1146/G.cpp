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

struct Banned {
    int begin, end, height, cost;
    bool operator<(const Banned& r) const {
        return height < r.height;
    }
};

int dp[51][51][51]; // (begin, end, height) -> profit
vector<Banned> bans;

int solve(int begin, int end, int height) {
    int& ret = dp[begin][end][height];
    if (ret >= 0) return ret;
    ret = 0;

    rep(i, begin, end) {
        int cost = 0, j = 0;

        rep(h, 0, height+1) {
            while (j < sz(bans)) {
                auto& b = bans[j];
                if (b.height >= h) break;
                if (b.begin >= begin && b.end <= end && b.begin <= i && b.end >= i+1) {
                    cost += b.cost;
                }
                j++;
            }
            ret = max(ret, solve(begin, i, h) + solve(i+1, end, h) - cost + h*h);
        }
    }

    return ret;
}

void run() {
    int n, h, m; cin >> n >> h >> m;
    bans.resize(m);

    each(b, bans) {
        cin >> b.begin >> b.end >> b.height >> b.cost;
        b.begin--;
    }

    sort(all(bans));
    rep(i, 0, n+1) rep(j, 0, n+1) rep(k, 0, h+1) dp[i][j][k] = -1;
    cout << solve(0, n, h) << endl;
}