#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    set <int> u;
    set <int> og;
    og.insert(0);
    u.insert(1e18);
    int ans=0;
    int curr=1e18;
    int sum=0;
    while(n--)
    {
        int typ,d;
        cin>>typ>>d;
        if(typ==0)
        {
            if(d>0)
            {
                sum+=d;
                u.insert(d);
                og.insert(-d);
                if(d>curr)
                {
                    ans+=d;
                    ans-=curr;
                    curr=(*u.upper_bound(curr));
                }
            }
            else
            {
                sum+=d;
                d=abs(d);
                if(d>=curr)
                {
                    ans-=d;
                    set <int>::iterator it=u.lower_bound(curr);
                    it--;
                    curr=(*it);
                    ans+=curr;
                }
                og.erase(-d);
                u.erase(d);
            }
        }
        else
        {
            if(d>0)
            {
                sum+=d;
                if(d<curr)
                {
                    u.insert(d);
                    set <int>::iterator it=u.lower_bound(curr);
                    it--;
                    curr=(*it);
                    ans+=curr;
                }
                else
                {
                    u.insert(d);
                    ans+=d;
                }
            }
            else
            {
                sum+=d;
                d=abs(d);
                if(d>curr)
                {
                    ans-=d;
                    u.erase(d);
                }
                else
                {
                    ans-=curr;
                    curr=(*u.upper_bound(curr));
                    u.erase(d);
                }
            }
        }
        //cout<<ans<<" ans "<<endl;
        //cout<<sum<<" sum "<<endl;
        //cout<<curr<<" curr "<<endl;
        if(curr!=1e18)
        cout<<ans+sum-max(0LL,curr+(*og.begin()))<<endl;
        else
        cout<<ans+sum<<endl;
    }
    return 0;
}