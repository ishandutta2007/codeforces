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

double pr[200005];
long long a[200005];

int main()
{   

    long long n, i, j, v1, v2, l, tmp;
    double delta, prv, eps=1e-7;
    scanf("%I64d %I64d %I64d %I64d", &n, &l, &v1, &v2);
    for(i=0; i<n; i++)
    {
        scanf("%I64d", &a[i]);
        a[i+n]=a[i]+2*l;
    }
    a[2*n]=a[0]+4*l;
    for(i=1; i<=2*n; i++) a[i]-=(a[0]-0);
    a[0]=0;
    prv=0.;
    for(j=0; v2*l-a[j]*(v1+v2)>=0; j++);
    delta=(v2*l+0.)/(v1+v2+0.);
    for(i=0; prv+eps<2.*l && j<=2*n; )
    {
        if (j<i) j=i;
        tmp=v2*l-(a[j]-a[i])*(v1+v2);
        if (tmp<0)
        {
            pr[j-i]+=a[i]-prv;
            prv=a[i];
            i++;
        }
        else if (tmp>0)
        {
            pr[j-i]+=a[j]-prv-delta;
            prv=a[j]-delta;
            j++;
        }
        else
        {
            pr[j-i]+=a[i]-prv;
            prv=a[i];
            i++; j++;
        }
    }
    for(i=0; i<=n; i++)
        printf("%.12lf\n", pr[i]/(2.*l));
}