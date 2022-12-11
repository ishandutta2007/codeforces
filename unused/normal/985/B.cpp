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

vector<string> vt;
int cnt[2002];
int n, m, cl, ce, v;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vt.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vt[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cnt[j] += vt[i][j] - '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool yes = true;
        for (int j = 0; j < m; j++)
        {
            if (cnt[j] == vt[i][j] - '0') { yes = false; break; }
        }
        if (yes)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}