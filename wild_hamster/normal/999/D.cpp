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
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y,INF, ans;
ll a[1200005], d[1205000], b[1205000];
vector<pii> g[200500];
vector<ll> gr[200500];
vector<ll> f;
multiset<ll> e;
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[a[i]%m]++;
        g[a[i]%m].push_back(mp(a[i], i));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < d[i]-n/m; j++)
            e.insert(i);
    }
    for (int i = 0; i < m; i++) {
        if (d[i] < n/m) {
            ll diff = n/m - d[i];
            for (int j = 0; j < diff; j++) {
                auto itr = e.upper_bound(i);
                if (itr == e.begin())
                    itr = e.end();
                itr--;
                gr[i].push_back(*itr);
                e.erase(itr);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        d[i]--;
    }
    for (int i = 0; i < m; i++) {
        ll v = i;
        for (int j = 0; j < gr[i].size(); j++) {
            ll to = gr[i][j];
            ll diff = v-to;
            if (diff < 0)
                diff += m;
            a[g[to][d[to]].Y] += diff;
            ans += diff;
            d[to]--;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}