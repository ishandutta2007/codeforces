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
#define maxN 400005

map<int, int> f;
int a[maxN], n, k, cnt;
ll ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    int r = -1;
    fto(i, 0, n-1) {
        ++f[a[i]];
        if (f[a[i]] == k) ++cnt;
        if (cnt == 1) {
            r = i;
            break;
        }
    }
    if (r == -1) {
        printf("0");
        return 0;
    }
    ans = n-r;

    fto(l, 0, n-1) {
        if (f[a[l]] == k) --cnt;
        --f[a[l]];
        while (cnt < 1) {
            if (r < n-1) ++r;
            else {
                printf("%I64d", ans);
                return 0;
            }
            ++f[a[r]];
            if (f[a[r]] == k) ++cnt;
        }
        ans+=n-r;
    }

    printf("%I64d", ans);
    return 0;
}