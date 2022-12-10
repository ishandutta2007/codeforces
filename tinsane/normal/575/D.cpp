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

const int n = 1000;

void solve()
{
    printf("%d\n", n * 2 - 2);
    for(int i = 2; i <= n; ++i)
        printf("%d %d %d %d\n", i, 1, i, 2);
    for(int i = n; i >= 2; --i)
        printf("%d %d %d %d\n", i, 1, i, 2);
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