using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
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
#define maxN 5005

ll ans;
int n, x, opl, opr;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE


    scanf("%d%d", &n, &x);
    opl = opr = x;
    fto(i, 1, n) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (min(opr, r)-max(opl, l) >= 0) {
            opl = max(opl, l);
            opr = min(opr, r);
        }
        else if ((opl > r)) {
            ans += opl-r;
            opr = opl;
            opl = r;
        }
        else {
            ans += l-opr;
            opl = opr;
            opr = l;
        }
//        printf("%d %d\n", opl, opr);
//        printf("%d %d\n", l, r);
//        printf("%I64d\n", ans);
    }

    cout << ans;

    return 0;
}