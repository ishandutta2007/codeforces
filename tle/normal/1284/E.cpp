//https://blog.csdn.net/ACdreamers/article/details/11833397
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
 
using namespace std;
typedef long long LL;
typedef long double ld;
const int N = 555555;
const ld PI = acosl(-1.0);
 
struct Point
{
    int x,y;
};
 
Point p[N];
ld A[N];
int n;
 
ld angle(ld x,ld y)
{
    ld t = y - x;
    if(t < 0) t += 2*PI;
    return t;
}
 
LL work()
{
    LL t1 = 0;
    for(int k=0; k<n; k++)
    {
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(k != i)
                A[cnt++] = atan2l((ld)(p[i].y-p[k].y),(ld)(p[i].x-p[k].x));
        }
        sort(A,A+n-1);
        LL t2 = (LL)(n-1)*(n-2)*(n-3)/6;
        for(int j=0,i=0; i<n-1; i++)
        {
            while(j<i+n-1)
            {
                if(angle(A[i],A[j%(n-1)])>PI) break;
                j++;
            }
            t2 -= (LL)(j-i-1)*(j-i-2)/2;
        }
        t1 += t2;
    }
    return t1;
}
 
int main()
{
    int T=1;
    while(T--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>p[i].x>>p[i].y;
        cout<<work()*(n-4)/2<<endl;
    }
    return 0;
}