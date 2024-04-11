/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;

const int MAX = 105000;

/**
 * Segment tree
 */
struct Seg
{
        int l, r;
        int maxLeftValue, maxRightValue, minLeftValue, minRightValue, maxSum,
                minSum, sum;
        int maxLeftBound, maxRightBound, minLeftBound, minRightBound,
                maxSumLeft, maxSumRight, minSumLeft, minSumRight;
} seg[MAX << 2];
int a[MAX];

void update(int k)
{
    seg[k].sum = seg[k << 1].sum + seg[k << 1 | 1].sum;
    if (seg[k << 1].maxLeftValue >= seg[k << 1].sum
            + seg[k << 1 | 1].maxLeftValue)
    {
        seg[k].maxLeftValue = seg[k << 1].maxLeftValue;
        seg[k].maxRightBound = seg[k << 1].maxRightBound;
    }
    else
    {
        seg[k].maxLeftValue = seg[k << 1].sum + seg[k << 1 | 1].maxLeftValue;
        seg[k].maxRightBound = seg[k << 1 | 1].maxRightBound;
    }
    if (seg[k << 1 | 1].maxRightValue >= seg[k << 1 | 1].sum
            + seg[k << 1].maxRightValue)
    {
        seg[k].maxRightValue = seg[k << 1 | 1].maxRightValue;
        seg[k].maxLeftBound = seg[k << 1 | 1].maxLeftBound;
    }
    else
    {
        seg[k].maxRightValue = seg[k << 1 | 1].sum + seg[k << 1].maxRightValue;
        seg[k].maxLeftBound = seg[k << 1].maxLeftBound;
    }
    if (seg[k << 1].minLeftValue <= seg[k << 1].sum
            + seg[k << 1 | 1].minLeftValue)
    {
        seg[k].minLeftValue = seg[k << 1].minLeftValue;
        seg[k].minRightBound = seg[k << 1].minRightBound;
    }
    else
    {
        seg[k].minLeftValue = seg[k << 1].sum + seg[k << 1 | 1].minLeftValue;
        seg[k].minRightBound = seg[k << 1 | 1].minRightBound;
    }
    if (seg[k << 1 | 1].minRightValue <= seg[k << 1 | 1].sum
            + seg[k << 1].minRightValue)
    {
        seg[k].minRightValue = seg[k << 1 | 1].minRightValue;
        seg[k].minLeftBound = seg[k << 1 | 1].minLeftBound;
    }
    else
    {
        seg[k].minRightValue = seg[k << 1 | 1].sum + seg[k << 1].minRightValue;
        seg[k].minLeftBound = seg[k << 1].minLeftBound;
    }
    if (seg[k << 1].maxSum >= seg[k << 1 | 1].maxSum)
    {
        seg[k].maxSum = seg[k << 1].maxSum;
        seg[k].maxSumLeft = seg[k << 1].maxSumLeft;
        seg[k].maxSumRight = seg[k << 1].maxSumRight;
    }
    else
    {
        seg[k].maxSum = seg[k << 1 | 1].maxSum;
        seg[k].maxSumLeft = seg[k << 1 | 1].maxSumLeft;
        seg[k].maxSumRight = seg[k << 1 | 1].maxSumRight;
    }
    if (seg[k].maxSum < seg[k << 1].maxRightValue
            + seg[k << 1 | 1].maxLeftValue)
    {
        seg[k].maxSum = seg[k << 1].maxRightValue
                + seg[k << 1 | 1].maxLeftValue;
        seg[k].maxSumLeft = seg[k << 1].maxLeftBound;
        seg[k].maxSumRight = seg[k << 1 | 1].maxRightBound;
    }

    if (seg[k << 1].minSum <= seg[k << 1 | 1].minSum)
    {
        seg[k].minSum = seg[k << 1].minSum;
        seg[k].minSumLeft = seg[k << 1].minSumLeft;
        seg[k].minSumRight = seg[k << 1].minSumRight;
    }
    else
    {
        seg[k].minSum = seg[k << 1 | 1].minSum;
        seg[k].minSumLeft = seg[k << 1 | 1].minSumLeft;
        seg[k].minSumRight = seg[k << 1 | 1].minSumRight;
    }
    if (seg[k].minSum > seg[k << 1].minRightValue
            + seg[k << 1 | 1].minLeftValue)
    {
        seg[k].minSum = seg[k << 1].minRightValue
                + seg[k << 1 | 1].minLeftValue;
        seg[k].minSumLeft = seg[k << 1].minLeftBound;
        seg[k].minSumRight = seg[k << 1 | 1].minRightBound;
    }
}

