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
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int len[100005];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k, l;
    cin >> n >> k >> l;

    for (int i = 0; i < n * k; i++)
    {
        cin >> len[i];
    }

    sort(len, len + n * k);

    long long ans = 0;

    int X = upper_bound(len, len + n * k, len[0] + l) - len;

    if (X < n)
    {
        cout << 0;
        return 0;
    }

    multiset<int> st1{len, len + X};
    int st2num = n * k - X;

    for (int i = 0; i < n; i++)
    {
        int z = *st1.begin();
        st1.erase(st1.begin());

        for (int j = 1; j < k; j++)
        {
            if (st1.size() > n - i - 1)
            {
                st1.erase(st1.begin());
            }
            else --st2num;
        }

        ans += z;
    }

    cout << ans;
}