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

int a[100005];

int main()
{
    cin.sync_with_stdio(false);
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    for (int i = 1; i <= n; i++) cin >> a[i];

    long long ans = LLONG_MIN;

    long long d2 = LLONG_MIN;
    int maxima = a[n];

    for (int i = n; i >= 1; i--)
    {
        if (r < 0) maxima = min(maxima, a[i]);
        else maxima = max(maxima, a[i]);

        d2 = max(d2, maxima * 1ll * r + a[i] * 1ll * q);
        ans = max(ans, a[i] * 1ll * p + d2);
    }

    cout << ans;
}