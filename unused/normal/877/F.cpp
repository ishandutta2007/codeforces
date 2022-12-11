#pragma GCC target("arch=ivybridge")
#include <bits/stdc++.h>
using namespace std;

int t[100005], a[100005];
long long sum[100005];
vector<long long> coord;
vector<int> nxt, prv;
vector<int> cnt;

struct query
{
    int l, r, idx;
    bool operator<(const query &q) const
    {
        if (l / 300 != q.l / 300) return l / 300 < q.l / 300;
        return r < q.r;
    }
} qry[100005];

long long ans[100005];
long long now;

void addL(int p)
{
    if (nxt[p] != -1) now += cnt[nxt[p]];
    cnt[p]++;
}

void addR(int p)
{
    if (prv[p] != -1) now += cnt[prv[p]];
    cnt[p]++;
}

void remL(int p)
{
    cnt[p]--;
    if (nxt[p] != -1) now -= cnt[nxt[p]];
}

void remR(int p)
{
    cnt[p]--;
    if (prv[p] != -1) now -= cnt[prv[p]];
}

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++) scanf("%d",&t[i]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if (t[i] == 1) sum[i] = sum[i - 1] + a[i];
        else sum[i] = sum[i - 1] - a[i];
    }

    coord = {sum, sum + 1 + n};
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    nxt.resize(coord.size(), -1);
    prv.resize(coord.size(), -1);
    for (int i = 0, j = 0; i < coord.size(); i++)
    {
        while (j < coord.size() && coord[j] < coord[i] + k) ++j;
        if (coord[j] == coord[i] + k)
        {
            nxt[i] = j;
            prv[j] = i;
        }
    }
    cnt.resize(coord.size());
    for (int i = 0; i <= n; i++) sum[i] = lower_bound(coord.begin(), coord.end(), sum[i]) - coord.begin();

    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d",&qry[i].l,&qry[i].r);
        --qry[i].l;
        qry[i].idx = i;
    }
    sort(qry, qry + q);
    int L = n + 1, R = n + 1;
    for (int i = 0; i < q; i++)
    {
        if (qry[i].r < R)
        {
            now = 0;
            fill(cnt.begin(), cnt.end(), 0);
            L = qry[i].l; R = qry[i].r;
            for (int j = L; j <= R; j++) addR(sum[j]);
        }

        while (R < qry[i].r) addR(sum[++R]);
        while (L > qry[i].l) addL(sum[--L]);
        while (L < qry[i].l) remL(sum[L++]);

        ans[qry[i].idx] = now;
    }

    for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
}