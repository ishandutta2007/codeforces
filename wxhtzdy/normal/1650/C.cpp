#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, m, x[200005], w[200005];
PII ord[200005];
LL ps[200005];

void solve()
{
    scanf("%d%d", &n, &m);
    rep1(i, m) scanf("%d%d", &x[i], &w[i]), ord[i] = MP(w[i], i);
    sort(ord + 1, ord + 1 + m);
    rep1(i, m) ps[i] = ps[i - 1] + w[ord[i].second];
    vector<int> ids;
    rep1(i, 2 * n) ids.push_back(ord[i].second);
    sort(ids.begin(), ids.end(), [&](int i, int j) { return x[i] < x[j]; });
    LL tot = 0;
    rep1(i, 2 * n) tot += w[ord[i].second];
    printf("%lld\n", tot);
    int sl = 0, sr = 2 * n - 1;
    for(int i = sl; i <= sr; i++) printf("%d %d\n", ids[sl], ids[sr]), sl++, sr--;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}