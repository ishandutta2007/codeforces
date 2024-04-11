#include <cstdio>
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
using namespace std;
using namespace chrono;

const int TSIZE = 131072; // always 2^k form && n <= TSIZE
int segtree[TSIZE * 2];
int prop[TSIZE * 2];
void seg_relax(int nod, int l, int r) {
    if (prop[nod] == 0) return;
    if (l < r) {
        int m = (l + r) >> 1;
        segtree[nod << 1] += prop[nod];
        segtree[nod << 1 | 1] += prop[nod];
        prop[nod << 1] += prop[nod];
        prop[nod << 1 | 1] += prop[nod];
    }
    prop[nod] = 0;
}
int seg_query(int nod, int l, int r, int s, int e) {
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return segtree[nod];
    seg_relax(nod, l, r);
    int m = (l + r) >> 1;
    return min(seg_query(nod << 1, l, m, s, e), seg_query(nod << 1 | 1, m + 1, r, s, e));
}
void seg_update(int nod, int l, int r, int s, int e, int val) {
    if (r < s || e < l) return;
    if (s <= l && r <= e) {
        segtree[nod] += val;
        prop[nod] += val;
        return;
    }
    seg_relax(nod, l, r);
    int m = (l + r) >> 1;
    seg_update(nod << 1, l, m, s, e, val);
    seg_update(nod << 1 | 1, m + 1, r, s, e, val);
    segtree[nod] = min(segtree[nod << 1], segtree[nod << 1 | 1]);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n, m;
        scanf("%d%d",&n,&m);

        memset(segtree, 0, sizeof(segtree));
        memset(prop, 0, sizeof(prop));

        vector<int> a(n);
        vector<pair<long long, vector<int>>> b;

        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            seg_update(1, 0, 100000, 0, a[i], 1);
        }

        for (int i = 0; i < m; i++)
        {
            int x;
            scanf("%d",&x);
            vector<int> c(x);
            for (int j = 0; j < x; j++)
            {
                scanf("%d",&c[j]);
            }
            long long sum = accumulate(c.begin(), c.end(), 0LL);
            seg_update(1, 0, 100000, 0, (sum + x - 1) / x, -1);
            b.emplace_back(accumulate(c.begin(), c.end(), 0LL), move(c));
        }

        for (int i = 0; i < m; i++)
        {
            seg_update(1, 0, 100000, 0, (b[i].first + b[i].second.size() - 1) / b[i].second.size(), 1);

            for (int j : b[i].second)
            {
                seg_update(1, 0, 100000, 0, (b[i].first - j + b[i].second.size() - 2) / (b[i].second.size() - 1), -1);
                printf("%d", segtree[1] >= 0);
                seg_update(1, 0, 100000, 0, (b[i].first - j + b[i].second.size() - 2) / (b[i].second.size() - 1), 1);
            }

            seg_update(1, 0, 100000, 0, (b[i].first + b[i].second.size() - 1) / b[i].second.size(), -1);
        }
        printf("\n");
    }
}