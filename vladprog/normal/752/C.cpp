#include<bits/stdc++.h>

//#define DEBUG
#ifdef DEBUG
    #define IFD(X) X
#else
    #define IFD(X)
#endif // DEBUG

#define mp make_pair
#define it iterator

using namespace std;

int main()
{
    int n;
    scanf("%d%*c",&n);
    bool l,r,u,d;
    l=r=u=d=false;
    int ans=1;
    for(int i=0;i<n;i++)
    {
        char c;
        scanf("%c",&c);
        switch(c)
        {
        case 'L':
            if(r)
            {
                ans++;
                l=r=u=d=false;
            }
            l=true;
            break;
        case 'R':
            if(l)
            {
                ans++;
                l=r=u=d=false;
            }
            r=true;
            break;
        case 'U':
            if(d)
            {
                ans++;
                l=r=u=d=false;
            }
            u=true;
            break;
        case 'D':
            if(u)
            {
                ans++;
                l=r=u=d=false;
            }
            d=true;
            break;
        }
    }
    printf("%d",ans);
}