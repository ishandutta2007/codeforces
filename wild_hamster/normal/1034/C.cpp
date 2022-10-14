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
#define MOD 1000000007
#define ROW 5
typedef long long ll;
using namespace std;
ll n,i,j,k,m,q,timer,mx, v,tot,x,y,INF, sz,ans, sum;
ll a[1005000], dp[1005000], b[105];
vector<int> g[1005000];
const int N = 32000000;
int lp[N+15];
vector<int> pr;
vector<ll> cur_primes, all, good;

struct Hashset {
    long long keys[300000];
    int values[300000];
    void update(ll key, int value) {
        int hsh = (key&262143);
        while (keys[hsh] != -1 && keys[hsh] != key) {
            hsh++;
        }
        //cout << hsh << " " << value << endl;
        if (keys[hsh] == -1)
            keys[hsh] = key, values[hsh] = value;
        else {
            values[hsh] += value;
            if (values[hsh] >= MOD)
                values[hsh] -= MOD;
        }
    }
    int get(ll key) {
        int hsh = (key&262143);
        while (keys[hsh] != -1 && keys[hsh] != key) {
            hsh++;
        }
        if (keys[hsh] == -1)
            return 0;
        return values[hsh];
    }
} cnt, tot_cnt, total_dp;

ll gcd(ll a, ll b) {
    return b==0?a:gcd(b, a%b);
}

void dfs(int v, int p = -1) {
    dp[v] = a[v];
    for (auto to: g[v]) {
        if (to != p) {
            dfs(to, v);
            dp[v] += dp[to];
        }
    }
}

void go(ll v, ll pos) {
    for (int i = pos; i < cur_primes.size(); i++) {
        ll u = cur_primes[i];
        if (v % u == 0) {
            go(v / u, i);
        }
    }
    all.push_back(v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < 300000; i++)
        cnt.keys[i] = tot_cnt.keys[i] = total_dp.keys[i] = -1;
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        sum += a[i];
    }
    for (int i = 2; i <= n; i++) {
        int x, y;
        scanf("%d", &x);
        g[i].push_back(x);
        g[x].push_back(i);
    }
    //cout << "hyu" << endl;
    dfs(1);
    for (int v = 1; v <= n; v++) {
        
        cnt.update(gcd(dp[v], sum), 1);
    }
    ll x = sum;
    for (int i = 0; i < pr.size(); i++) {
        if (x % pr[i] == 0) {
            cur_primes.push_back(pr[i]);
            while (x % pr[i] == 0)
                x /= pr[i];
        }
    }
    if (x != 1)
        cur_primes.push_back(x);
    go(sum, 0);
    //for (int i = 0; i < all.size(); i++)
    //    cout << all[i] << endl;
    sort(all.begin(), all.end());
    reverse(all. begin(), all.end());
    for (int j = 0; j < all.size(); j++) {
        sz = 0;
        ll v = all[j];
        for (int i = 0; i < cur_primes.size(); i++)
        if (sum % (v * cur_primes[i]) == 0) {
            b[sz++] = cur_primes[i];
        }
        ll ans = 0;
        for (int i = 1; i < (1<<sz); i++) {
            int bits = 0;
            ll mul = 1;
            for (int k = 0; k < sz; k++)
            if ((i>>k)&1) {
                bits++;
                mul *= b[k];
            }
            if (bits % 2)
                ans += tot_cnt.get(v*mul);
            else
                ans -= tot_cnt.get(v*mul);
        }
        tot_cnt.update(v, cnt.get(v) + ans);
        //cout << v << " " << tot_cnt[v] << " " << cnt[v] << endl;
    }
    for (int i = 0; i < all.size(); i++) {
        ll v = all[i];
        if (sum / v == tot_cnt.get(v)) {
            total_dp.update(v, 1);
            good.push_back(v);
        }
    }
    sort(good.begin(), good.end());
    for (int i = 0; i < good.size(); i++) {
        for (int j = i+1; j < good.size(); j++)
            if (good[j] % good[i] == 0) {
                total_dp.update(good[j], total_dp.get(good[i]));
            }
    }
    cout << total_dp.get(sum) << endl;
    return 0;
}