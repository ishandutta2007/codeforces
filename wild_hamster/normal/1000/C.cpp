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
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,tot,y,INF, ans;
ll a[1200005], b[1205000], d[1205000], rev[1200500], bull[1200500];
map<ll, ll> f;
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &a[i], &b[i]);
        f[a[i]] = 0;
        f[b[i]] = 0;
    }
    i = 0;
    for (auto itr = f.begin(); itr != f.end(); itr++) {
        f[(*itr).X] = i;
        rev[i] = (*itr).X;
        i += 2;
    }
    y = i;
    for (int i = 0; i < n; i++) {
        a[i] = f[a[i]];
        b[i] = f[b[i]];
        d[a[i]]++;
        d[b[i]+1]--;
    }
    ll sum = 0;
    for (int i = 0; i < y; i++) {
        sum += d[i];
        if (i % 2 == 0) {
            bull[sum]++;
        } else {
            bull[sum] += rev[i+1] - rev[i-1] - 1;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << bull[i] << " ";
    return 0;
}