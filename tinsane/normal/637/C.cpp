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

const int N = 1005;

char buf[10];
string scan_token()
{
    scanf("%s", buf);
    return string(buf);
}

int n;
string arr[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        arr[i] = scan_token();

    int res = 6;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int diff = 0;
            for (int x = 0; x < 6; x++)
                if (arr[i][x] != arr[j][x])
                    diff++;
            res = min(res, (diff + 1) / 2 - 1);
        }

    printf("%d\n", res);
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