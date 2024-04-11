#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int K = 200001;
vector<int> divv[K];
int first[K];
int second[K];
int last[K];
int lbo[K];

vector<int> vec[K];
vector<int> vec1[K];

set<pair<int, int>> s;
ll _sum;
void insert(int p, int v)
{
    if(p == 0) return;
    auto ret = s.insert(make_pair(p, v));
    if(!ret.second) return;
    auto it = ret.first;
    auto it2 = it;
    it2++;
    if(it2->second >= v)
    {
        s.erase(it);
        return;
    }
    auto it0 = it;
    it0--;
    _sum += 1LL * (p - it0->first) * (v - it2->second);
    while(it0->second <= v)
    {
        auto next = it0;
        next--;
        _sum += 1LL * (it0->first - next->first) * (v - it0->second);
        swap(it0, next);
        s.erase(next);
    }
}

ll sum(int x)
{
//     for(auto p: s)
//         printf("%d %d\n", p.first, p.second);
//     printf("%lld\n", _sum);
//     puts("");
    auto it = s.begin();
    it++;
    while(it->first < x)
    {
        auto next = it;
        next++;
        _sum -= 1LL * it->first * (it->second - next->second);
        swap(it, next);
        s.erase(next);
    }
//     printf("sum(%d) = %lld\n", x, _sum - 1LL * (x - 1) * it->second);
    return _sum - 1LL * (x - 1) * it->second;
}

void print(int n)
{
    for(int i = 1; i <= n; i++)
        printf("%d ", s.lower_bound(make_pair(i, 0))->second);
    puts("");
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        if(divv[a].empty())
        {
            for(int j = 2; j * j <= a; j++)
                if(a % j == 0)
                {
                    divv[a].push_back(j);
                    if(j * j != a) divv[a].push_back(a / j);
                }
            divv[a].push_back(a);
        }
        for(auto d: divv[a])
        {
            if(first[d] == 0) first[d] = i;
            else if(second[d] == 0) second[d] = i;
            lbo[d] = last[d];
            last[d] = i;
        }
    }
    s.insert(make_pair(n + 1, 1));
    s.insert(make_pair(0, K));
    _sum = n;
    for(int i = 2; i < K; i++)
    {
        if(first[i] != 0 && first[i] != last[i])
            vec[first[i]+1].push_back(i);
        if(second[i])
            vec1[second[i]+1].push_back(i);
        if(lbo[i]) insert(lbo[i] - 1, i);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(auto v: vec1[i])
            insert(n, v);
        for(auto v: vec[i])
            insert(last[v]-1, v);
//         print(n);
        ans += sum(i);
    }
    printf("%lld\n", ans - 3);
}