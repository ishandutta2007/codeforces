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

const int mod = (int)1e9 + 7;
const int N = (int)1e5 + 100;
int fact[N];
int rfact[N];
int used[N];
int val[N];

vector <int> listD[N];
int cc = 1;

int add(int a, int b)
{
    a += b;
    if (a < 0)
        return a + mod;
    if (a < mod)
        return a;
    return a - mod;
}

int mult(int a, int b)
{
    ll c = (ll)a * b;
    return c % mod;
}

int myPow(int val, int k)
{
    if (k == 0)
        return 1;
    if (k & 1)
        return mult(myPow(val, k - 1), val);
    else
    {
        int t = myPow(val, k / 2);
        return mult(t, t);
    }
}

int getC(int a, int b)
{
    if (a < b)
        return 0;
    int x = fact[a];
    int y = mult(rfact[b], rfact[a - b]);
    return mult(x, y);
}

int solve(int n, int f)
{
    if (used[n] == cc)
        return val[n];
    int x = getC(n - 1, f - 1);
    for (int d : listD[n])
    {
        x = add(x, -solve(d, f));
    }
    used[n] = cc;
    return val[n] = x;
}



int main()
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int s = 2; s * s <= i; s++)
        {
            if (i % s == 0)
            {
                listD[i].push_back(s);
                cnt++;
                if (i / s != s)
                {
                    listD[i].push_back(i / s);
                    cnt++;
                }
            }
        }
    }

    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mult(fact[i - 1], i);
    for (int i = 0; i < N; i++)
        rfact[i] = myPow(fact[i], mod - 2);
    
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        cc++;
        int f, n;
        scanf("%d%d", &n, &f);
        if (f == 1)
        {
            if (n == 1)
                puts("1");
            else
                puts("0");
        }
        else
            printf("%d\n", solve(n, f));
    }
    
    return 0;
}