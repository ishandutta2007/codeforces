#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

int n,k,x,num,a[101],ans,l,r,i,le,re;
int main()
{
    scanf("%d%d%d",&n,&k,&x);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    ans=0;
    for(i=1;i<n;i++)
    {
        l=i-1;r=i;
        if ((a[l]==a[r])&&(a[r]==x))
        {
            l--;r++;
            while ((l>=0)&&(r<n)&&(a[l]==a[r]))
            {
                re=1;le=1;
                if ((l>0)&&(a[l]==a[l-1])) le++;
                if ((r<n-1)&&(a[r]==a[r+1])) re++;
                if (le+re<3) break;else {l-=le;r+=re;}
            }
        }
        if (ans<r-l-1) ans=r-l-1;
    }
    printf("%d",ans);
}