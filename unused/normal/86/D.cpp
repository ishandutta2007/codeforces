#include <bits/stdc++.h>
using namespace std;

int n, t;
int dat[200005];
int cnt[1000005];

constexpr int SQRT = 400;

struct query {
    int l, r;
    int idx;
    int bucket() const {
        return l / SQRT;
    }
    bool operator<(const query& rhs) const
    {
        return pair(bucket(), r) < pair(rhs.bucket(), rhs.r);
    }
};

query qry[200005];
long long ans[200005];
long long now;

void add(int x, int d)
{
    now -= cnt[x] * 1ll * cnt[x] * x;
    cnt[x] += d;
    now += cnt[x] * 1ll * cnt[x] * x;
}

int main()
{
    scanf("%d%d",&n,&t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&dat[i]);
    }

    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &qry[i].l, &qry[i].r);
        qry[i].idx = i;
    }

    sort(qry, qry + t);
    int l, r; int bucket = -1;

    for (int i = 0; i < t; i++)
    {
        if (bucket != qry[i].bucket())
        {
            bucket = qry[i].bucket();
            memset(cnt, 0, sizeof(cnt));
            now = 0;

            for (int j = qry[i].l; j <= qry[i].r; j++)
            {
                add(dat[j], 1);
            }

            l = qry[i].l; r = qry[i].r;
        }
        else
        {
            while (l < qry[i].l)
            {
                add(dat[l++], -1);
            }

            while (l > qry[i].l)
            {
                add(dat[--l], 1);
            }

            while (r < qry[i].r)
            {
                add(dat[++r], 1);
            }
        }

        ans[qry[i].idx] = now;
    }

    for (int i = 0; i < t; i++)
    {
        printf("%lld\n", ans[i]);
    }
}