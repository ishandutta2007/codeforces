#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

int x[1000];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    double ans = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ans = max(ans, (double)(x[a] + x[b]) / (double)c);
    }
    printf("%.11lf", ans);
    return 0;
}