void init(int k, int l, int r)
{
    seg[k].l = l;
    seg[k].r = r;
    if (l == r)
    {
        seg[k].sum = seg[k].maxLeftValue = seg[k].maxRightValue
                = seg[k].minLeftValue = seg[k].minRightValue = seg[k].maxSum
                        = seg[k].minSum = a[l];
        seg[k].maxLeftBound = seg[k].minLeftBound = l;
        seg[k].maxRightBound = seg[k].minRightBound = r;
        seg[k].maxSumLeft = seg[k].maxSumRight = r;
        seg[k].minSumLeft = seg[k].minSumRight = r;
        return;
    }
    int mid = l + r >> 1;
    init(k << 1, l, mid);
    init(k << 1 | 1, mid + 1, r);
    update(k);
}

void Up(int k,int pos,int v)
{
    if(seg[k].l==pos&&seg[k].r==pos)
    {
        seg[k].sum = seg[k].maxLeftValue = seg[k].maxRightValue
                = seg[k].minLeftValue = seg[k].minRightValue = seg[k].maxSum
                        = seg[k].minSum = v;
        return;
    }
    int mid=(seg[k].l+seg[k].r)/2;
    if(pos<=mid)Up(k << 1, pos, v);
    else Up(k << 1 | 1, pos, v);
    update(k);
}
int findMaxRight(int k, int l, int r, int& ll)
{
    if (seg[k].l == l && seg[k].r == r)
    {
        ll = seg[k].maxLeftBound;
        return seg[k].maxRightValue;
    }
    int mid = seg[k].l + seg[k].r >> 1;
    if (l > mid)
    {
        return findMaxRight(k << 1 | 1, l, r, ll);
    }
    else
    {
        int l1, l2;
        int retRight = findMaxRight(k << 1 | 1, mid + 1, r, l1);
        int retLeft = findMaxRight(k << 1, l, mid, l2) + seg[k << 1 | 1].sum;
        if (retRight >= retLeft)
        {
            ll = l1;
            return retRight;
        }
        else
        {
            ll = l2;
            return retLeft;
        }
    }
}

int findMaxLeft(int k, int l, int r, int& rr)
{
    if (seg[k].l == l && seg[k].r == r)
    {
        rr = seg[k].maxRightBound;
        return seg[k].maxLeftValue;
    }
    int mid = seg[k].l + seg[k].r >> 1;
    if (r <= mid)
    {
        return findMaxLeft(k << 1, l, r, rr);
    }
    else
    {
        int r1, r2;
        int retLeft = findMaxLeft(k << 1, l, mid, r1);
        int retRight = seg[k << 1].sum
                + findMaxLeft(k << 1 | 1, mid + 1, r, r2);
        if (retLeft >= retRight)
        {
            rr = r1;
            return retLeft;
        }
        else
        {
            rr = r2;
            return retRight;
        }
    }
}

int findMax(int k, int l, int r, int& ll, int& rr)
{
    if (seg[k].l == l && seg[k].r == r)
    {
        ll = seg[k].maxSumLeft;
        rr = seg[k].maxSumRight;
        return seg[k].maxSum;
    }
    int mid = seg[k].l + seg[k].r >> 1;
    if (r <= mid)
    {
        return findMax(k << 1, l, r, ll, rr);
    }
    else if (l > mid)
    {
        return findMax(k << 1 | 1, l, r, ll, rr);
    }
    else
    {
        int l1, r1, l2, r2, l3, r3, ret;
        int retLeft = findMax(k << 1, l, mid, l1, r1);
        int retRight = findMax(k << 1 | 1, mid + 1, r, l2, r2);
        int retMiddle = findMaxRight(k << 1, l, mid, l3)
                + findMaxLeft(k << 1 | 1, mid + 1, r, r3);
        if (retLeft >= retRight)
        {
            ll = l1;
            rr = r1;
            ret = retLeft;
        }
        else
        {
            ll = l2;
            rr = r2;
            ret = retRight;
        }
        if (ret < retMiddle)
        {
            ll = l3;
            rr = r3;
            ret = retMiddle;
        }
        return ret;
    }
}

int findMinRight(int k, int l, int r, int& ll)
{
    if (seg[k].l == l && seg[k].r == r)
    {
        ll = seg[k].minLeftBound;
        return seg[k].minRightValue;
    }
    int mid = seg[k].l + seg[k].r >> 1;
    if (l > mid)
    {
        return findMinRight(k << 1 | 1, l, r, ll);
    }
    else
    {
        int l1, l2;
        int retRight = findMinRight(k << 1 | 1, mid + 1, r, l1);
        int retLeft = findMinRight(k << 1, l, mid, l2) + seg[k << 1 | 1].sum;
        if (retRight <= retLeft)
        {
            ll = l1;
            return retRight;
        }
        else
        {
            ll = l2;
            return retLeft;
        }
    }
}

