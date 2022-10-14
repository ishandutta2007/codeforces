#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
pii a[300500];
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> x >> y;
    y = min(y, n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x1, y1;
        scanf("%d %d", &a[i].X, &a[i].Y);
        ans += a[i].Y;
        f.push_back(max(0, a[i].X-a[i].Y));

    }
    if (y == 0) {
        cout << ans << endl;
        return 0;
    }
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    long long possible_ans = 0;
    long long sum = 0;
    for (int i = 0; i < y; i++)
        sum += f[i];
    for (int i = 0; i < n; i++) {
        ll val = max(0, a[i].X-a[i].Y);
        long long super_val = (1LL<<x)*a[i].X - a[i].Y;
        //cout << val << " " << super_val << endl;
        if (val >= f[y-1])
            possible_ans = max(possible_ans, sum + super_val - val);
        else
            possible_ans = max(possible_ans, sum + super_val - f[y-1]);
    }
    cout << ans+possible_ans << endl;
    return 0;
}