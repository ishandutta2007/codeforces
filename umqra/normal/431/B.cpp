#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
using namespace std;
                 
int p[10];
int g[10][10];

int solve()
{
    int res = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int s = i; s < 5; s += 2)
        {
            if (s + 1 >= 5)
                continue;
            int a = p[s];
            int b = p[s + 1];
            res += g[a][b] + g[b][a];
        }
    }
    return res;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int ans = 0; 
    for (int i = 0; i < 5; i++) for (int s = 0; s < 5; s++) scanf("%d", &g[i][s]);
    for (int i = 0; i < 5; i++) p[i] = i;

    do
    {
        ans = max(ans, solve());
    }
    while (next_permutation(p, p + 5));
    cout << ans;

    return 0;
}