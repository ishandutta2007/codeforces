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
const int oo=1000000010;
const int V=310;
const int P=1000000007;
int dp[V][V];
int pre[V][V], suf[V][V], a[V], n, T;
int mx[V][V][30], ret[V][V];
int main()
{
    while(~scanf("%d%d", &n, &T))
    {
        for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        dp[i][j] = -oo;
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j)
            {
                for(int k = i; k < j; ++k)
                if(a[k] <= a[j])
                dp[i][j] = max(dp[i][j], dp[i][k] + 1);
            }
        }
        //for(int i = 0; i < n; ++i, puts(""))
        //for(int j = 0; j < n; ++j) printf("%d ", dp[i][j]);
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        mx[i][j][0] = dp[i][j];
        for(int L = 1; L <= 25; ++L)
        {
            for(int i = 0; i < n; ++i)
            for(int k = 0; k < n; ++k)
            pre[i][k] = suf[k][i] = mx[i][k][L] = -oo;
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    for(int k = 0; k < n; ++k)
                    {
                        if(a[j] <= a[k])
                        pre[i][k] = max(pre[i][k], mx[i][j][L - 1]);
                        if(a[i] >= a[k])
                        suf[k][j] = max(suf[k][j], mx[i][j][L - 1]);
                    }
                }
            }
            for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
            mx[i][j][L] = max(mx[i][j][L], pre[i][k] + suf[k][j]);
        }
        //puts("OK");
        int x = T - 1, L = 0;
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        ret[i][j] = dp[i][j];
        while(x)
        {
            if(x & 1)
            {
                for(int i = 0; i < n; ++i)
                for(int k = 0; k < n; ++k)
                pre[i][k] = suf[k][i] = -oo;
                for(int i = 0; i < n; ++i)
                {
                    for(int j = 0; j < n; ++j)
                    {
                        for(int k = 0; k < n; ++k)
                        {
                            if(a[j] <= a[k])
                            pre[i][k] = max(pre[i][k], ret[i][j]);
                            if(a[i] >= a[k])
                            suf[k][j] = max(suf[k][j], mx[i][j][L]);
                        }
                    }
                }
                for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                ret[i][j] = -oo;
                for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                for(int k = 0; k < n; ++k)
                ret[i][j] = max(ret[i][j], pre[i][k] + suf[k][j]);
            }
            x /= 2;
            L++;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        ans = max(ans, ret[i][j]);
        printf("%d\n", ans);
    }
}

/*

4 3
3 1 4 2


4 4
3 1 4 3

4 4
1 3 3 4

6 4
1 2 3 3 4 5

*/