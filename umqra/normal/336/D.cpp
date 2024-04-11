#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;
const int N = (int)3e5;
int fact[N];

int mult(int a, int b)
{
    ll c = (ll)a * (ll)b;
    return (int)(c % (ll)mod);
}

int add(int a, int b)
{
    return (a + b < mod ? a + b : a + b - mod);
}

int myPow(int a, int k)
{
    if (k == 0)
        return 1;
    if (k & 1)
        return mult(a, myPow(a, k - 1));
    else
    {
        int t = myPow(a, k >> 1);
        return mult(t, t);
    }
}

int getC(int n, int k)
{
    if (n == 0)
        return 0;
    if (k < 0)
        return 0;
    int a = fact[n];
    int b = mult(fact[k], fact[n - k]);         
    b = myPow(b, mod - 2);  
    return mult(a, b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
                                      

    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mult(fact[i - 1], i);

    int n, m, g;
    scanf("%d%d%d", &n, &m, &g);
    int ans = 0;

    if (n + m == 1)
    {
        if ((g == 1 && m == 1) || (g == 0 && m == 0))
            puts("1");
        else
            puts("0");
        return 0;
    }

    if (g == 0)
    {
        ans = add(ans, getC(n + m - 1, m - 1));    
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
            {
                if (i == n && m <= 1)
                    ans = add(ans, 1);
            }                           
            else
            {
                ans = add(ans, getC(n + m - i - 1, m - 1));
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
            {
                ans = add(ans, getC(n + m - i - 1, m - 1));
            }
            else
            {
                if (i == n && m <= 1)
                    ans = add(ans, 1);   
            }
        }
    }

    printf("%d", ans);

    return 0;
}