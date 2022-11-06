#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

const int maxn=1000005;
pair<int, int> mm[maxn], tmp[maxn];
long long lval[maxn], rval[maxn];

void my_merge(int l1, int r1, int r2)
{
    int l2 = r1 + 1, i, i1, i2, sz;
    for(i1 = l1, i2 = l2, i = 0; i1 <= r1 && i2 <= r2; )
    {
        if (mm[i1].first < mm[i2].first)
        {
            lval[mm[i1].second] += i2 - l2;
            tmp[i++] = mm[i1++];
        }       
        else
        {
            rval[mm[i2].second] += r1 - i1 + 1;
            tmp[i++] = mm[i2++];
        }
    }
    for(; i1 <= r1; )
    {
        lval[mm[i1].second] += r2 - l2 + 1;
        tmp[i++] = mm[i1++];
    }
    for(; i2 <=r2; )
    {
        //rval[mm[i2].second] += r1 - i1 + 1;
        tmp[i++] = mm[i2++];
    }
    sz = i;
    for(i = 0; i<sz; i++)
        mm[l1 + i] = tmp[i];
}

void my_sort(int sz)
{
    int len, i, last = 1;
    for(len = 2; ; len = min (sz, len * 2))
    {
        for(i = 0; i < sz; i+=len)
            my_merge(i, min(i + last - 1, sz-1), min(i + len - 1, sz - 1));
        last = len;
        if (len == sz)
            break;
    }
}


int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, i;
    long long ans;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &mm[i].first);
        mm[i].second = i;
    }
    my_sort(n);
    ans = 0;
    for(i = 0; i < n; i++)
        ans += lval[i] * rval[i];
    cout << ans;
}