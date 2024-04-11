#include <bits/stdc++.h>
using namespace std;

long double dp1[1001][1001];
long double dp2[1001][1001];
bool v1[1001][1001];
bool v2[1001][1001];

long double D(int, int); long double E(int, int);

long double D(int w, int b)
{
    if (w == 0) return 0;
    if (b == 0) return 1;

    if (v1[w][b] == false)
    {
        v1[w][b] = true;

        dp1[w][b] = (long double)w / (w+b) +
            (long double)b / (w+b) * E(w, b - 1);
    }
    return dp1[w][b];
}

long double E(int w, int b)
{
    if (w == 0 || b == 0) return 0;

    if (v2[w][b] == false)
    {
        v2[w][b] = true;

        dp2[w][b] = (long double)b / (w+b) *
        (D(w - 1, b - 1) * w / (w + b - 1) + 
            (b >= 2 ? D(w, b - 2) * (b - 1) / (w + b - 1) : 0));
    }
    return dp2[w][b];
}

int main()
{
    int w, b;
    scanf("%d%d",&w,&b);

    printf("%.12Lf\n", D(w, b));
}