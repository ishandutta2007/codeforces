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

long long n, m;

long long f(long long a, long long b, long long c, long long d)
{
    long long dx, dy, ans;
    dx=min(n-2*a, n-2*c);
    dy=min(m-2*b, m-2*d);
    if (dx<0)
        dx=0;
    if (dy<0)
        dy=0;
    ans=dx*dy;
    return ans;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long ans=0, i, j, k, tmp, s, dif, q;
    cin >> n >> m >> s;
    for(i=0; i<=n/2; i++)
        for(j=0; j<=m/2; j++)
        {
            if ((2*i+1)*(2*j+1)==s)
            {
                tmp=f(i, j, i, j);
                ans+=2*tmp*(i+1)*(j+1)-tmp;
            }
            else if (s>(2*i+1)*(2*j+1))
            {
                dif=s-(2*i+1)*(2*j+1);
                if (dif&1)
                    continue;
                dif/=2;
                for(k=1; k*k<=dif; k++)
                    if (!(dif%k))
                    {
                        q=dif/k;
                        if ((q&1) && q<2*j+1)
                            ans+=2*f(i, j, i+k, (q+1)/2);
                        if ((k&1) && k<2*j+1 && q!=k)
                            ans+=2*f(i, j, i+q, (k+1)/2);
                    }
            }       
        }
    cout << ans;
}