/*
    Author:USETC_elfness
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
typedef long long LL;
const int V=200100;
const int P=1000000007;
using namespace std;
struct Node
{
    int l, r, W, H, L, R, all;
}tr[12 * V];
int N;
void init(int id, int l, int r)
{
    tr[id].l = l;
    tr[id].r = r;
    tr[id].W = tr[id].H = 0;
    tr[id].L = 1;
    tr[id].R = N;
    tr[id].all = 1;
    if(l == r) return;
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
}
void down(int id)
{
    if(tr[id].all == 1)
    {
        tr[id * 2].W = tr[id *2 + 1].W = tr[id].W;
        tr[id * 2].H = tr[id *2 + 1].H = tr[id].H;
        tr[id * 2].L = tr[id *2 + 1].L = tr[id].L;
        tr[id * 2].R = tr[id *2 + 1].R = tr[id].R;
        tr[id].all = 0;
    }
}
Node find(int id, int pos)
{
    if(tr[id].l == pos && tr[id].r == pos)
    return tr[id];
    down(id);
    int mid = (tr[id].l + tr[id].r) / 2;
    if(pos <= mid) return find(id * 2, pos);
    else return find(id * 2 + 1, pos);
}
void update(int id, int l, int r, int W, int H, int L, int R)
{
    if(tr[id].l == l && tr[id].r == r)
    {
        tr[id]. W = W;
        tr[id]. H = H;
        tr[id]. L = L;
        tr[id]. R = R;
        return;
    }
    down(id);
    int mid = (tr[id].l + tr[id].r) / 2;
    if(r <= mid) update(id * 2, l, r, W, H, L, R);
    else if(l > mid) update(id * 2 + 1, l, r, W, H, L, R);
    else
    {
        update(id * 2, l, mid, W, H, L, R);
        update(id * 2 + 1, mid + 1, r, W, H, L, R);
    }
}
map<int ,int> mp;
map<int, int> rp;
int n, m, x[V], y[V], op[V], id[V], ls[V * 3];
char s[120];
int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d", &x[i], &y[i]);
            y[i] = x[i];
            scanf("%s", s);
            if(s[0] == 'U') op[i] = 0;
            else op[i] = 1;
            ls[i] = ls[i + m] = ls[i + 2 * m] = x[i];
            if(x[i] > 1)ls[i + m] = x[i] - 1;
            if(x[i] < n)ls[i + 2 * m] = x[i] + 1;
        }
        mp.clear();
        rp.clear();
        N = 1;
        mp[1] = 1;rp[1] = 1;
        sort(ls, ls + 3 * m);
        for(int i = 0; i < 3 * m; ++i)
        if(mp.find(ls[i]) == mp.end())
        {
            N++;
            rp[N] = ls[i];
            mp[ls[i]] = N;
        }
        if(mp.find(n) == mp.end())
        {
            N++;
            rp[N] = n;
            mp[n] = N;
        }
        for(int i = 0; i < m; ++i)
        id[i] = mp[x[i]];
        mp.clear();
        init(1, 1, N);
        for(int i = 0; i < m; ++i)
        {
            if(mp.find(id[i]) != mp.end())
            {
                puts("0");
                continue;
            }
            mp[id[i]] = 1;
            Node now = find(1, id[i]);
            if(op[i] == 0)
            {
                printf("%d\n", now.H + rp[now.R] - rp[id[i]] + 1);
                if(now.L < id[i])
                update(1, now.L, id[i] - 1, now.W, now.H + rp[now.R] - rp[id[i]] + 1, now.L, id[i] - 1);
                if(id[i] < now.R)
                update(1, id[i] + 1, now.R, 0, now.H, id[i] + 1, now.R);
            }
            else
            {
                printf("%d\n", now.W - rp[now.L] + rp[id[i]] + 1);
                if(now.L < id[i])
                update(1, now.L, id[i] - 1, now.W, 0, now.L, id[i] - 1);
                if(id[i] < now.R)
                update(1, id[i] + 1, now.R, now.W - rp[now.L] + rp[id[i]] + 1 , now.H, id[i] + 1, now.R);
            }
        }
    }
    return 0;
}