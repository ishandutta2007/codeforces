#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <random>
#include <limits>
#include <chrono>
#include <ctime>
#include <bitset>
#include <list>
#include <stack>
using namespace std;

int tr[524288];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++) scanf("%d",&tr[i + 262144]);
    for (int i = 262143; i >= 1; i--)
    {
        tr[i] = max(tr[i << 1], tr[i << 1 | 1]);
    }
    int q;
    scanf("%d",&q);
    while (q--)
    {
        int xs, ys, xf, yf, k;
        scanf("%d%d%d%d%d",&xs,&ys,&xf,&yf,&k);
        if (abs(xs - xf) % k || abs(ys - yf) % k)
        {
            printf("NO\n");
            continue;
        }

        // xs + x * k <= n
        // x * k <= n - xs
        // x <= (n - xs) / k

        int topmost = xs + (n - xs) / k * k;

        int l = ys + 262144, r = yf + 262144;
        if (l > r) swap(l, r);
        int ans = 0;
        while (l <= r)
        {
            if (l & 1) ans = max(ans, tr[l++]);
            if (!(r & 1)) ans = max(ans, tr[r--]);
            l >>= 1; r >>= 1;
        }
        if (ans < topmost) printf("YES\n");
        else printf("NO\n");
    }
}