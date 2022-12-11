#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
unordered_map<ll, pair<int, ll>> ans;

pair<int, ll> go(ll x)
{
    if(x == 0) return make_pair(0, 0LL);
    auto &an = ans[x];
    if(an.first == 0)
    {
        ll a = pow(x, 1.0 / 3), a3 = a * a * a;
        if(a3 > x)
        {
            a--;
            a3 = a * a * a;
        }
        else if((a+1) * (a+1) * (a+1) <= x)
        {
            a++;
            a3 = a * a * a;
        }
        auto an1 = go(a3 - 1), an2 = go(x - a3);
        an = max(an1, make_pair(an2.first + 1, an2.second + a3));
    }
    return an;
}

int main()
{
    ll m;
    scanf("%lld", &m);
    go(m);
    printf("%d %lld\n", ans[m].first, ans[m].second);
}