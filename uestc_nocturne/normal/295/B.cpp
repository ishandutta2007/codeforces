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
const int V = 510;
int d[V][V], del[V], in[V], n;
LL ans[V];
int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        scanf("%d", &d[i][j]);
        LL ret = 0;
        for(int i = 1; i <= n; i++)
        scanf("%d", &del[i]);
        memset(in, 0, sizeof(in));
        for(int vn = n; vn > 0; vn--)
        {
            int k = del[vn];
            in[k] = 1;
            for(int j = 1; j <= n ;j++)
            if(in[j]) ret += d[k][j] + d[j][k];
            for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                int tmp = d[i][k] + d[k][j];
                if(tmp < d[i][j])
                {
                    if(in[i] && in[j])
                    ret -= d[i][j] - tmp;
                    d[i][j] = tmp;
                }
            }
            ans[vn] = ret;
        }
        for(int i = 1; i <= n; i++)
        printf("%I64d ",ans[i]);
    }
}