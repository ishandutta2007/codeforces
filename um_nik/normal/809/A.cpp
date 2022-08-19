#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int MOD = (int)1e9 + 7;
int add(int x, int y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
int sub(int x, int y)
{
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
int mult(int x, int y)
{
    return ((ll)x * y) % MOD;
}

const int N = 300300;
int n;
int a[N];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);

    int ans = 0;

    int p = 1;
    for (int i = 0; i < n; i++)
    {
        ans = add(ans, mult(p, a[i]));
        p = add(p, p);
    }
    p = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans = sub(ans, mult(p, a[i]));
        p = add(p, p);
    }

    printf("%d\n", ans);

    return 0;
}