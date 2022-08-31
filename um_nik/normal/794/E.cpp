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

const int LOG = 19;
const int N = 300300;
int a[N];
int p2[N];
int n;
int s1[LOG][N], s2[LOG][N];

int getS1(int l, int r)
{
    int k = p2[r - l];
    return max(s1[k][l], s1[k][r - (1 << k)]);
}
int getS2(int l, int r)
{
    int k = p2[r - l];
    return max(s2[k][l], s2[k][r - (1 << k)]);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n - 1; i++)
        s1[0][i] = max(a[i], a[i + 1]);
    for (int k = 1; k < LOG; k++)
        for (int i = 0; i + (1 << k) <= n - 1; i++)
            s1[k][i] = max(s1[k - 1][i], s1[k - 1][i + (1 << (k - 1))]);

    for (int i = 1; i < n - 1; i++)
        s2[0][i] = min(a[i], max(a[i - 1], a[i + 1]));
    for (int k = 1; k < LOG; k++)
        for (int i = 0; i + (1 << k) <= n - 1; i++)
            s2[k][i] = max(s2[k - 1][i], s2[k - 1][i + (1 << (k - 1))]);

    for (int i = 2; i < N; i++)
        p2[i] = p2[i / 2] + 1;

    for (int k = 0; k < n - 1; k++)
    {
        int len = n - k;
        if (len % 2 == 0)
        {
            int l = len / 2 - 1;
            int r = l + k + 1;
            printf("%d ", getS1(l, r));
        }
        else
        {
            int l = len / 2;
            int r = l + k + 1;
            printf("%d ", getS2(l, r));
        }
    }
    int res = a[0];
    for (int i = 0; i < n; i++)
        res = max(res, a[i]);
    printf("%d\n", res);

    return 0;
}