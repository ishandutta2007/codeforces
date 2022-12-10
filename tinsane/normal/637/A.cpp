#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 1000500;

int n;
pair<int, int> likes[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        likes[x].first++;
        likes[x].second = -i;
    }

    pair<int, int> best;
    int best_who = -1;
    for (int i = 0; i < N; i++)
        if (likes[i] > best)
        {
            best = likes[i];
            best_who = i;
        }

    printf("%d\n", best_who);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}