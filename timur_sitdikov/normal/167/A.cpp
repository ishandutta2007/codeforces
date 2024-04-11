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

double ans[100005];
long long t[100005], v[100005];

int main()
{   
    long long n, i, d, a;
    double d1;
    scanf("%I64d %I64d %I64d", &n, &a, &d);
    for(i=0; i<n; i++)
        scanf("%I64d %I64d", &t[i], &v[i]);
    for(i=0; i<n; i++)
    {
        if (v[i]*v[i]>=2*a*d)
        {ans[i]=t[i]+sqrt(2.*d/a);}
        else
        {
            d1=v[i]*v[i]+0.;
            d1/=(2.*a);
            ans[i]=t[i]+(d-d1)/v[i]+v[i]/(double)a;
        }
    }
    for(i=1; i<n; i++)
        if (ans[i]<ans[i-1]) ans[i]=ans[i-1];
    for(i=0; i<n; i++)
        printf("%.12lf\n", ans[i]);

}