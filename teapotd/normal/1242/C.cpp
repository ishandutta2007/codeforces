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

int k;
ll wanted;
vector<Vi> boxes;
vector<vector<Pii>> nxt;

vector<bool> cycle, dp;
vector<Pii> cycleStart;

void run() {
    cin >> k;
    boxes.resize(k);

    map<ll, Pii> numToBox;
    ll sum = 0;

    each(box, boxes) {
        int n; cin >> n;
        box.resize(n);
        each(b, box) {
            cin >> b;
            sum += b;
        }
    }

    if (sum % k) {
        cout << "No\n";
        return;
    }

    wanted = sum/k;
    nxt.resize(k);

    rep(i, 0, k) {
        rep(j, 0, sz(boxes[i])) numToBox[boxes[i][j]] = {i, j};
    }

    rep(i, 0, k) {
        auto& box = boxes[i];
        sum = 0;
        each(b, box) sum += b;

        each(b, box) {
            ll d = ll(wanted) - (sum-b);
            if (numToBox.count(d)) {
                nxt[i].pb(numToBox[d]);
            } else {
                nxt[i].pb({-1, -1});
            }
        }
    }

    cycle.resize(1<<k);
    cycleStart.resize(1<<k);
    dp.resize(1<<k);

    rep(i, 0, k) {
        rep(j, 0, sz(boxes[i])) {
            int seen = 0;
            Pii cur = {i, j};

            while (cur.x != -1 && !((seen >> cur.x) & 1)) {
                seen |= 1 << cur.x;
                cur = nxt[cur.x][cur.y];
            }

            if (cur.x == i && cur.y == j) {
                cycle[seen] = 1;
                cycleStart[seen] = {i, j};
            }
        }
    }

    dp[0] = 1;

    rep(i, 0, 1<<k) {
        for (int a = i; a > 0; a = (a-1) & i) {
            int b = i^a;
            if (cycle[a] && dp[b]) {
                dp[i] = 1;
                break;
            }
        }
    }

    int mask = (1<<k)-1;

    if (!dp[mask]) {
        cout << "No\n";
        return;
    }

    vector<Pii> ans(k);

    while (mask) {
        for (int a = mask; a > 0; a = (a-1) & mask) {
            if (cycle[a] && dp[mask^a]) {
                Pii cur = cycleStart[a];

                do {
                    Pii n = nxt[cur.x][cur.y];
                    ans[cur.x].x = boxes[cur.x][cur.y];
                    ans[n.x].y = cur.x;
                    cur = n;
                } while (cur != cycleStart[a]);

                mask ^= a;
                break;
            }
        }
    }

    cout << "Yes\n";
    each(a, ans) cout << a.x << ' ' << a.y+1 << '\n';
}