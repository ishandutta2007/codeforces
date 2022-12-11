#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500003;
const ll inf = 1000000001;
ll t[N];

struct seg
{
    int a, b;
    ll expand;
};

struct segcomp
{
    bool operator()(const seg &a, const seg &b)
    {
        return a.b < b.b;
    }
};

seg join(seg a, seg b)
{
    assert(a.b + 1 == b.a);
    return { a.a, b.b, a.expand + b.expand - (t[b.a] - t[a.b]) };
}

seg single(int a)
{
    return { a, a + 1, t[a+2] - t[a-1] - 2 * (t[a+1] - t[a]) };
}

seg expanded(seg s)
{
    return { s.a - 1, s.b + 1, t[s.a-1] - t[s.a-2] + t[s.b+2] - t[s.b+1] - s.expand };
}

bool operator<(const seg &a, const seg &b)
{
    return a.expand < b.expand;
}

set<seg, segcomp> segs;

void insert(seg s)
{
    auto it = segs.lower_bound(s);
    if(it != segs.end() && s.b + 1 == it->a)
    {
        auto t = *it;
        segs.erase(it);
        insert(join(s, t));
        return;
    }
    if(it != segs.begin())
    {
        it--;
        if(it->b + 1 == s.a)
        {
            auto t = *it;
            segs.erase(it);
            insert(join(t, s));
            return;
        }
    }
    segs.insert(s);
}

void erase(seg s)
{
    segs.erase(s);
}

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    t[0] = -inf;
    t[n+1] = inf * 2;
    for(int i = 1; i <= n; i++)
        scanf("%lld", t + i);
    sort(t + 1, t + n + 1);
    priority_queue<pair<ll, int>> pq;
    for(int i = 1; i < n; i++)
        pq.push({ -(t[i+1] - t[i]), i });
    for(int i = 1; i <= k; i++)
        pq.push({ -inf, 0 });
    segs.insert({ n + 2, n + 3, inf });
    ll ans = 0;
    int done = 0;
    while(done < k)
    {
        ll c = -pq.top().first, a = pq.top().second;
        auto s = *min_element(segs.begin(), segs.end());
        if(c >= s.expand)
        {
            erase(s);
//              printf("expand %d %d\n", s.a, s.b);
            ans += s.expand;
            insert(expanded(s));
            done++;
            continue;
        }
        pq.pop();
        auto it = segs.lower_bound({ a, a, 0 });
        if(it->a <= a + 1) continue;
        ans += t[a+1] - t[a];
        insert(single(a));
//          printf("single %d\n", a);
        done++;
    }
    printf("%lld\n", ans);
}