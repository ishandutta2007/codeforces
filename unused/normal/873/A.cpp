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

int a[111];

int main()
{
    int n, k, x;
    scanf("%d%d%d",&n,&k,&x);
    for (int i= 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        if (k && a[i] > x) ans += x, --k;
        else ans += a[i];
    }
    printf("%d\n", ans);
}