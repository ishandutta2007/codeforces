#include <bits/stdc++.h>
using namespace std;

constexpr int TSIZE = 262144;

struct basis
{
    int dat[30]{};
    int cnt = 0;

    void reset()
    {
        memset(this, 0, sizeof(*this));
    }

    void add(int t)
    {
        for (int bit = 29; bit >= 0 && t; bit--)
        {
            if (!(t & (1 << bit))) continue;
            if (dat[bit]) t ^= dat[bit];
            else
            {
                dat[bit] = t;
                cnt++;
                return;
            }
        }
    }

    void merge(const basis &r)
    {
        for (int t : r.dat) if (t) add(t);
    }
};

int xortree[TSIZE * 2];
int dat[200005];

void update(int l, int r, int val)
{
    l += TSIZE; r += TSIZE;
    while (l <= r)
    {
        if (l & 1) xortree[l++] ^= val;
        if (!(r & 1)) xortree[r--] ^= val;
        l >>= 1; r >>= 1;
    }
}

int query(int pos)
{
    int ret = dat[pos];
    for (pos += TSIZE; pos; pos >>= 1)
        ret ^= xortree[pos];
    return ret;
}

int b[200005];
basis btree[TSIZE * 2];

void bupdate(int pos, int val)
{
    b[pos] = val;
    pos += TSIZE;
    btree[pos].reset();
    btree[pos].add(val);

    while (pos >>= 1)
    {
        btree[pos] = btree[pos << 1];
        btree[pos].merge(btree[pos << 1 | 1]);
    }
}

basis bquery(int l, int r)
{
    basis ret;
    l += TSIZE; r += TSIZE;
    while (l <= r)
    {
        if (l & 1) ret.merge(btree[l++]);
        if (!(r & 1)) ret.merge(btree[r--]);
        l >>= 1; r >>= 1;
    }
    return ret;
}

int main()
{
    int n, q;
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &dat[i]);
        bupdate(i, dat[i - 1] ^ dat[i]);
    }

    for (int i = 0; i < q; i++)
    {
        int type;
        scanf("%d",&type);
        if (type == 1)
        {
            int l,r,c;
            scanf("%d%d%d",&l,&r,&c);
            update(l, r, c);
            bupdate(l, b[l] ^ c);
            bupdate(r + 1, b[r + 1] ^ c);
        }
        else
        {
            int l, r;
            scanf("%d%d",&l,&r);
            auto ret = bquery(l + 1, r);
            ret.add(query(l));
            printf("%u\n", 1u << ret.cnt);
        }
    }
}