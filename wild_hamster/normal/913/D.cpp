#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <time.h>
#include <fstream>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
typedef long long ll;
using namespace std;

ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500], leaf[100500];
multiset<pii> f1, f2;
vector<ll> g[200500];
vector<pii> g1[200500];
int main() {
    // cout << setprecision(20);
    // ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d",&x,&y);
        f1.insert(mp(y, x));
        g[x].push_back(y);
        g1[x].push_back(mp(y, i+1));
    }
    ll ans = 0;
    auto itr = f1.begin();
    f2.insert(*itr);
    ans += (*itr).X;
    f1.erase(itr);
    ll res = 0;
    if (ans <= m) {
        res = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (j = 0; j < g[i-1].size(); j++) {
            ll x = i-1;
            ll y = g[i-1][j];
            if (f1.find(mp(y,x)) != f1.end()) {
                auto itr = f1.find(mp(y,x));
                f1.erase(itr);
            } else {
                auto itr = f2.find(mp(y,x));
                f2.erase(itr);
                ans -= y;
            }
        }
        if (f1.size() + f2.size() < i) {
            break;
        }
        while (f2.size() < i) {
            auto itr = f1.begin();
            ans += (*itr).X;
            f2.insert(*itr);
            f1.erase(itr);
        }
        if (ans <= m) {
            res = i;
        }
    }
    cout << res << endl;
    vector<pii> hyu;
    for (int i = res; i <= n; i++) {
        for (int j = 0; j < g1[i].size(); j++)
            hyu.push_back(g1[i][j]);
    }
    sort(hyu.begin(), hyu.end());
    cout << res << endl;
    for (int i = 0; i < res; i++)
        cout << hyu[i].Y << " ";
    return 0;
}