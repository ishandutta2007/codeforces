#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
deque<pair<int, int>> deq;

void simulate(int x)
{
    int a = deq.back().first, b = deq.back().second;
    deq.pop_back();
    int c = a - x / b, mod = x % b;
    assert(c >= deq.back().first);
    if(mod)
    {
        if(deq.back().first == c - 1) deq.back().second += mod;
        else deq.emplace_back(c - 1, mod);
    }
    if(deq.back().first == c) deq.back().second += b - mod;
    else deq.emplace_back(c, b - mod);
    a = deq.front().first; b = deq.front().second;
    deq.pop_front();
    c = a + x / b, mod = x % b;
    assert(c <= deq.front().first);
    if(mod)
    {
        if(deq.front().first == c + 1) deq.front().second += mod;
        else deq.emplace_front(c + 1, mod);
    }
    if(deq.front().first == c) deq.front().second += b - mod;
    else deq.emplace_front(c, b - mod);
}

int main()
{
    map<int, int> m;
    int n, k;
    scanf("%d %d", &n, &k);
    while(n--)
    {
        int c;
        scanf("%d", &c);
        m[c]++;
    }
    deq.insert(deq.end(), m.begin(), m.end());
    while(k > 0)
    {
        if(deq.back().first - deq.front().first < 2) break;
        if(deq.size() == 2)
        {
            int a = deq.back().first, b = deq.back().second, c = deq.front().first, d = deq.front().second;
            int meet1 = (1LL * a * b + 1LL * c * d) / (b + d), meet2 = meet1;
            if(1LL * meet1 * (b + d) != 1LL * a * b + 1LL * c * d) meet2++;
            a = max(meet2, a - k / b);
            c = min(meet1, c + k / d);
            printf("%d\n", a - c);
            return 0;
        }
        int step = min((ll)k, min(1LL * deq.front().second * (deq[1].first - deq[0].first), 1LL * deq.back().second * 
            (deq.back().first - deq[deq.size()-2].first)));
        simulate(step);
        k -= step;
    }
    printf("%d\n", deq.back().first - deq.front().first);
}