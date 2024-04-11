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

int x[2005], y[2005];

int main()
{
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> y[i];

    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + n);

    int z = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int w = x[i] ^ y[j];
            if (binary_search(x+1,x+1+n,w) || binary_search(y+1,y+1+n,w)) ++z;
        }
    }

    if (z%2==0) cout << "Karen\n";
    else cout << "Koyomi\n";
}