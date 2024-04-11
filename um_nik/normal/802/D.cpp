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

int P;
int read()
{
    int x;
    scanf("%d", &x);
    return x;
    //return rand() % (2 * P + 1);
}

void solve()
{
    double s = 0, s2 = 0;
    for (int i = 0; i < N; i++)
    {
        int x = read();
        s += x;
        s2 += (double)x * x;
    }
    s /= N;
    s2 /= N;
    //printf("%d %.5lf %.5lf\n", P, s, s2);
    double y = s2 / s / s;
    //printf("%.10lf\n", y);
    if (y > 1.15)
        printf("uniform\n");
    else
        printf("poisson\n");
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