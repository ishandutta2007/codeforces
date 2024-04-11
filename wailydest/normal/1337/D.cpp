#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

inline long long po2(int a) { return (long long)a * a; }

long long getmin(vector<int> &a, vector<int> &b, vector<int> &invb, vector<int> &c, vector<int> &invc)
{
    long long ans = LLONG_MAX;
    int bmin, cmin;
    for (int i = 0; i < a.size(); ++i) {
        bmin = (int)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());
        cmin = (int)(lower_bound(c.begin(), c.end(), a[i]) - c.begin());
        if (bmin == b.size() || cmin == c.size()) break;
        if (b[bmin] <= c[cmin]) {
            int fin = -1;
            int m = (a[i] + c[cmin]) / 2;
            int right = (int)(lower_bound(b.begin(), b.end(), m) - b.begin());
            int left = (int)(lower_bound(invb.begin(), invb.end(), -m) - invb.begin());
            if (left != b.size()) left = b.size() - left - 1;
            if (right == b.size() || b[right] > c[cmin]) fin = left;
            if (left == b.size() || b[left] < a[i]) fin = right;
            if (fin == -1) {
                if (m - b[left] < b[right] - m) fin = left;
                else fin = right;
            }
            ans = min(ans, po2(c[cmin] - a[i]) + po2(b[fin] - a[i]) + po2(c[cmin] - b[fin]));
        }
    }
    return ans;
}

void solve()
{
    int nr, ng, nb;
    scanf("%d%d%d", &nr, &ng, &nb);
    vector<int> r(nr), g(ng), b(nb), invr(nr), invg(ng), invb(nb);
    for (int i = 0; i < nr; ++i) {
        scanf("%d", &r[i]);
        invr[i] = -r[i];
    }
    for (int i = 0; i < ng; ++i) {
        scanf("%d", &g[i]);
        invg[i] = -g[i];
    }
    for (int i = 0; i < nb; ++i) {
        scanf("%d", &b[i]);
        invb[i] = -b[i];
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    sort(invr.begin(), invr.end());
    sort(invg.begin(), invg.end());
    sort(invb.begin(), invb.end());
    
    long long ans = getmin(r, g, invg, b, invb);
    ans = min(ans, getmin(r, b, invb, g, invg));
    ans = min(ans, getmin(g, b, invb, r, invr));
    ans = min(ans, getmin(g, r, invr, b, invb));
    ans = min(ans, getmin(b, r, invr, g, invg));
    ans = min(ans, getmin(b, g, invg, r, invr));
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}