#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

const int maxi=50000;

int64_t n,i,j,s[2][maxi],a[maxi],sum=0,cap,top=0,bot=0,ans=0;
int main()
{
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        sum+=a[i];
    }
    cap=sum/n;
    for(i=0;i<n;i++) if (a[i]>cap) s[0][++top]=i;else s[1][++bot]=i;
    while (top)
    {
        if (a[s[0][top]]-cap>cap-a[s[1][bot]])
        {
            a[s[0][top]]-=cap-a[s[1][bot]];
            ans+=(cap-a[s[1][bot]])*abs(s[0][top]-s[1][bot]);
            bot--;
        }
        else
        {
            ans+=(a[s[0][top]]-cap)*abs(s[0][top]-s[1][bot]);
            a[s[1][bot]]+=a[s[0][top]]-cap;
            top--;
        }
    }
    printf("%I64d",ans);
}