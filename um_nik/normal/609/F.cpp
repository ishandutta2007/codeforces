#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair

const int N = 200200;
int n, m;
ll a[N];
ll x[N];
int cnt[N];
ll pos[N];
ll b[N];
set<pli> c, d, e;

void tryErase(int id)
{
    if (c.find(mp(x[id], id)) == c.end()) return;
    while(true)
    {
        auto it = c.lower_bound(mp(x[id] + 1, -1));
        if (it == c.end()) break;
        int p = it->second;
        if (x[id] + a[id] < x[p] + a[p]) break;
        c.erase(it);
        d.erase(mp(x[p] + a[p], p));
    }
}

void read()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &x[i], &a[i]);
        c.insert(mp(x[i], i));
        d.insert(mp(x[i] + a[i], i));
    }
    for (int i = 0; i < n; i++)
        tryErase(i);
    return;
}

void tryEat(int id)
{
    while(true)
    {
        auto it = e.lower_bound(mp(x[id] + a[id] + 1, -1));
        if (it == e.begin()) break;
        it--;
        if (it->first < x[id]) break;
        a[id] += b[it->second];
        cnt[id]++;
        e.erase(it);
    }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    for (int i = 0; i < m; i++)
    {
        scanf("%lld%lld", &pos[i], &b[i]);
        auto it = d.lower_bound(mp(pos[i], -1));
        if (it == d.end() || x[it->second] > pos[i])
        {
            e.insert(mp(pos[i], i));
            continue;
        }
        int id = it->second;
        d.erase(mp(x[id] + a[id], id));
        a[id] += b[i];
        cnt[id]++;
        tryEat(id);
        d.insert(mp(x[id] + a[id], id));
        tryErase(id);
    }
    for (int i = 0; i < n; i++)
        printf("%d %lld\n", cnt[i], a[i]);

    return 0;
}