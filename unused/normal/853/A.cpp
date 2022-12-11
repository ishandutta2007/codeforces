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

int c[300005];
int ans[300005];

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++) scanf("%d",&c[i]);

    priority_queue<pair<int, int>> pq;

    long long total = 0;
    long long pqsum = 0;
    int last = 1;

    for (int i = k + 1; i <= k + n; i++)
    {
        while (last <= n && last <= i)
        {
            pq.emplace(c[last], last);
            pqsum += c[last];
            total += (i - last) * 1ll * c[last];
            ++last;
        }

        auto res = pq.top();
        pq.pop();
        pqsum -= res.first;
        ans[res.second] = i;

        total += pqsum;
    }

    printf("%lld\n", total);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}