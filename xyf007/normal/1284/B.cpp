#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, l[100001], b[100001], tmp;
vector<int> a[100001];
bool ok[100001];
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        bool f = 1;
        scanf("%d", &l[i]);
        for (int j = 0; j < l[i]; j++)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
            if (j && a[i][j] > a[i][j - 1])
            {
                f = 0;
            }
        }
        if (f)
        {
            ok[i] = 1;
            b[++tmp] = a[i][0];
        }
    }
    sort(b + 1, b + tmp + 1);
    long long ans = 1LL * n * n;
    for (int i = 1; i <= n; i++)
    {
        if (ok[i])
        {
            ans -= upper_bound(b + 1, b + tmp + 1, a[i][l[i] - 1]) - b - 1;
        }
    }
    printf("%lld", ans);
    return 0;
}