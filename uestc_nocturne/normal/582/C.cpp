/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=200100;
const int P=1000000007;
int gcd(int x, int y)
{
    if(!x) return y;
    if(!y) return x;
    return gcd(y, x % y);
}
int a[V], mx[V], can[V], seg[V], g[V], n;
int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; ++i)
        g[i] = gcd(i, n);
        LL ret = 0;
        for(int L = 1; L < n; ++L)
        {
            if(n % L != 0) continue;
            memset(mx, 0, sizeof(mx));
            for(int i = 0; i < n; ++i)
            if(mx[i % L] < a[i]) mx[i % L] = a[i];
            for(int i = 0; i < n; ++i)
            if(mx[i % L] == a[i]) can[i] = 1;
            else can[i] = 0;
            int sn = 0, now = 0;
            for(int i = 0; i < n; ++i)
            {
                if(can[i] == 1)
                {
                    ++now;
                }
                else if(now != 0)
                {
                    seg[sn++] = now;
                    now = 0;
                }
            }
            if(now != 0) seg[sn++] = now;
            if(can[0] && can[n - 1] && sn > 1)
            seg[0] += seg[--sn];
            //printf("L %d\n", L);
            //for(int i = 0; i < sn; ++i) printf("%d ",seg[i]);puts("");
            if(sn == 1 && seg[0] == n)
            {
                for(int j = 1; j * L < n; ++j)
                if(g[j * L] == L)
                ret += n;
            }
            else
            {
                for(int i = 0; i < sn; ++i)
                {
                    for(int j = 1; j * L <= seg[i]; ++ j)
                    if(g[j * L] == L)
                    ret += max(0, seg[i] - j * L + 1);
                }
            }
        }
        cout << ret << endl;
    }
}

/*

4
7 1 2 3

2
2 1

3
1 1 1

*/