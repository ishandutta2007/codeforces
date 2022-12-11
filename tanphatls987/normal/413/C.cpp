#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace std;
long int a[100],h[100]={0},b[50],tmp,selmin,selmax;
int64_t sum;
int m,n,i,j,l,r;
int compare(const void*x,const void*y)
{
    return a[*(long int*)x]-a[*(long int*)y];
}
int main()
{

    cin>>n>>m;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<m;i++)
    {
        cin>>tmp;b[i]=tmp-1;
        h[tmp-1]=1;
    }
    sum=0;
    for(i=0;i<n;i++) if (h[i]==0) sum+=a[i];
    qsort(b,m,sizeof(long int),compare);
    l=0;r=m-1;
    while (l<=r) {if (sum>=a[b[r]]) {sum*=2;l++;} else {sum+=a[b[r]];r--;}}
    cout<<sum;
}