#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int d[100005], f[100005], t[100005], c[100005];
multiset<int> minfrom[100005], minto[100005];
int cnt;
long long totalcost;

void addset(int val, multiset<int> &st)
{
    if (st.empty())
    {
        ++cnt;
        totalcost += val;
        st.insert(val);
    }
    else
    {
        totalcost -= *st.begin();
        st.insert(val);
        totalcost += *st.begin();
    }
}

void deleteset(int val, multiset<int> &st)
{
    if (st.size() == 1)
    {
        --cnt;
        totalcost -= val;
        st.erase(st.find(val));
    }
    else
    {
        totalcost -= *st.begin();
        st.erase(st.find(val));
        totalcost += *st.begin();
    }
}


int main()
{
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);

    vector<pair<int, int>> events;

    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d",&d[i],&f[i],&t[i],&c[i]);

        if (f[i] == 0)
        {
            addset(c[i], minto[t[i]]);
            events.emplace_back(d[i] - k + 1, i);
        }
        else
        {
            events.emplace_back(d[i] + 1, i);
        }
    }

    sort(events.begin(), events.end());

    long long ans = LLONG_MAX;

    for (int T = 2, P = 0; T <= 3000000; T++)
    {
        while (P < events.size() && events[P].first <= T)
        {
            int idx = events[P].second;

            if (f[idx] == 0)
            {
                deleteset(c[idx], minto[t[idx]]);
            }
            else
            {
                addset(c[idx], minfrom[f[idx]]);
            }
            ++P;
        }

        if (cnt == n * 2)
        {
            ans = min(ans, totalcost);
        }
    }

    if (ans == LLONG_MAX) printf("-1\n");
    else printf("%lld\n", ans);
}