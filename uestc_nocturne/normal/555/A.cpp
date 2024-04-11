/*
    Author:USETC_elfness
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
typedef long long LL;
const int V=100100;
const int P=1000000007;
using namespace std;
int n, m, x, y;
int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        int ret = n + n - m + 1;
        for(int i = 0; i < m; ++i)
        {
            scanf("%d", &x);
            int pre = 0, st = 0;
            for(int j = 0; j < x; ++j)
            {
                scanf("%d", &y);
                if(st == 0)
                {
                    if(y == pre + 1) ret -= 2;
                    else st = 1;
                }
                pre = y;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}