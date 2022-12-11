#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3001;
vector<int> vec[N];
vector<pair<int, pair<int, int>>> votes;
vector<ll> sm[N];
int rem[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        int p, c;
        scanf("%d %d", &p, &c);
        vec[p].push_back(c);
    }
    for(int i = 2; i <= m; i++)
    {
        sort(vec[i].begin(), vec[i].end());
        sm[i].resize(vec[i].size() + 1);
        for(int j = 0; j < vec[i].size(); j++)
        {
            sm[i][j+1] = sm[i][j] + vec[i][j];
            votes.emplace_back(vec[i][j], make_pair(i, j));
        }
    }
    sort(votes.begin(), votes.end());
    ll ans = 1e15;
    for(int i = 1; i <= n; i++)
    {
        int k = vec[1].size();
        ll now = 0;
        for(int j = 2; j <= m; j++)
            if(vec[j].size() >= i)
            {
                rem[j] = vec[j].size() - i + 1;
                now += sm[j][rem[j]];
                k += rem[j];
            }
            else rem[j] = 0;
        for(auto v: votes)
        {
            if(k >= i) break;
            if(v.second.second >= rem[v.second.first])
            {
                now += v.first;
                k++;
            }
        }
//         printf("   %d %lld\n", i, now);
        ans = min(ans, now);
    }
    printf("%lld\n", ans);
}