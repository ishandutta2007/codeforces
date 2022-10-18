#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin>>m;
    int t;
    int minn=0x3fffffff,maxn=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&t);
        if(minn>t)
        {
            minn=t;
        }
        if(maxn<t)
        {
            maxn=t;
        }
    }
    printf("%d\n",maxn-minn+1-m);
    return 0;
}
/////////afclroiusdusoisptuy