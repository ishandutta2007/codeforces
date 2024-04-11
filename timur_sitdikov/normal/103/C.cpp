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

char c[2];

int ans(long long n, long long k, long long s)
{
    if (!k)
        return 0;
    if (k>=(n+1)/2)
    {
        if ((s&1 ) && s<=2*(n-k)-1)
            return 0;
        else return 1;
    }
    else
    {
        if (s==n)
            return 1;
        if (n&1)
            return ans(n-1, k-1, s);
        if (s&1)
            return 0;
        if (s<=2*(n-n/2-k))
            return 0;
        return 1;
    }
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, k, i, t, s;
    c[0]='.';
    c[1]='X';
    cin >> n >> k >> t;
    for(i=0; i<t; i++)
    {
        cin >> s;
        putchar(c[ans(n, k, s)]);
    }
}