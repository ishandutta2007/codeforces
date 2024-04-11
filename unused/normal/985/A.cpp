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

vector<int> vt;
string str;
int n, m, cl, ce, v;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vt.resize(n / 2);
    for (int i = 0; i < n / 2; i++)
    {
        cin >> vt[i];
    }

    sort(vt.begin(), vt.end());
    int ans = 0, ans2 = 0;

    for (int i = 0; i < n / 2; i++)
    {
        ans += abs((i * 2 + 1) - vt[i]);
        ans2 += abs((i * 2 + 2) - vt[i]);
    }

    cout << min(ans, ans2);
}