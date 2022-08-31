#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/*
const int M = (int)1e8;
char buf[M];
int mpos = 0;
inline void* operator new(size_t n)
{
    mpos += n;
    if (mpos >= M) throw;
    return buf + mpos - n;
}
*/

typedef long long ll;

const int Z = (int)5e5 + 100;
const int N = 2 * Z + 1000;
const ll MOD = (ll)1e9 + 7;
char s[N];
ll _X[N], _Y[N];
ll *X = _X + Z;
ll *Y = _Y + Z;
int n;
ll w, h;
vector<ll> xs, ys;

ll add(ll x, ll y)
{
    return (x + y) % MOD;
}
ll mult(ll x, ll y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

void read()
{
    scanf("%d%lld%lld", &n, &h, &w);
    scanf(" %s", s);
    for (int x = -w; x <= w; x++)
        X[x] = -1;
    for (int y = -h; y <= h; y++)
        Y[y] = -1;
    X[0] = Y[0] = 0;
    int xx = 0, yy = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
            yy++;
        else if (s[i] == 'D')
            yy--;
        else if (s[i] == 'L')
            xx--;
        else
            xx++;
        if (X[xx] == -1)
            X[xx] = i + 1;
        if (Y[yy] == -1)
            Y[yy] = i + 1;
    }
    if (xx > 0)
    {
        int pos = 0;
        while(pos <= w && X[pos] != -1)
            pos++;
        while(pos <= w)
        {
            X[pos] = X[pos - xx] + (ll)n;
            pos++;
        }
    }
    if (xx < 0)
    {
        int pos = 0;
        while(pos >= -w && X[pos] != -1)
            pos--;
        while(pos >= -w)
        {
            X[pos] = X[pos - xx] + (ll)n;
            pos--;
        }
    }
    if (yy > 0)
    {
        int pos = 0;
        while(pos <= h && Y[pos] != -1)
            pos++;
        while(pos <= h)
        {
            Y[pos] = Y[pos - yy] + (ll)n;
            pos++;
        }
    }
    if (yy < 0)
    {
        int pos = 0;
        while(pos >= -h && Y[pos] != -1)
            pos--;
        while(pos >= -h)
        {
            Y[pos] = Y[pos - yy] + (ll)n;
            pos--;
        }
    }

    return;
}


int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    
    int xL = -1, xR = 1;
    while((int)xs.size() < w && (X[xL] != -1 || X[xR] != -1))
    {
        if (X[xL] == -1)
            xs.push_back(X[xR++]);
        else if (X[xR] == -1)
            xs.push_back(X[xL--]);
        else if (X[xL] < X[xR])
            xs.push_back(X[xL--]);
        else
            xs.push_back(X[xR++]);
    }
    int yL = -1, yR = 1;
    while((int)ys.size() < h && (Y[yL] != -1 || Y[yR] != -1))
    {
        if (Y[yL] == -1)
            ys.push_back(Y[yR++]);
        else if (Y[yR] == -1)
            ys.push_back(Y[yL--]);
        else if (Y[yL] < Y[yR])
            ys.push_back(Y[yL--]);
        else
            ys.push_back(Y[yR++]);
    }
    if ((int)xs.size() < w && (int)ys.size() < h)
    {
        printf("-1\n");
        return 0;
    }

    /*
    for (ll x : xs)
        printf("%lld ", x);
    printf("\n");
    for (ll y : ys)
        printf("%lld ", y);
    printf("\n");
    */

    ll ans = 0;
    int itX = 0, itY = 0;
    while(itX < w && itY < h)
    {
        if (itX == (int)xs.size())
            ans = add(ans, mult(ys[itY++], w - itX));
        else if (itY == (int)ys.size())
            ans = add(ans, mult(xs[itX++], h - itY));
        else if (xs[itX] < ys[itY])
            ans = add(ans, mult(xs[itX++], h - itY));
        else
            ans = add(ans, mult(ys[itY++], w - itX));
    }
    printf("%lld\n", ans);

    return 0;
}