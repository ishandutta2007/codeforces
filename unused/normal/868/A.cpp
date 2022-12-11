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

string z[105];

int main()
{
    string str;
    cin >> str;
    int n;
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        cin >> z[i];
        if (str == z[i])
        {
            cout << "YES\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (str[0] == z[i][1] && str[1] == z[j][0])
            {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
}