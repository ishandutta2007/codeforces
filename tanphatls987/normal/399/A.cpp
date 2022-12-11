#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,p,k,l,r,i;
    cin>>n>>p>>k;
    l=p-k;if (l<=0) l=1;
    r=p+k;if (r>n) r=n;
    if (l>1) printf("<< ");
    for(i=l;i<=r;i++) if (i==p) printf ("(%d) ",i); else printf("%d ",i);
    if (r<n) printf(">> ");
}