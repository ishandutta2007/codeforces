#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;
int n,i,a[100],h[100],p[100],m;
int compare(const void*x,const void* y)
{
    return a[(*(int *)x)]-a[(*(int*) y)];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++) h[i]=i;
    qsort(h,n,sizeof(int),compare);
    for(i=0;i<n;i++) p[h[i]]=i%2;
    for(i=0;i<n;i++) printf("%d ",p[i]);
}