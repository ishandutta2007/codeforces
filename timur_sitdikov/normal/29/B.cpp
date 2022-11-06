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
using namespace std;

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int g, l, v, d, r, i, dd;
    double t, rem, eps=1e-8, ans;
    cin >> l >> d >> v >> g >> r;
    dd=0;
    t=0.;
    for(i=0; ; i++)
    {
        dd+=v*g;
        if (dd>d) 
        {
            ans=(l+0.)/v;
            printf("%.12lf", ans);
            return 0;           
        }
        t+=g;
        dd+=v*r;
        if (dd>d)
        {
            t+=r;
            ans=t+(l-d+0.)/v;
            printf("%.12lf", ans);
            return 0;
        }
        t+=r;
    }
    /*t=(d+0.)/v;
    rem=t-((int)(t/(g+r)))*(g+r);
    if (rem+eps<r || rem+eps>g+r)
        ans=(l+0.)/v;
    else 
        ans=(l-d+0.)/v+((int)(t/(g+r))+1)*(g+r);*/
    /*if (d%(v*(g+r))<r)
        ans=(l+0.)/v;
    else 
    {
        t=(d+0.)/v;
        ans=(l+0.)/v+(v*(g+r)-(d%(v*(g+r))+0.))/v;
    }*/ 
}