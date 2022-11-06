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

double hh[5400];
double h[5000], r[5000], R[5000], al[5000];

int checka(double r1, double R1, double h1, double r2, double R2, double h2)
{
    if (r2<r1)
        return 0;
    if (h1<=h2)
    {
        if (R1<=h1*(R2-r2)/h2+r2)
            return 1;
        else return 0;
    }
    else
    {
        if (R2>=h2*(R1-r1)/h1+r1)
            return 1;
        else return 0;
    }
}

int checkb(double r1, double R1, double h1, double r2, double R2, double h2)
{
    if (r1>=R2)
        return 1;
    return 0;
}
int checkc(double r1, double R1, double h1, double r2, double R2, double h2)
{

    if (r1>=R2 || r1<=r2)
        return 0;
    double h22=(r1-r2)/(R2-r2)*h2;
    return checka(r1, R1, h1, r1, R2, h2-h22);
}

int checkd(double r1, double R1, double h1, double r2, double R2, double h2)
{
    if (R1>R2 || R1<=r2)
        return 0;
    return 1;
}
int checke(double r1, double R1, double h1, double r2, double R2, double h2)
{
    return 1;
}

int main()
{   
    //#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    //#endif
    int n, i, j;
    double ans, cur, mx;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> h[i] >> r[i] >> R[i];
        al[i]=atan((R[i]-r[i])/h[i]);
    }
    hh[0]=0.;
    for(i=1; i<=n; i++)
    {
        mx=0.;
        for(j=i-1; j>=0; j--)
        {
            if (checka(r[i], R[i], h[i], r[j], R[j], h[j]))
            {
                cur=hh[j];
                if (mx<cur)
                    mx=cur;
            }
            else if (checkb(r[i], R[i], h[i], r[j], R[j], h[j]))
            {
                cur=hh[j]+h[j];
                if (mx<cur)
                    mx=cur;
            }
            else if (checkc(r[i], R[i], h[i], r[j], R[j], h[j]))
            {
                cur=hh[j]+(r[i]-r[j])/(R[j]-r[j])*h[j];
                if (mx<cur)
                    mx=cur;
            }
            else if (checkd(r[i], R[i], h[i], r[j], R[j], h[j]))
            {
                cur=hh[j]+(R[i]-r[j])/(R[j]-r[j])*h[j]-h[i];
                if (mx<cur)
                    mx=cur;
            }
            else
            {
                cur=hh[j]-(R[j]-r[i])/(R[i]-r[i])*h[i]+h[j];
                if (mx<cur)
                    mx=cur;
            }
        }
        hh[i]=mx;
    }
    mx=0.;
    for(i=0; i<=n; i++)
        if (hh[i]+h[i]>mx)
            mx=hh[i]+h[i];
    printf("%.12lf", mx);
}