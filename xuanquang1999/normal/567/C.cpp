using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

int n, k, a[maxN];
map<ii, int> cnt;
map<ii, ll> sum;
ll ans;

ll CNT(ll x) {
    return (x*(x-1)*(x-2))/6;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    if (k == 1) {
        fto(i, 0, n-1) ++cnt[mp(0, a[i])];
        for(map<ii, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) ans+=CNT((*it).se);
    }
    else {
        int cnt0 = 0;
        fdto(i, n-1, 0) {
            if (a[i] == 0) ++cnt0;
            else {
                int b = 0, r = 0;
                while (a[i]%k == 0) {
                    ++r;
                    a[i]/=k;
                }
                b = a[i];
                ans+=sum[mp(b, r+1)];
                ++cnt[mp(b, r)];
                sum[mp(b, r)]+=cnt[mp(b, r+1)];
            }
        }
        ans+=CNT(cnt0);
    }

    cout << ans;

    return 0;
}