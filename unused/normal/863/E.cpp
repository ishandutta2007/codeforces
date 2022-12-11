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

// example implementation of sum tree
const int TSIZE = 2097152; // always 2^k form && n <= TSIZE
int segtree[TSIZE * 2], prop[TSIZE * 2];
void seg_relax(int nod, int l, int r) {
    if (prop[nod] == 0) return;
    if (l < r) {
        segtree[nod << 1] += prop[nod];
        prop[nod << 1] += prop[nod];
        segtree[nod << 1 | 1] += prop[nod];
        prop[nod << 1 | 1] += prop[nod];
    }
    prop[nod] = 0;
}
int seg_query(int nod, int l, int r, int s, int e) {
    if (r < s || e < l) return 2e9;
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
// usage:
// seg_update(1, 0, n - 1, qs, qe, val);
// seg_query(1, 0, n - 1, qs, qe);

int l[200005], r[200005];
vector<int> crd;

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        crd.push_back(l[i]-1);
        crd.push_back(l[i]);
        crd.push_back(l[i]+1);
        crd.push_back(r[i]-1);
        crd.push_back(r[i]);
        crd.push_back(r[i]+1);
    }
    sort(crd.begin(),crd.end());
    crd.erase(unique(crd.begin(),crd.end()),crd.end());
    for (int i = 0; i < n; i++)
    {
        l[i]=lower_bound(crd.begin(),crd.end(),l[i])-crd.begin();
        r[i]=lower_bound(crd.begin(),crd.end(),r[i])-crd.begin();
        seg_update(1, 0, TSIZE - 1, l[i], r[i], 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (seg_query(1, 0, TSIZE - 1, l[i], r[i]) > 1)
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
}