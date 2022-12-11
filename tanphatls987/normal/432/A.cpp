#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;
int n,k,a[2000],ans,i;
int main()
{
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    ans=0;
    for(i=0;i<n;i++) if (5-a[i]>=k) ans++;
    ans/=3;
    printf("%d",ans);
}