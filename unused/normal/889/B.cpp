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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

string str[100005];
set<int> graph[26];
int deg[26];
bool used[26];

string ans;

void dfs(int t)
{
    if (ans.size() > 26)
    {
        printf("NO\n");
        exit(0);
    }
    ans.push_back(t + 'a');
    for (int nxt : graph[t])
    {
        dfs(nxt);
    }
}

int main()
{
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        bool z[26] = {};
        for (int t : str[i])
        {
            if (z[t - 'a'])
            {
                printf("NO\n");
                return 0;
            }
            z[t - 'a'] = true;
            used[t - 'a'] = true;
        }

        for (int j = 1; j < str[i].size(); j++)
        {
            graph[str[i][j-1] - 'a'].insert(str[i][j] - 'a');
        }
    }

    for (int i = 0; i < 26; i++) if (graph[i].size() >= 2)
    {
        printf("NO\n");
        return 0;
    }

    for (int i = 0; i < 26; i++) for (int t : graph[i]) deg[t]++;

    for (int i = 0; i < 26; i++)
    {
        if (deg[i] == 0 && used[i]) dfs(i);
    }

    if (ans.size() != accumulate(used, used + 26, 0))
    {
        printf("NO\n");
        return 0;
    }

    printf("%s\n", ans.c_str());
}