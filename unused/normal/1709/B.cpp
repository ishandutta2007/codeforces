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

int a[100005];
long long b[100005], c[100005];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1; i < n; i++) b[i] = b[i - 1] + max(0, a[i] - a[i + 1]);
    for (int i = 1; i < n; i++) c[i] = c[i - 1] + max(0, a[i + 1] - a[i]);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        if (x < y) printf("%lld\n", b[y - 1] - b[x - 1]);
        else printf("%lld\n", c[x - 1] - c[y - 1]);
    }
}