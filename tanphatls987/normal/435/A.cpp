#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

const int maxi=1000;

int a[100],n,m,i,ans=1;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    int tmp=0;
    for(i=0;i<n;i++)
    {
        if (tmp+a[i]>m){tmp=a[i];ans++;}
        else tmp+=a[i];
    }
    printf("%d",ans);
}