#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define tick printf("tick\n")
using namespace std;

const int maxd=100000;
double a[101],ans,p,s;
int n,i,j;
int main()
{
    //freopen("443d.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ans=0;p=1;s=0;
    if (a[n-1]>0.5) ans=a[n-1];
    else for(i=n-1;i>=0;i--)
        {
            p*=(1-a[i]);
            s+=a[i]/(1-a[i]);
            if (ans<p*s) ans=p*s;else break;
        }
    //for(i=0;i<n;i++) printf("%.15f\n",a[i]);
    printf("%.12f",ans);
}