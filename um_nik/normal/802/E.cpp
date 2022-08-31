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

const int N = 250;
int a[N];

int P;
int read()
{
    //return rand() % (2 * P + 1);
 
    int x;
    scanf("%d", &x);
    return x;
}

void solve()
{
    double s = 0, s2 = 0;
    for (int i = 0; i < N; i++)
    {
        int x = read();
        a[i] = x;
        s += x;
        s2 += (double)x * x;
    }
    s /= N;
    s2 /= N;
    //printf("%d %.5lf %.5lf\n", P, s, s2);
    double y = s2 / s / s;
    //printf("%.10lf\n", y);
    if (y > 1.15)
    {
        int m = 0;
        for (int i = 0; i < N; i++)
            m = max(m, a[i]);
        int ans = m;
        while((ans + 1) / 1.045 < m) ans++;
        printf("%d\n", ans / 2);
    }
    else
    {
        printf("%d\n", (int)(s + 0.5));
    }
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

/*
    for (int i = 0; i < 10; i++)
    {
        P = 10 + rand() % 1000;
        solve();
    }
    return 0;
*/

    int t;
    scanf("%d", &t);
    while(t--) solve();

    return 0;
}