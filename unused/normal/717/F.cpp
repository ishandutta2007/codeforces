#include <bits/stdc++.h>
using namespace std;

const int TSIZE = 131072; // always 2^k form && n <= TSIZE
long long init[TSIZE*2+2];

struct lazy_propagation
{
    // example implementation of sum tree
    long long segtree[TSIZE * 2], prop[TSIZE * 2];
    void seg_init(int nod, int l, int r, int delta) {
        if (l == r) segtree[nod] = init[2*l+delta];
        else {
            int m = (l + r) >> 1;
            seg_init(nod << 1, l, m, delta);
            seg_init(nod << 1 | 1, m + 1, r, delta);
            segtree[nod] = min(segtree[nod << 1], segtree[nod << 1 | 1]);
        }
    }
    void seg_relax(int nod, int l, int r) {
        if (prop[nod] == 0) return;
        if (l < r) {
            int m = (l + r) >> 1;
            segtree[nod << 1] += prop[nod];
            prop[nod << 1] += prop[nod];
            segtree[nod << 1 | 1] += prop[nod];
            prop[nod << 1 | 1] += prop[nod];
        }
        prop[nod] = 0;
    }
    long long seg_query(int nod, int l, int r, int s, int e) {
        if (r < s || e < l) return 1e18;
        if (s <= l && r <= e) return segtree[nod];
        seg_relax(nod, l, r);
        int m = (l + r) >> 1;
        return min(seg_query(nod << 1, l, m, s, e), seg_query(nod << 1 | 1, m + 1, r, s, e));
    }
    void seg_update(int nod, int l, int r, int s, int e, long long val) {
        if (r < s || e < l) return;
        if (s <= l && r <= e) {
            segtree[nod] += val;
            prop[nod] += val;
            return;
        }
        seg_relax(nod, l, r);
        int m = (l + r) >> 1;
        seg_update(nod << 1, l, m, s, e, val);
        seg_update(nod << 1 | 1, m + 1, r, s, e, val);
        segtree[nod] = min(segtree[nod << 1], segtree[nod << 1 | 1]);
    }
} stree[2];
// usage:
// seg_update(1, 0, n - 1, qs, qe, val);
// seg_query(1, 0, n - 1, qs, qe);


int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &init[i]);
    }

    if (n==1)
    {
        int q; scanf("%d",&q); while (q--)
        {
            int a,b,c;scanf("%d%d%d",&a,&b,&c);if(a==2) printf("%d\n",init[0]==1);
            else { int k; scanf("%d",&k); init[0] += k; }
        }
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        init[i] = init[i] - init[i-1] + 1;
    }

    // 0 : , 1 : 
    // 0 : 0, 1, 2, ..., n/2
    // 1 : 0, 1, 2, ..., (n+1)/2
    stree[0].seg_init(1, 0, TSIZE-1, 0);
    stree[1].seg_init(1, 0, TSIZE-1, 1);

    int q;
    scanf("%d",&q);
    while (q--)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        if (a == 2)
        {
            long long diff = b == 0 ? 0 : stree[(b&1)^1].seg_query(1, 0, TSIZE-1, (b-1)/2, (b-1)/2) - 1;
            if (b & 1) diff *= -1;

            if (stree[0].seg_query(1, 0, TSIZE-1, (b+1)/2, (c-1)/2) + diff <= 0 ||
                stree[1].seg_query(1, 0, TSIZE-1, b/2, c/2-1) - diff <= 0)
            {
                printf("0\n");
                continue;
            }

            long long fin = stree[c&1].seg_query(1, 0, TSIZE-1, c/2, c/2);
            if (c & 1) diff *= -1;
            if (fin + diff != 1) printf("0\n");
            else printf("1\n");
        }
        else
        {
            int k;
            scanf("%d",&k);
            if ((b^c)&1)
            {
                stree[b&1].seg_update(1, 0, TSIZE-1, b/2, (c-1)/2, k);
            }
            else
            {
                stree[b&1].seg_update(1, 0, TSIZE-1, b/2, TSIZE-1, k);
                stree[(b&1)^1].seg_update(1, 0, TSIZE-1, (c+1)/2, TSIZE-1, -k);
            }
        }
    }
}