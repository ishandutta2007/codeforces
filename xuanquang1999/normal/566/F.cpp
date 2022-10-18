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
#define maxN 1000001

int n, a[maxN], f[maxN], ans;
bool avail[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) {
        scanf("%d", &a[i]);
        avail[a[i]] = true;
    }

    ans = 0;
    fto(i, 1, maxN-1)
        if (avail[i]) {
            f[i] = max(f[i], 1);
            ans = max(f[i], ans);
            int j = 2*i;
            while (j < maxN) {
                if (avail[j]) f[j] = max(f[j], f[i]+1);
                j+=i;
            }
        }

    printf("%d", ans);

    return 0;
}