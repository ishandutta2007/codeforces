#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

#define maxn 100010

int h, m, nq;
long long ll, rr, sol;
pair<long long, long long> v[maxn];

int main()
{
    cin>>h>>m;
    ll=1LL<<(h-1);
    rr=(1LL<<h)-1;

    while(m--)
    {
        long long t, x, y;
        int ans;
        cin>>t>>x>>y>>ans;

        x = (x<<(h-t));
        y = ((y+1)<<(h-t))-1;

        if(ans==1)
        {
            ll=max(ll, x);
            rr=min(rr, y);
        }
        else
            v[++nq]=make_pair(x, y);
    }

    if(ll>rr)
    {
        cout<<"Game cheated!\n";
        return 0;
    }

    sort(v+1, v+nq+1);

    int gs=0;

    for(int i=1; i<=nq; ++i)
    {
        if(v[i].first>rr)
            continue;

        if(v[i].first>ll+1 || (v[i].first>ll && gs==1))
        {
            cout<<"Data not sufficient!\n";
            return 0;
        }
        if(v[i].first==ll+1)
        {
            gs=1;
            sol=ll;
        }
        ll=max(ll, v[i].second+1);
    }

    if(ll>rr)
    {
        if(gs==1)
            cout<<sol<<"\n";
        else
            cout<<"Game cheated!\n";
    }
    else
    {
        if(ll==rr && gs==0)
            cout<<ll<<"\n";
        else
            cout<<"Data not sufficient!\n";
    }

    return 0;
}