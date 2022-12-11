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

char str[111111];
int s1[111111];
int s2[111111];

map<int, int> mp;

int main()
{
    int n;
    scanf("%d%s",&n,str + 1);
    int ans = 0;
    mp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        s1[i] = s1[i - 1] + (str[i] == '0');
        s2[i] = s2[i - 1] + (str[i] == '1');

        mp.emplace(s1[i] - s2[i], i);
        ans = max(ans, i - mp[s1[i] - s2[i]]);
    }

    printf("%d\n", ans);
}