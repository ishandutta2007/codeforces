#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *c1, const void *c2)
{return 0;}

int main()
{   

    double min=1000000000., cur, eps=1e-7;
    long long i, n, mini=-1, vb, vs, m[105], x, y;
    scanf("%lld %lld %lld", &n, &vb, &vs);
    for(i=0; i<n; i++) scanf("%lld", &m[i]);
    scanf("%lld %lld", &x, &y);
    for(i=1; i<n; i++)
    {
        cur=(double)m[i]/(double)vb+sqrt((double)(y*y+(x-m[i])*(x-m[i]))+1e-18)/(double)vs;
        if (cur+eps<min) {min=cur; mini=i+1;}
        else if(fabs(cur-min)<eps) 
        {if ((m[i]-x)*(m[i]-x)<(m[mini-1]-x)*(m[mini-1]-x)) mini=i+1;}
    }
    printf("%lld", mini);
}