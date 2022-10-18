#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
#define ld long double

using namespace std;

const int N=3e5+100;

int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l=0,r=m-1;
    while(l<r)
    {
        int t=(l+r)/2;
        bool ok=true;
        for(int i=1;i<=n;i++)
        {
            b[i]=m;
            #define upd(x,y) if((y)>=b[i-1]) b[i]=min(b[i],max((x),b[i-1]))
            if(a[i]+t<m)
            {
                upd(a[i],a[i]+t);
            }
            else
            {
                upd(a[i],m-1);
                upd(0ll,(a[i]+t)%m);
            }
            if(b[i]==m)
            {
                ok=false;
                break;
            }
        }
        if(ok)
            r=t;
        else
            l=t+1;
    }
    cout<<l;
}