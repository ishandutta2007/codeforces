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

bool NO[13];
bool NO2[13];

int main()
{
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    if (h == 12) h = 0;
    if (t1 == 12) t1 = 0;
    if (t2 == 12) t2 = 0;

    if (s % 5 == 0)
    {
        NO[s / 5] = true;
    }

    if (s == 0 && m % 5 == 0)
    {
        NO[m / 5] = true;
    }

    if (s == 0 && m == 0) NO[h] = true;

    if (s % 5)
    {
        NO2[s / 5] = true;
    }

    if (m % 5 || s)
    {
        NO2[m / 5] = true;
    }

    if (m || s)
    {
        NO2[h] = true;
    }

    for (int T = t1;;)
    {
        if (T == t2) 
        {
            cout << "YES\n";
            return 0;
        }


        if (NO2[T]) break;
        if (NO[(T + 1) % 12]) break;
        T = (T + 1) % 12;
    }
    
    for (int T = t1;;)
    {
        if (T == t2) 
        {
            cout << "YES\n";
            return 0;
        }

        int back = (T + 11) % 12;

        if (NO2[back]) break;
        if (NO[back]) break;
        T = back;
    }

    cout << "NO\n";
}