int findMinLeft(int k, int l, int r, int& rr)
{
    if (seg[k].l == l && seg[k].r == r)
    {
        rr = seg[k].minRightBound;
        return seg[k].minLeftValue;
    }
    int mid = seg[k].l + seg[k].r >> 1;
    if (r <= mid)
    {
        return findMinLeft(k << 1, l, r, rr);
    }
    else
    {
        int r1, r2;
        int retLeft = findMinLeft(k << 1, l, mid, r1);
        int retRight = seg[k << 1].sum
                + findMinLeft(k << 1 | 1, mid + 1, r, r2);
        if (retLeft <= retRight)
        {
            rr = r1;
            return retLeft;
        }
        else
        {
            rr = r2;
            return retRight;
        }
    }
}

int findMin(int k, int l, int r, int& ll, int& rr)
{
    if (seg[k].l == l && seg[k].r == r)
    {
        ll = seg[k].minSumLeft;
        rr = seg[k].minSumRight;
        return seg[k].minSum;
    }
    int mid = seg[k].l + seg[k].r >> 1;
    if (r <= mid)
    {
        return findMin(k << 1, l, r, ll, rr);
    }
    else if (l > mid)
    {
        return findMin(k << 1 | 1, l, r, ll, rr);
    }
    else
    {
        int l1, r1, l2, r2, l3, r3, ret;
        int retLeft = findMin(k << 1, l, mid, l1, r1);
        int retRight = findMin(k << 1 | 1, mid + 1, r, l2, r2);
        int retMiddle = findMinRight(k << 1, l, mid, l3)
                + findMinLeft(k << 1 | 1, mid + 1, r, r3);
        if (retLeft <= retRight)
        {
            ll = l1;
            rr = r1;
            ret = retLeft;
        }
        else
        {
            ll = l2;
            rr = r2;
            ret = retRight;
        }
        if (ret > retMiddle)
        {
            ll = l3;
            rr = r3;
            ret = retMiddle;
        }
        return ret;
    }
}

/**
 * heap
 */

struct Node
{
        bool flag;
        int v, l, r, ll, rr;
        Node()
        {
        }
        Node(bool flag, int v, int l, int r, int ll, int rr) :
            flag(flag), v(v), l(l), r(r), ll(ll), rr(rr)
        {
        }
} h[MAX];
int K;

void sink(int k)
{
    while ((k << 1) <= K)
    {
        int maxv = max(h[k].v, h[k << 1].v);
        if ((k << 1 | 1) <= K)
        {
            maxv = max(maxv, h[k << 1 | 1].v);
        }
        if (maxv == h[k].v)
            break;
        else if (maxv == h[k << 1].v)
        {
            swap(h[k], h[k << 1]);
            k = k << 1;
        }
        else
        {
            swap(h[k], h[k << 1 | 1]);
            k = k << 1 | 1;
        }
    }
}

void flow(int k)
{
    while (k > 1)
    {
        int p = k >> 1;
        if (h[p].v < h[k].v)
        {
            swap(h[p], h[k]);
            k >>= 1;
        }
        else
        {
            break;
        }
    }
}

Node getMax()
{
    swap(h[1], h[K]);
    K--;
    sink(1);
    return h[K + 1];
}

void add(const Node& node)
{
    h[++K] = node;
    flow(K);
}

int main()
{
    int n, m, Q, t;
    int l, r, L, R;
    int ret;


    while (~scanf("%d", &n) )
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        init(1, 0, n - 1);
        scanf("%d",&Q);
        while(Q--)
        {
            int op;
            scanf("%d",&op);
            if(op==0)
            {
                scanf("%d%d",&l,&r);l--;
                Up(1,l,r);
            }
            else
            {
                scanf("%d%d%d",&L,&R,&m);L--;R--;
                K = 0;
                ret = 0;
                t = findMax(1, L, R, l, r);
                add(
                    Node(true, t, L, R, l,
                         r));
                while (m--)
                {
                    Node u = getMax();
                    if (u.v <= 0)
                    {
                        break;
                    }
                    ret += u.v;
                    if (!u.flag)
                    {
                        if (u.l != u.ll)
                        {
                            t = findMin(1, u.l, u.ll - 1, l, r);
                            add(Node(false, -t, u.l, u.ll - 1, l, r));
                        }
                        if (u.r != u.rr)
                        {
                            t = findMin(1, u.rr + 1, u.r, l, r);
                            add(Node(false, -t, u.rr + 1, u.r, l, r));
                        }
                        t = findMax(1, u.ll, u.rr, l, r);
                        add(Node(true, t, u.ll, u.rr, l, r));
                    }
                    else
                    {
                        if (u.l != u.ll)
                        {
                            t = findMax(1, u.l, u.ll - 1, l, r);
                            add(Node(true, t, u.l, u.ll - 1, l, r));
                        }
                        if (u.r != u.rr)
                        {
                            t = findMax(1, u.rr + 1, u.r, l, r);
                            add(Node(true, t, u.rr + 1, u.r, l, r));
                        }
                        t = findMin(1, u.ll, u.rr, l, r);
                        add(Node(false, -t, u.ll, u.rr, l, r));
                    }
                }
                printf("%d\n", ret);
            }
        }
    }

    return 0;
}