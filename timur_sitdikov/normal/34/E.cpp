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

const int maxn=15;
double eps=1e-9;

struct ball
{
    double m, x, v;
    int ind;
};

bool cmp(ball & b1, ball & b2)
{
    return b1.x<b2.x;
}

bool cmp2(ball & b1, ball & b2)
{
    return b1.ind<b2.ind;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ball b[maxn];
    double t[maxn], tt, tmin, mini, last, dt, xx, v1, v2;
    int n, i, j;
    cin >> n >> tt;
    for(i=0; i<n; i++)
    {
        cin >> b[i].x >> b[i].v >> b[i].m;
        b[i].ind=i;
    }
    sort(b, b+n, cmp);
    tmin=0.;
    do  
    {
        last=tmin;
        for(i=0; i<n-1; i++)
            if (b[i+1].v>=b[i].v)
            {
                t[i]=tt;
                continue;
            }
            else
            {
                t[i]=(b[i+1].x-b[i].x)/(b[i].v-b[i+1].v)+last;
            }
        tmin=tt;
        mini=-2;
        for(i=0; i<n-1; i++)
            if (t[i]+eps<tmin)
            {
                tmin=t[i];
                mini=i;
            }
        dt=tmin-last;
        i=mini;
        for(j=0; j<n; j++)
        {
            if (j==i || j==i+1)
                continue;
            b[j].x=b[j].x+b[j].v*dt;
        }
        if (mini!=-2)
        {
            xx=b[i].x+b[i].v*dt;
            v1=((b[i].m-b[i+1].m)*b[i].v+2.*b[i+1].m*b[i+1].v)/(b[i].m+b[i+1].m);
            v2=((b[i+1].m-b[i].m)*b[i+1].v+2.*b[i].m*b[i].v)/(b[i].m+b[i+1].m);
            b[i].v=v1;
            b[i+1].v=v2;
            b[i].x=b[i+1].x=xx;
        }
    }
    while(tmin+eps<tt);
    sort(b, b+n, cmp2); 
    for(i=0; i<n; i++)
        printf("%.12lf\n", b[i].x);
}