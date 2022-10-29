#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 2e5 + 5;

int T, n;
LL a[N], sum;

void madd(int &x, int y) { x = x + y >= P ? x + y - P : x + y; }

int getans(bool lp, bool rc) {
    //if lp then the first c could not be on the 3rd place
    //if rc then the last p could not be on the (n-2)-th place
    int l, r, i;
    l = lp ? 2 : 1;
    r = n - 1;
    LL sumc = rc ? a[n] : 0;
    int res = 0;

    int li, ri;
    for (i = l; i <= r; i += 2)
        sumc += a[i];
    li = l, ri = i - 2;
    while (ri >= li && sumc * 2 >= sum)
        sumc -= a[ri], ri -= 2;
    if (rc && ri == r)
        sumc -= a[ri], ri -= 2;

    while (li <= ri) {
        madd(res, (ri - li) / 2 + 1);
        if (li + 2 > ri)
            break;
        sumc += a[li + 1], li += 2;
        while (ri >= li && sumc * 2 >= sum)
            sumc -= a[ri], ri -= 2;
    }

    sumc = a[l] + (rc ? a[n] : 0);
    for (i = l + 1; i <= r; i += 2)
        sumc += a[i];
    li = l + 1, ri = i - 2;
    while (ri >= li && sumc * 2 >= sum)
        sumc -= a[ri], ri -= 2;
    if (rc && ri == r)
        sumc -= a[ri], ri -= 2;

    while (li <= ri) {
        madd(res, (ri - li) / 2 + 1);
        if (li + 2 > ri)
            break;
        sumc += a[li + 1], li += 2;
        while (ri >= li && sumc * 2 >= sum)
            sumc -= a[ri], ri -= 2;
    }
    return res;
}

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        rep(i, 1, n) scanf("%lld", a + i);
        sum = 0;
        rep(i, 1, n) sum += a[i];
        int ans = 0;
        //left p right c is not counted
        LL sumc = 0;
        rrep(i, n, 1) {
            ans += (sumc * 2 < sum);
            sumc += a[i];
        }
        madd(ans, getans(0, 0)), madd(ans, getans(0, 1)), madd(ans, getans(1, 0)), madd(ans, getans(1, 1));
        //cerr << getans(0, 0) << " " << getans(0, 1) << " " << getans(1, 0) << " " << getans(1, 1) << endl;
        printf("%d\n", ans);
    }
}