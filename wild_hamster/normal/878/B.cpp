#include <bits/stdc++.h>
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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500];
vector<ll> f, g;
long long solve() {
    ll lst = 0, cnt = 0;
    f.clear(); g.clear();
    for (int i = 0; i < n; i++)
    {
        if (f.empty()) {
            f.push_back(a[i]);
            lst = a[i];
            cnt = 1;
        } else {
            if (a[i] == f.back()) {
                cnt++;
                f.push_back(a[i]);
            } else {
                cnt = 1;
                f.push_back(a[i]);
            }
            if (cnt == k) {
                for (int j = 0; j < k; j++)
                    f.pop_back();
                if (!f.empty()) {
                    int idx = f.size();
                    idx--;
                    lst = f[idx];
                    idx--;
                    cnt = 1;
                    while (idx >= 0 && lst == f[idx])
                        cnt++, idx--;
                }
            }
        }
    }

    ll sz = f.size();
    if (sz == 0) {
        return 0;
    }
    for (int i = 0; i < sz; i++)
        g.push_back(f[i]);
    for (int i = 0; i < sz; i++)
    {
        if (f.empty()) {
            f.push_back(g[i]);
            lst = a[i];
            cnt = 1;
        } else {
            if (g[i] == f.back()) {
                cnt++;
                f.push_back(g[i]);
            } else {
                cnt = 1;
                f.push_back(g[i]);
            }
            if (cnt == k) {
                for (int j = 0; j < k; j++)
                    f.pop_back();
                if (!f.empty()) {
                    int idx = f.size();
                    idx--;
                    lst = f[idx];
                    idx--;
                    cnt = 1;
                    while (idx >= 0 && lst == f[idx])
                        cnt++, idx--;
                }
            }
        }
    }

    ll newsz = f.size();
    if (newsz%2 != 0) {
        return (1LL*m*sz-1LL*(sz*2-newsz)*(m-1));
    }
    if (newsz == 0) {
        if (m%2 == 0) {
            return 0;
        } else {
            return sz;
        }
    }
    ll mag = (2*sz-newsz)/2;
    bool flag = true;
    for (int i = mag; i < sz-mag-1; i++)
        if (g[i] != g[i+1])
            flag = false;
    if (!flag) {
        return (1LL*sz*m - 2LL*mag*(m-1));
    }
    long long val = 1LL*m*(sz-2*mag);
    long long ans = 1LL*sz*m - 2LL*mag*(m-1);
    if (val % k != 0) {
        ans -= (val - val%k);
        return ans;
    } else {
        return 0;
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool flag = true;
    for (int i = 0; i+1 < n; i++)
        if (a[i] != a[i+1])
            flag = false;
    if (flag) {
        cout << 1LL*n*m%k << endl;
        return 0;
    }
    cout << solve() << endl;

    /*while (1) {
        srand(time(0));
        n = rand()%10, k = rand()%8+2, m = rand()%10+1;
        for (int i = 0; i < n; i++)
            a[i] = rand()%3 + 1;
        ll ans1 = solve();
        for (int i = 0; i < n*m; i++)
            a[i+n] = a[i];
        x = n;
        n = n*m, m = 1;
        ll ans2 = solve();
        if (ans1 != ans2)
        {
            cout << ans1 << " " << ans2 << endl;
            cout << x << " " << k << " " << n/x << endl;
            for (int i = 0; i < x; i++)
                cout << a[i] << " ";
            cout << endl;
            return 0;
        }
    }*/
    return 0;
}