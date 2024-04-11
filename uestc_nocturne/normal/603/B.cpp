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
const int oo = 1000000010;
const int V = 1000100;
const int P = 1000000007;
int Pow(int x, int y)
{
    int ret = 1;
    while(y)
    {
        if(y & 1) ret = (LL) ret * x % P;
        x = (LL) x * x % P;
        y /= 2;
    }
    return ret;
}
int set[V], cnt[V];
int find(int x)
{
    if(x != set[x]) set[x] = find(set[x]);
    return set[x];
}
void U(int x, int y)
{
    int px = find(x);
    int py = find(y);
    set[px] = py;
}
int n, K;
int main()
{
    while(~scanf("%d%d", &n, &K))
    {
        for(int i = 1; i < n; ++i)
        {
            set[i] = i;
        }
        for(int i = 1; i < n; ++i)
            U(i, (LL)K * i % n);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i < n; ++i) cnt[find(i)]++;
        int ans = 0;
        for(int i = 1; i < n; ++i) if(cnt[i] != 0) ++ans;
        if(K == 0)printf("%d\n", Pow(n, n - 1));
        else if(K == 1) printf("%d\n", Pow(n, n));
        else printf("%d\n", Pow(n, ans));
    }
    return 0;
}