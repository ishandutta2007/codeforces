#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;
const int pow2 = (1 << 17);
int cost[N], to[N];
int p[N];
set <pii> setVote[N];
int cnt[N];

bool cmp(int a, int b)
{
    return cost[a] < cost[b];
}

struct SegmentTree
{
    int tree[pow2 * 2];
    int cnt[pow2 * 2];
    void build()
    {
        for (int i = 0; i < pow2 * 2; i++)
        {
            tree[i] = 0;
            cnt[i] = 0;
        }
    }
    void setVal(int pos, int val, int v = 1, int l = 0, int r = pow2 - 1)
    {
        if (l == r)
        {
            tree[v] = (val == -1 ? 0 : val);
            cnt[v] = (val == -1 ? 0 : 1);
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m)
            setVal(pos, val, 2 * v, l, m);
        else
            setVal(pos, val, 2 * v + 1, m + 1, r);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
        cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
    }
    int getSum(int k, int v = 1, int l = 0, int r = pow2 - 1)
    {
        if (l == r)
        {
            if (k == 0)
                return 0;
            return tree[v];
        }
        int m = (l + r) / 2;
        if (cnt[2 * v] >= k)
            return getSum(k, 2 * v, l, m);
        else
            return getSum(k - cnt[2 * v], 2 * v + 1, m + 1, r) + tree[2 * v];
    }
} tree;

set <pii> listH;
int rp[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &to[i], &cost[i]);
        p[i] = i;
        setVote[to[i]].insert(mp(cost[i], i));
        cnt[to[i]]++;
    }
    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++)
    {
        rp[p[i]] = i;
        if (to[p[i]] != 0)
        {
            tree.setVal(i, cost[p[i]]);
        }
    }
    int mx = 0;
    for (int i = 1; i < N; i++)
    {
        mx = max(mx, cnt[i]);
        if (cnt[i] != 0)
            listH.insert(mp(-cnt[i], i));
    }
    if (mx < cnt[0])
    {
        cout << 0;
        return 0;
    }
    int ans = (int)1e9;
    int curAns = 0;
    for (int i = mx; i >= 0; i--)
    {
        while (1)
        {
            pii x = *listH.begin();
            int h = -x.X;
            int ind = x.Y;
            if (h <= i)
                break;
            pii voter = *setVote[ind].begin();
            curAns += voter.X;
            tree.setVal(rp[voter.Y], -1);
            setVote[ind].erase(voter);
            listH.erase(x);
            listH.insert(mp(-(h - 1), ind));
            cnt[0]++;
        }
        ans = min(ans, curAns + tree.getSum(max(0, (i + 1) - cnt[0])));
    }
    cout << ans;
    
    return 0;
}