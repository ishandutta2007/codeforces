#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,x,y,INF, ans, d;
double dp[5005][5005];
ll w[500500];
vector<pii> f;
vector<ll> nodes[500500], g[500500], need;
ll used[500500];
string s;
void dfs(ll v) {
    used[v] = 1;
    need.push_back(v);
    if (!g[v].empty())
        dfs(g[v][0]);
}
void output() {
    cout << "YES" << endl;
    dfs(g[1][0]);
    dfs(g[1][1]);
    ll diam = need.size();
    ll ex = need.back();
    int last = n;
    int lst = ex;
    for (int i = 0; i < d-diam; i++) {
        while (used[last])
            last--;
        printf("%d %d\n", lst, last);
        used[last] = 2;
        lst = last;
        last--;
    }
    for (int i = 0; i < f.size(); i++) {
        if (used[f[i].Y] != 2)
            printf("%I64d %I64d\n", f[i].X, f[i].Y);
    }
}
int main() {

    //freopen("input.txt","r",stdin);
    ll cur, curlev;
    cin >> n >> d >> k;
    if (n == 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (n == 2) {
        if (d == 1) {
            cout << "YES" << endl;
            cout << 1 << " " << 2 << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    if (d >= n) {
        cout << "NO" << endl;
        return 0;
    }
    if (d%2 == 0) {

        nodes[0].push_back(1);
        cur = 2, curlev = 0;
        for (int i = 0; i < nodes[curlev].size(); i++) {
            ll v = nodes[curlev][i];
            for (int j = 0; j < k; j++) {
                nodes[curlev+1].push_back(cur);
                f.push_back(mp(v, cur));
                g[v].push_back(cur);
                w[cur] = v;
                cur++;
                if (cur > n) {
                    output();
                    return 0;
                }
            }
        }
        curlev++;
    } else {
        nodes[0].push_back(1);
        nodes[0].push_back(2);
        f.push_back(mp(1,2));
        g[1].push_back(2);
        w[2] = 1;
        cur = 3;
        curlev = 0;
    }
    k--;
    for (int ii = 1; ii < (d+1)/2; ii++) {
        for (int i = 0; i < nodes[curlev].size(); i++) {
            ll v = nodes[curlev][i];
            //cout << v << " " << k << endl;
            for (int j = 0; j < k; j++) {
                nodes[curlev+1].push_back(cur);
                f.push_back(mp(v, cur));
                g[v].push_back(cur);
                w[cur] = v;
                cur++;
                if (cur > n) {
                    output();
                    return 0;
                }
            }
        }
        curlev++;
    }
    cout << "NO" << endl;
    return 0;
}