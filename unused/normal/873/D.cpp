#pragma GCC target("popcnt")
#include <cctype>
#include <cassert>
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

int n, k;
int ans[111111];

void test_merge(int l, int r)
{
    if (k < 0)
    {
        printf("-1\n");
        exit(0);
    }

    if (l + 1 == r) return;

    int mid = (l + r) / 2;

    if (k == 0) return;

    swap(ans[mid - 1], ans[mid]);

    k -= 2;
    test_merge(l, mid);
    test_merge(mid, r);
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++) ans[i] = i + 1;

    --k;
    test_merge(0, n);

    if (k)
    {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");
}