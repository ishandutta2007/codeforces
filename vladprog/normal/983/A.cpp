#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int ll

typedef long long ll;

int gcd(int x,int y)
{
    //cout<<x<<" "<<y<<"\n";
    if(y==0)
        return x;
    return gcd(y,x%y);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    bool pans,ok=true;
    for(int t=0;t<n;t++)
    {
        if(t>=7929&&ok)
        {
            if(pans)
                cout<<"Finite\n";
            else
                cout<<"Infinite\n";
            continue;
        }
        int p,q,b;
        cin>>p>>q>>b;
        int d=gcd(p,q);
        p/=d;
        q/=d;
        int bb=b;
        if(bb!=1)
            while(double(bb)*b<=1e18)
                bb*=b;
        while(true)
        {
            d=gcd(q,bb);
            if(d==1)
                break;
            while(q%d==0)
                q/=d;
        }
        if(q==1)
            cout<<"Finite\n";
        else
            cout<<"Infinite\n";
        if(t<7929&&ok)
        {
            if(t==0)
                pans=q==1;
            if(pans!=(q==1))
                ok=false;
        }
    }
}