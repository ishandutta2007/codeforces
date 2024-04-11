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

int num(int l, int r, int f)
{
    if (l>r)
        return 0;
    int ans=(r-l+1)>>1;
    if ((!(l&1)) && (!(r&1)))
        ans++;
    if (f)
        ans=r-l+1-ans;
    return ans;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, x, i, cur, f;
    cin >> n >> m >> x;
    f=1;
    for(i=0; i<x; i++, n-=2, m-=2)
    {
        if (n<=0 || m<=0)
        {
            printf("0");
            return 0;
        }
        cur=num(1, n, f)+num(2, m, f);
        if (n>1)
            cur+=num(2, m, f^1^(n&1));
        if (m>1)
            cur+=num(2, n-1, f^1^(m&1));
    }
    cout << cur;
}