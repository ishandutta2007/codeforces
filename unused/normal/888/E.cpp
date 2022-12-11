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
#include <cassert>
using namespace std;

vector<int> v1, v2;

int a[40];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);

    for (int i = 0; i < (1 << (n / 2)); i++)
    {
        int sum = 0;
        for (int j = 0; j < n / 2; j++)
        {
            if (i & (1 << j)) sum = (sum + a[j]) % m;
        }
        v1.push_back(sum);
    }
    
    for (int i = 0; i < (1 << (n - n / 2)); i++)
    {
        int sum = 0;
        for (int j = 0; j < n - n / 2; j++)
        {
            if (i & (1 << j)) sum = (sum + a[j + n / 2]) % m;
        }
        v2.push_back(sum);
    }

    sort(v1.begin(), v1.end());

    int ans = 0;
    for (int t : v2)
    {
        ans = max(ans, (t + v1.back()) % m);
        auto itr = lower_bound(v1.begin(), v1.end(), m - t);
        if (itr != v1.begin()) ans = max(ans, (t + itr[-1]) % m);
    }
    printf("%d\n", ans);
}