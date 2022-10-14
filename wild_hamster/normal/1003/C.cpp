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
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,x,y,INF, ans;
double dp[5005][5005];
ll a[5005], pa[5005];
map<ll,ll> f;
string s;
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pa[i+1] = pa[i] + a[i];
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+k; j <= n; j++) {
            ans = max(ans, 1.*(pa[j]-pa[i])/(j-i));
        }
    printf("%.10f\n", ans);
    return 0;
}