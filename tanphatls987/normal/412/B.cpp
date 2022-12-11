#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int compare(const void*x,const void*y)
{
    return *(long*)y-*(long*)x;
}
int main()
{
    long n,k,a[100],i;
    cin>>n>>k;
    for(i=0;i<n;i++) cin>>a[i];
    qsort(a,n,sizeof(long),compare);
    cout<<a[k-1];
}