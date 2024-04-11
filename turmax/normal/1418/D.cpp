#include <bits/stdc++.h>

using namespace std;
#define int long long
map <int,int> o1;
set <int> d1;
set <int> d;
int ma()
{
    if(d.empty()) return 0;
    set <int> ::iterator it=d.end();
    it--;
    return *it;
}
int mi()
{
    if(d.empty()) return 0;
    return *d.begin();
}
void pl1(int x)
{
    if(d1.count(x))
    {
        o1[x]++;
        return;
    }
    else
    {
        d1.insert(x);
        o1[x]=1;
    }
}
void mi1(int x)
{
    if(o1[x]>1)
    {
        o1[x]--;
        return;
    }
    else
    {
        o1[x]--;
        d1.erase(x);
    }
}
int ma1()
{
    if(d1.empty()) return 0;
    set <int>::iterator it=d1.end();
    it--;
    return (*it);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;++i) {cin>>a[i];d.insert(a[i]);}
    sort(a,a+n);
    for(int i=0;i<(n-1);++i) pl1(a[i+1]-a[i]);
    cout<<ma()-mi()-ma1()<<endl;
    while(q--)
    {
        int typ,x;
        cin>>typ>>x;
        if(typ==1)
        {
            if(d.empty())
            {
                d.insert(x);
            }
            else {
            int ma2=ma();int mi2=mi();
            if(x>=ma2)
            {
                d.insert(x);
                pl1(x-ma2);
            }
            else if(x<=mi2)
            {
                d.insert(x);
                pl1(mi2-x);
            }
            else
            {
                set <int>::iterator it=d.lower_bound(x);
                int o1=*it;
                it--;
                int o2=*it;
                //cout<<o1<<" "<<o2<<" o1 o2 "<<endl;
                mi1(o1-o2);
                pl1(x-o2);
                pl1(o1-x);
                d.insert(x);
            }
            }
        }
        else
        {
            if(d.size()<=1)
            {
                d.erase(x);
            }
            else {
            int ma2=ma();int mi2=mi();
            if(x==ma2)
            {
                d.erase(x);
                mi1(x-ma());
            }
            else if(x==mi2)
            {
                d.erase(x);
                mi1(mi()-x);
            }
            else
            {
                d.erase(x);
                set <int>::iterator it=d.lower_bound(x);
                int o1=*it;
                it--;
                int o2=*it;
                pl1(o1-o2);
                mi1(x-o2);
                mi1(o1-x);
            }
            }
        }
        cout<<ma()-mi()-ma1()<<endl;
    }
    return 0;
}