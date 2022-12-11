#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];
constexpr int TSIZE = 262144;
using ftype = const int&(*)(const int &, const int &);

struct segtree
{
    int tree[TSIZE * 2];
    ftype fp;
    int init;

    segtree(ftype fp, int init):fp(fp),init(init) {fill(tree, tree + TSIZE * 2, init);}

    void update(int pos, int val)
    {
        pos += TSIZE; tree[pos] = val;
        while (pos >>= 1)
        {
            tree[pos] = fp(tree[pos<<1], tree[pos<<1|1]);
        }
    }

    int query(int l, int r)
    {
        int ret = init;
        l += TSIZE; r += TSIZE;
        while (l <= r)
        {
            if (l&1) ret = fp(ret, tree[l++]);
            if (!(r&1)) ret = fp(ret, tree[r--]);
            l>>=1; r>>=1;
        }
        return ret;
    }
};

segtree mintree((ftype)min<int>, 2e9), maxtree((ftype)max<int>, -2e9);

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        maxtree.update(i, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&b[i]);
        mintree.update(i, b[i]);
    }

    long long ans = 0;

    for (int L = 1; L <= n; L++)
    {
        int lo = L, hi = n, lbound = n + 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int r1 = maxtree.query(L, mid);
            int r2 = mintree.query(L, mid);

            if (r1 < r2)
            {
                lo = mid + 1;
            }
            else if (r1 > r2)
            {
                hi = mid - 1;
            }
            else
            {
                lbound = mid;
                hi = mid - 1;
            }
        }

        if (lbound == n + 1) continue;

        lo = L, hi = n; int ubound = n + 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int r1 = maxtree.query(L, mid);
            int r2 = mintree.query(L, mid);

            if (r1 < r2)
            {
                lo = mid + 1;
            }
            else if (r1 > r2)
            {
                hi = mid - 1;
            }
            else
            {
                ubound = mid;
                lo = mid + 1;
            }
        }

        ans += ubound - lbound + 1;
    }
    printf("%lld\n", ans);
}