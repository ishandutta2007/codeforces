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

const int IT = 100;
const double INF = 1e11;

const int N = 200200;
int n;
int a[N], b[N];
int k;

bool solve(double x)
{
    double sum = k * x;
    for (int i = 0; i < n; i++)
        sum -= max(0., a[i] * x - b[i]);
    return sum > 0;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll sum = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        sum += a[i];
    }
    if (sum <= k)
    {
        printf("-1\n");
        return 0;
    }
    double l = 0, r = INF;
    for (int it = 0; it < IT; it++)
    {
        double x = (l + r) / 2;
        if (solve(x))
            l = x;
        else
            r = x;
    }
    printf("%.13lf\n", l);


    return 0;
}