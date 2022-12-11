#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;

long n,s,i,x,y;
struct city{long dis,peo;};
city a[1000];
int compare(const void* x,const void* y)
{
    return ((city*)x)->dis-((city*)y)->dis;
}
int main()
{
    cin>>n>>s;
    s=1000000-s;
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>a[i].peo;
        a[i].dis=x*x+y*y;
    }
    qsort(a,n,sizeof(city),compare);
    i=0;
    while (i<n)
    {
        s-=a[i].peo;
        if (s<=0) break;
        i++;
    }
    if ((i==n)&&(s)) cout<<-1;else
    printf("%.7lf",double (sqrt(a[i].dis)));
}