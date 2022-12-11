#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;
char bit[N];
int a[N];
int sum[N], t[N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf(" %c", &bit[i]);

    for (int i = n - 1; i >= 0; i--)
    {
        t[i] = (i == n - 1 ? 0 : t[i + 1]);
        if (bit[i] == '1')
            t[i] += a[i];
    }

    for (int i = 0; i < n; i++)
    {
        sum[i] = (i == 0 ? 0 : sum[i - 1]);
        sum[i] += a[i];
    }

    int ans = t[0];
    for (int i = 0; i < n; i++)
    {
        if (bit[i] == '1')
        {
            ans = max(ans, t[i + 1] + (i == 0 ? 0 : sum[i - 1]));
        }
    }
    cout << ans;

    return 0;
}