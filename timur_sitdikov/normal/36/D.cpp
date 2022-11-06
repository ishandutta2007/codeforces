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

bool cmp(int a, int b)
{return a<b;}

int main()
{   
    //#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    //#endif
    long long t, n, m, k, i;
    char ans;
    cin >> t >> k;
    for(i=0; i<t; i++)
    {
        cin >> n >> m;
        if (n>m)
            swap(n, m);
        if (k==1)
        {
            if ((n&1) && (m&1))
                printf("-\n");
            else printf("+\n");
            continue;
        }
        /*if (k&1)
        {
            if (n%(2*k+2)==0 || n%(2*k+2)==k+1)
                ans='+';
            else
            {
                if (n%(2*k+1)<=k)
                {
                    if ((n+m)&1)
                        ans='+';
                    else ans='-';
                }
                else
                {
                    if (!((n+m)&1))
                        ans='+';
                    else ans='-';
                }
            }
        }
        else*/
        {
            if (n%(2*k+2)==0 || n%(2*k+2)==k+1)
                ans='+';
            else
            {
                if (n%(2*k+2)<=k)
                {
                    if ((n+m)&1)
                        ans='+';
                    else ans='-';
                }
                else
                {
                    if (!((n+m)&1))
                        ans='+';
                    else ans='-';
                }
            }
        }
        putchar(ans);
        putchar('\n');
    }
}