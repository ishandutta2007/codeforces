#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second 
#define mp make_pair

const int N = (int)1e6 + 10;
bool a[N];
int dp[N];

int main()
{
#ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }
    int ans = 0;
    for (int x = 1; x < N; x++)
    {
        if (!a[x]) continue;
        dp[x] = max(dp[x], 1);
        ans = max(ans, dp[x]);
        for (int y = 2 * x; y < N; y += x)
            if (a[y])
                dp[y] = max(dp[y], dp[x] + 1);
    }
    printf("%d\n", ans);

    return 0;
}