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
#define maxN 100005

ll cnt[maxN], f[maxN];
int n;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }

    f[1] = cnt[1];
    f[2] = max(cnt[1], cnt[2]*2);
    fto(i, 3, maxN-1) f[i] = max(f[i-1], f[i-2]+cnt[i]*i);

    cout << f[maxN-1];

    return 0;
}