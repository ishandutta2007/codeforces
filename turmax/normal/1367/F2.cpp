#include <bits/stdc++.h>

using namespace std;
#define int long long
map <pair <int,int>,int> z;
map <int,int> z1;
map <int,int> d;
map <int,vector <int> > u;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    z.clear();
    d.clear();
    z1.clear();
    u.clear();
    int n;
    cin>>n;
    int a[n];
    pair <int,int> b[n];
    int answ[n];
    int answ1[n];
    int answ2[n];
    for(int i=0;i<n;++i) answ[i]=1;
    for(int i=0;i<n;++i) answ1[i]=1;
    for(int i=0;i<n;++i) answ2[i]=1;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) b[i]={a[i],i};
    sort(b,b+n);
    for(int i=0;i<n;++i) z[b[i]]=i;
    vector <int> c;
    for(int i=0;i<n;++i)
    {
        if(u.count(a[i]))
        {
            u[a[i]].push_back(i);
        }
        else
        {
            vector <int> v;
            v.push_back(-1);
            v.push_back(i);
            u[a[i]]=v;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(d.count(a[i]))
        {
            answ[i]=d[a[i]]+1;
            d[a[i]]++;
        }
        else
        {
            c.push_back(a[i]);
            answ[i]=1;
            d[a[i]]=1;
        }
    }
    sort(c.begin(),c.end());
    for(int i=0;i<c.size();++i)
    {
        z1[c[i]]=i;
    }
    int ans=1;
    for(int i=0;i<n;++i)
    {
        int x=z[{a[i],i}];
        //cout<<i<<" i "<<answ[i]<<" answ[i] "<<endl;
        answ1[i]=answ[i];
        answ2[i]=answ[i];
        ans=max(ans,answ2[i]);
        if(x==0)
        {
            continue;
        }
        pair <int,int> h=b[x-1];
        int o=h.second;
        bool z5=false;
        //cout<<h.first<<" first "<<endl;
        //cout<<a[i]<<" a[i] "<<endl;
        if(o<i)
        {
        if(h.first==a[i])
        {
            answ2[i]=max(answ2[i],answ2[o]+1);
            answ1[i]=max(answ1[i],answ1[o]+1);
        }
        else
        {
            answ2[i]=max(answ2[i],answ1[o]+1);
            answ1[i]=max(answ1[i],answ1[o]+1);
        }
        }
        z5=(h.first != a[i]);
        x=z1[a[i]];
        ans=max(ans,answ2[i]);
        if(x==0)
        {
            continue;
        }
        int h1=c[x-1];
        //cout<<h1<<" h1 "<<endl;
        int o1=(lower_bound(u[h1].begin(),u[h1].end(),i)-u[h1].begin());
        o1--;
        int l=u[h1][o1];
        ans=max(ans,answ2[i]);
        //cout<<l<<" l "<<endl;
        if(l==(-1))
        {
            continue;
        }
        else
        {
            //cout<<i<<" i "<<endl;
            if(o1!=(u[h1].size()-1))
            {
            if(!z5)
            {
            answ2[i]=max(answ2[i],answ[l]+1);
            }
            else
            {
            answ2[i]=max(answ2[i],answ[l]+1);
            answ1[i]=max(answ1[i],answ[l]+1);
            }
            }
            else
            {
                if(!z5)
            {
            answ2[i]=max(answ2[i],answ1[l]+1);
            }
            else
            {
            answ2[i]=max(answ2[i],answ1[l]+1);
            answ1[i]=max(answ1[i],answ1[l]+1);
            }
            }
        }
        //cout<<i<<" i "<<endl;
        //cout<<answ1[i]<<" answ1[i] "<<endl;
        ans=max(ans,answ2[i]);
    }
    cout<<(n-ans)<<endl;
    }
    return 0;
}