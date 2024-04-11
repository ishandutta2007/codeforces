#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k,l,r,t,x,y;
    cin>>k>>l>>r>>t>>x>>y;
    if(x==y)
    {
        if((k+x)<=r || (k-x)>=l)
        {
            cout<<"Yes";
            return 0;
        }
        else
        {
            cout<<"No";
            return 0;
        }
    }
    if((r-l)<x)
    {
        cout<<"No";
        return 0;
    }
    if(x>y)
    {
        int o=(k-(r-y));
        o--;
        int mv=0;
        if(o>=0)
        {
            mv=(o/x+1);
            k-=(mv*x);
            if(k<l)
            {
                if(mv<=t)
                {
                    cout<<"No";
                    return 0;
                }
                else
                {
                    cout<<"Yes";
                    return 0;
                }
            }
        }
        int mv1=(k-l)/(x-y);
        if((mv+mv1)>=t)
        {
            cout<<"Yes";
            return 0;
        }
        else
        {
            cout<<"No";
            return 0;
        }
    }
    else
    {
        if((r-l)>=(x+y-1))
        {
            cout<<"Yes";
            return 0;
        }
        if(k>(r-y) && k<(l+x))
        {
            cout<<"No";
            return 0;
        }
        set <int> was;
        was.insert(k);
        int mv=0;
        int z=(k-l);
        mv+=(z/x);
        k-=((z/x)*x);
        if(mv>=t)
        {
            cout<<"Yes";
            return 0;
        }
        while(true)
        {
            k+=y;
            if(k>r)
            {
                cout<<"No";
                return 0;
            }
            k-=x;
            mv++;
            if(mv>=t)
            {
                cout<<"Yes";
                return 0;
            }
            int z=(k-l);
            mv+=(z/x);
            k-=((z/x)*x);
            if(mv>=t)
            {
                cout<<"Yes";
                return 0;
            }
            if(was.count(k))
            {
                cout<<"Yes";
                return 0;
            }
            was.insert(k);
        }
    }
    return 0;
}