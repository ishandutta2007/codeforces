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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans, cnt;
vector<ll> f;
map<int, int> g;
ll a[100500], b[100500];
ll t[100500];
bool pal(string x) {
    ll n = x.size();
    for (int i = 0; i < n; i++)
        if (x[i] != x[n-i-1])
            return false;
    return true;
}

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        g[x] = max(g[x], y);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        g[x] = max(g[x], y);
    }
    ll ans = 0;
    for (auto itr = g.begin(); itr != g.end(); itr++) {
        ans += (*itr).Y;
    }
    cout << ans << endl;
    return 0;
}