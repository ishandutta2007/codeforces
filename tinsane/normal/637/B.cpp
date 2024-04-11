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

const int N = 200500;

char buf[20];
string scan_token()
{
    scanf("%s", buf);
    return string(buf);
}

int n;
set<string> used;
string arr[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        arr[i] = scan_token();

    for (int i = n - 1; i >= 0; i--)
    {
        string t = arr[i];
        if (used.count(t) == 0)
        {
            printf("%s\n", t.c_str());
            used.insert(t);
        }
    }
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