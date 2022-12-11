#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

vector<int> crd;

int a[100005];
int b[100005];
int parent[100005];
pair<int, int> dat[100005];
int last[262144];
long long fw[100005];
void add(int pos, int val)
{
    for (++pos; pos <= 100000; pos += pos & -pos)
        fw[pos] += val;
}
long long query(int pos)
{
    long long ret = 0;
    for (++pos; pos; pos -= pos & -pos)
        ret += fw[pos];
    return ret;
}

int getparent(int t)
{
    return parent[t] == t ? t : parent[t] = getparent(parent[t]);
}

void merge(int a, int b)
{
    a = getparent(a); b = getparent(b);
    parent[max(a, b)] = min(a, b);
}

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; i < n; i++) scanf("%d",&a[i]), add(i, a[i]);
    for (int i = 0; i < n; i++) b[i] = a[i];
    crd = {a, a + n};
    sort(crd.begin(), crd.end());
    crd.erase(unique(crd.begin(), crd.end()), crd.end());
    for (int i = 0; i < n; i++)
    {
        last[lower_bound(crd.begin(), crd.end(), a[i]) - crd.begin() + 131072] = i;
    }
    for (int i = 131071; i >= 1; i--) last[i] = max(last[i << 1], last[i << 1 | 1]);

    for (int i = 0; i < m; i++) scanf("%d",&dat[i].first);
    for (int i = 0; i < m; i++) scanf("%d",&dat[i].second);

    sort(dat, dat + m, [](auto a, auto b)
    {
        if (a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    });

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        int x = lower_bound(crd.begin(), crd.end(), dat[i].first) - crd.begin();
        int L = x + 131072, R = 262143;
        int pos = 0;
        while (L <= R)
        {
            if (L & 1) pos = max(pos, last[L++]);
            L >>= 1; R >>= 1;
        }
        if (a[pos] < dat[i].first) continue;
        if (query(pos) < dat[i].second) continue;

        ++ans;

        pos = getparent(pos);
        while (dat[i].second)
        {
            int sub = min(b[pos], dat[i].second);
            dat[i].second -= sub;
            b[pos] -= sub;
            add(pos, -sub);

            if (b[pos] == 0)
            {
                if (pos)
                {
                    merge(pos - 1, pos);
                    pos = getparent(pos);
                }
            }
            else break;
        }
    }

    printf("%d\n", ans);
}