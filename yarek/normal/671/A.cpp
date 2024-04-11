#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double dist(ll x1, ll y1, ll x2, ll y2)
{
    x1 -= x2; y1 -= y2;
    return sqrt(x1 * x1 + y1 * y1);
}

const double inf = 1e15;
const int N = 100002;
double diffA[N];
double diffB[N];
double minpA[N];
double minpB[N];
double minsA[N];
double minsB[N];

int main()
{
    double sum = 0;
    int ax, ay, bx, by, tx, ty;
    scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        double da = dist(x, y, ax, ay), db = dist(x, y, bx, by), dt = dist(x, y, tx, ty);
        sum += dt * 2;
        diffA[i] = da - dt;
        diffB[i] = db - dt;
    }
    minpA[0] = inf;
    minpB[0] = inf;
    for(int i = 1; i <= n; i++)
    {
        minpA[i] = min(minpA[i-1], diffA[i]);
        minpB[i] = min(minpB[i-1], diffB[i]);
    }
    minsA[n+1] = inf;
    minsB[n+1] = inf;
    for(int i = n; i > 0; i--)
    {
        minsA[i] = min(minsA[i+1], diffA[i]);
        minsB[i] = min(minsB[i+1], diffB[i]);
    }
    double ans = min(minpA[n], minpB[n]);
    for(int i = 1; i <= n; i++)
    {
        ans = min(ans, diffA[i] + min(minpB[i-1], minsB[i+1]));
        ans = min(ans, diffB[i] + min(minpA[i-1], minsA[i+1]));
    }
    printf("%.10lf\n", sum + ans);
}