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

    double x[6], y[6], al[3], lm, r, s, a[3], eps=1e-4, ans, pi=acos(-1.), tmp, tmp1, tmp2;
    int i, j, f;
    for(i=0; i<3; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
        x[i+3]=x[i]; y[i+3]=y[i];
    }
    for(i=0; i<3; i++)
        al[i]=2.*acos(((x[i+1]-x[i])*(x[i+2]-x[i])+(y[i+1]-y[i])*(y[i+2]-y[i]))/
        sqrt(((x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]))*((x[i+2]-x[i])*(x[i+2]-x[i])+(y[i+2]-y[i])*(y[i+2]-y[i]))));
    for(i=3; i<=100; i++)
    {
        for(j=f=0; j<3; j++)
        {
            tmp1=al[j]*i;
            tmp2=al[j]*i/(2.*pi);
            tmp=tmp1-(int)(tmp2)*2.*pi;
            if (fabs(2.*pi-tmp)<eps) tmp-=2.*pi;
            if (fabs(2.*pi+tmp)<eps) tmp+=2.*pi;
            if (tmp>eps) {f=1; break;}
        }
        if (!f)
        {
            for(j=0; j<3; j++)
                a[j]=sqrt((x[j+1]-x[j])*(x[j+1]-x[j])+(y[j+1]-y[j])*(y[j+1]-y[j]));
            s=fabs((x[1]-x[0])*(y[2]-y[0])-(x[2]-x[0])*(y[1]-y[0]));
            r=a[0]*a[1]*a[2]/(2.*s);
            lm=2.*pi/i;
            ans=i*r*r*sin(lm)/2.;
            printf("%.10lf\n", ans);
            return 0;
        }
    }
}