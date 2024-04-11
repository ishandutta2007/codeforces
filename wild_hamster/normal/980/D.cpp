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
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum;
ll a[300500], pr[300500], b[300500], ans[300500];
vector<pii> groups, tmp;
vector<ll> prs;
map<ll, ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    for (int i = 2; i <= 10000; i++)
        pr[i] = 1;
    for (int i = 2; i <= 10000; i++)
        if (pr[i]) {
            prs.push_back(i);
            for (int j = i*2; j <= 10000; j+=i)
                pr[j] = 0;
        }
    ll m = prs.size();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != 0) {
            for (int j = 0; j < m; j++) {
                while (x%(prs[j]*prs[j]) == 0) {
                    x /= (prs[j]*prs[j]);
                }
            }
        }
        a[i] = x;
        f[a[i]] = 0;
    }
    i = 1;
    for (auto itr = f.begin(); itr != f.end(); itr++) {
        if ((*itr).X != 0)
            f[(*itr).X] = i++;
    }
    f[0] = 0;
    for (int i = 0; i < n; i++)
        a[i] = f[a[i]];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n+5; j++)
            b[j] = 0;
        ll cnt = 0;
        for (int j = i; j < n; j++) {
            if (b[a[j]] == 0)
                cnt++;
            b[a[j]]++;
            if (b[0] > 0) {
                ans[max(1, cnt-1)]++;

            } else
                ans[cnt]++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}