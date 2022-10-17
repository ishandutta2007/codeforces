#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n,t1,t2,k;
struct P
{
    int x;
    double y;
}a[2010];
inline bool cmp(const P & a, const P & b)
{
    if(a.y != b.y)
    return a.y > b.y;
    return a.x < b.x;
}
int main()
{
    scanf("%d%d%d%d",&n,&t1,&t2,&k);
    for(int i = 1;i <= n; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i].y = max(x*t1*(1.0-(double)k/100)+y*t2,y*t1*(1.0-(double)k/100)+x*t2);
        a[i].x = i; 
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1; i <= n; i++)
        printf("%d %.2lf\n",a[i].x,a[i].y);
    return 0;
}