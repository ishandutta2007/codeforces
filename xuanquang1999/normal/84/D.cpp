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
#define maxN 1000005
#define maxC 1000000007

int a[maxN], n, m;
ll sum, k;


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int r = 0;
    scanf("%d%I64d", &n, &k);
    fto(i, 0, n-1) {
        scanf("%d", &a[i]);
        r = max(r, a[i]);
    }

    sum = 0;
    fto(i, 0, n-1) sum+=a[i];
    if (sum < k) {
        printf("-1");
        return 0;
    }

    int l = 0, res = -1;
    while (l <= r) {
        int mid = (l+r)/2;
        sum = 0;
        fto(i, 0, n-1) sum+=min(mid, a[i]);
        if (sum <= k) {
            if (mid > res) res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }

    sum = 0;
    fto(i, 0, n-1) sum+=min(res, a[i]);

    if (sum == k) m = -1;
    else {
        ll cnt = 0;
        fto(i, 0, n-1)
            if (a[i] > res) {
                ++cnt;
                if (sum+cnt == k) {
                    m = i;
                    break;
                }
            }
    }

    fto(i, m+1, n-1)
        if (a[i] > res) printf("%d ", i+1);

    fto(i, 0, m)
        if (a[i] > res+1) printf("%d ", i+1);

    return 0;
}