#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N];
vector<int> v[N];
int t[4*N];

void upd(int v,int tl,int tr,int pos,int val)
{
    if(tl==tr)
        t[v]=val;
    else
    {
        int tm=(tl+tr)/2;
        if(pos<=tm)
            upd(v<<1,tl,tm,pos,val);
        else
            upd((v<<1)|1,tm+1,tr,pos,val);
        t[v]=min(t[v<<1],t[(v<<1)|1]);
    }
}

int get(int v,int tl,int tr,int l)
{
    if(tl==tr)
        return t[v]>=l?tl+1:tl;
    int tm=(tl+tr)/2;
    if(t[v<<1]>=l)
        return get((v<<1)|1,tm+1,tr,l);
    else
        return get(v<<1,tl,tm,l);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        v[i].push_back(0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        upd(1,1,n,a[i],i);
        s.insert(get(1,1,n,1));
        if(i<n)
        {
            int val=a[i+1];
            int pos=*prev(lower_bound(v[val].begin(),v[val].end(),i+1));
            if(pos!=i)
                s.insert(get(1,1,n,pos+1));
        }
        else
        {
            for(int val=1;val<=n;val++)
            {
                int pos=v[val].back();
                if(pos!=i)
                    s.insert(get(1,1,n,pos+1));
            }
        }
    }
    for(int i=1;;i++)
        if(!s.count(i))
            cout<<i,exit(0);
}