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
ll a[300500],b[250005], c[200500], pre[3000500];
ll sparse_max[300500][20], sparse_or[300500][20];
vector<ll> ans;
ll get_max(ll l, ll r) {
    ll p = pre[r-l+1];
    return max(sparse_max[l][p], sparse_max[r-(1<<p)+1][p]);
}
ll get_or(ll l, ll r) {
    ll p = pre[r-l+1];
    return (sparse_or[l][p]|sparse_or[r-(1<<p)+1][p]);
}
int main() {
    //freopen("input.txt","r",stdin);
    for (int i = 0; i < 20; i++)
        pre[(1<<i)] = i;
    for (int i = 1; i < (1<<20); i++)
        pre[i] = max(pre[i-1], pre[i]);
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        sparse_max[i][0] = sparse_or[i][0] = a[i];
    for (int j = 1; j < 20; j++)
        for (int i = 0; i+(1<<j) <= n; i++) {
            sparse_max[i][j] = max(sparse_max[i][j-1], sparse_max[i+(1<<(j-1))][j-1]);
            sparse_or[i][j] = (sparse_or[i][j-1]|sparse_or[i+(1<<(j-1))][j-1]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ll cur_pos = i;
        while (get_or(i, cur_pos) < get_or(i, n-1)) {
            ll cur_val = get_or(i, cur_pos);
            ll l = cur_pos+1, r = n-1;
            while (l < r) {
                ll mid = ((l+r)>>1);
                if (get_or(i, mid) > get_or(i, cur_pos))
                    r = mid;
                else
                    l = mid+1;
            }
            ll next_pos = l;
            if (cur_val > get_max(i, cur_pos)) {
                l = cur_pos, r = next_pos-1;
                while (l < r) {
                    ll mid = ((l+r+1)>>1);
                    if (get_max(i, mid) < cur_val)
                        l = mid;
                    else
                        r = mid-1;
                }
                ans += l-cur_pos+1;
            }
            cur_pos = next_pos;
        }

        ll cur_val = get_or(i, cur_pos);
        if (cur_val > get_max(i, cur_pos)) {
            ll l = cur_pos, r = n-1;
            while (l < r) {
                ll mid = ((l+r+1)>>1);
                if (get_max(i, mid) < cur_val)
                    l = mid;
                else
                    r = mid-1;
            }
            ans += l-cur_pos+1;
        }
    }
    cout << ans << endl;
    return 0;
}