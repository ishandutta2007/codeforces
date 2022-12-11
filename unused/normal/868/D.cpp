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

string str[222];
int ans[222];

bool check(string s, int k)
{
    vector<char> vis(1 << k);
    for (char *p = strtok(&s[0], " "); p; p = strtok(nullptr, " "))
    {
        int len = strlen(p);
        int num = 0;
        for (int i = 0; i < k; i++)
        {
            num = num * 2 + p[i] - '0';
        }
        vis[num] = true;
        for (int i = k; i < len; i++)
        {
            num = num * 2 + p[i] - '0';
            num &= (1 << k) - 1;
            vis[num] = true;
        }
    }
    return accumulate(vis.begin(), vis.end(), 0) == 1 << k;
}

int main()
{
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> str[i];
    int m;
    cin >> m;
    for (int i = n + 1; i <= n + m; i++)
    {        
        int A, B;
        cin >> A >> B;
        auto &a = str[A];
        auto &b = str[B];

        if (a.size() <= 50000) str[i] = a;
        else str[i] = a.substr(0, 24999) + " " + a.substr(a.size() - 24999);
        if (b.size() <= 50000) str[i] += b;
        else str[i] += b.substr(0, 24999) + " " + b.substr(b.size() - 24999);

        for (int j = 1;; j++)
        {
            if (check(str[i], j) == false)
            {
                printf("%d\n", j - 1);
                break;
            }
        }
    }
}