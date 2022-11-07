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

int v[1005], n;
double cur, eps=1e-7;

int check(double r)
{
    int i, f, num;
    cur=r;
    f=0;
    for(i=1; i<=n; i++)
    {
        num=(int)(cur/10+eps);
        if (num<v[i]-v[i-1])
        {
            f=-1;
            break;
        }
        if (num>v[i]-v[i-1])
        {
            f=1;
            break;
        }
        cur=cur-num*10.+r;
    }
    return f;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, a, num, f, v1, v2;
    double p, q, r, p1, q1;
    cin >> n;
    /*if (n==1)
    {
        printf("not unique");
        return 0;
    }*/
    for(i=1; i<=n; i++)
        cin >> v[i];
    /*for(p=10., q=1000000.; p+eps<q; )
    {
        r=(p+q)/2.;
        f=check(r);
        if (f==-1)
            p=r;
        else q=r;
    }
    p1=q;
    for(p=v[1]*10.-eps, q=p+1.; p+eps<q; )
    {
        r=(p+q)/2.;
        f=check(r);
        if (f!=1)
            p=r;
        else q=r;
    }
    q1=p;*/
    p1=v[1];
    for(i=2; i<=n; i++)
    {
        p1=max(p1, v[i]/(i+0.));
    }
    q1=v[1]+1;
    for(i=2; i<=n; i++)
    {
        q1=min(q1, (v[i]+1)/(i+0.));
    }
    /*check(p1*10.);
    num=(int)(cur/10+eps);*/
    v1=(int)(p1*(n+1)+eps);
    v2=(int)((q1-eps)*(n+1)+eps);
    if (v1<v2)
        printf("not unique");
    else 
        printf("unique\n%d", v1);

}