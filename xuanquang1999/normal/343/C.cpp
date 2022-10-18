using namespace std;
#include <bits/stdc++.h>
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
#define maxN 100005
#define maxC 1000000000000000007

int n, m;
ll h[maxN], p[maxN];

bool Check(ll t) {
    int j = 0;
    fto(i, 0, n-1) {
        int r = j;
        while (r < m && ((h[i] > p[j] && ((h[i] > p[r]) ? (h[i]-p[j]) : (p[r]-p[j]+min(h[i]-p[j], p[r]-h[i]))) <= t)
                     ||  (h[i] <= p[j] && p[r]-h[i] <= t))) ++r;
        --r;
        if (r == m-1) return true;
        j = r+1;
    }
    return false;
}

//bool Check2(ll t) {
//    int j = m-1;
//    fdto(i, n-1, 0) {
//        int r = j;
//        //while (r >= 0 && ((h[i] <= p[j] && max((ll)0, h[i]-p[r])*2+p[j]-h[i] <= t)
//        while (r >= 0 && ((h[i] <= p[j] && ((h[i] < p[r]) ? (p[j]-h[i]) : (p[j]-p[r]+min(h[i]-p[r], p[j]-h[i]))) <= t)
//                      ||  (h[i] > p[j] && h[i]-p[r] <= t))) --r;
//        ++r;
//        if (r == 0) return true;
//        j = r-1;
//    }
//    return false;
//}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, n-1) scanf("%I64d", &h[i]);
    fto(i, 0, m-1) scanf("%I64d", &p[i]);

    ll l = 0, r = maxC, res = maxC+1;
    while (l <= r) {
        ll mid = (l+r)/2;
        if (Check(mid)) {
            if (mid < res) res = mid;
            r = mid-1;
        }
        else l = mid+1;
    }

    cout << res;

    return 0;
}