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

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, a, b, c, i, j, ans, tmp, tmp1;
    cin >> n >> a >> b >> c;
    ans=0;
    for(i=0; i<=c; i++)
    {
        tmp=n-2*i;
        if (tmp>=0)
        {
            tmp*=2;
            for(j=0; j<=b; j++)
            {
                tmp1=tmp-2*j;
                if (tmp1>=0 && tmp1<=a)
                    ans++;
            }
        }
    }
    cout << ans;
}