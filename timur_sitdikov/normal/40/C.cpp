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

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, m, x, y, i, ans, l1, l2, d, d2;
    cin >> n >> x >> m >> y;
    y-=x;
    x=0;
    if (y<0)
        y=-y;
    /*if (n>m)
        swap(n, m);
    if (y-m<=-n)
        ans=1;
    else ans=min(n+1, y-m+n+1); 
    d=-1;*/
    ans=n+1;
    if (y-m<=-n)
    {
        ans+=(-n-y+m+1);
        m=y+n-1;
    }
    for(i=1; i<=m; i++)
    {
        d=0;
        d2=0;
        if (y-i<0)
        {
            l1=-(y-i);
            d2=1;
        }
        else
            l1=min(n+1, y-i);
        if (y-i==0)
            l1=0;
        l2=min(n+1, y+i);
        
        if (l1==n+1)
        {
            ans++;
            continue;
        }
        /*if (l2!=n+1)
            d2++;*/
        if (l1+1<l2)
            d=l2-l1-1;
        if (!d)
            ans++;
        else 
            ans+=2*d+d2;
    }
    cout << ans;
}