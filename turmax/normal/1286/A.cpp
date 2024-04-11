#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <pair<int,int> > a;
    vector <int> b(n);
    int s1=((n+1)/2);
    int s2=(n/2);
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
        if(b[i]!=0)
        {
            if(b[i]%2==1)
            {
                s1--;
            }
            else
            {
                s2--;
            }
            a.push_back(make_pair(i,b[i]));
        }
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    int ans=0;
    int l;
    vector <int> d1,d2;
    vector <int> u1,u2;
    if(a.size()!=0)
    {
    if((a[0].second)%2==1)
    {
        u1.push_back(a[0].first);
    }
    else
    {
        u2.push_back(a[0].first);
    }
    if((a[a.size()-1].second)%2==1)
    {
        u1.push_back(n-a[a.size()-1].first-1);
    }
    else
    {
        u2.push_back(n-a[a.size()-1].first-1);
    }
    }
    else
    {
        cout<<1;
        return 0;
    }
    for(int i=0;i<a.size()-1;++i)
    {
        l=a[i+1].first-a[i].first-1;
        if((a[i].second%2)==(a[i+1].second%2))
        {
            if((a[i].second%2)==1)
            {
                d1.push_back(l);
            }
            else
            {
                d2.push_back(l);
            }
        }
        else
        {
            ++ans;
        }
    }
    sort(d1.begin(),d1.end());
    sort(d2.begin(),d2.end());
    for(int i=0;i<d1.size();++i)
    {
        if(s1<d1[i])
        {
            ans+=2;
        }
        else
        {
            s1-=d1[i];
        }
    }
    for(int i=0;i<d2.size();++i)
    {
        if(s2<d2[i])
        {
            ans+=2;
        }
        else
        {
            s2-=d2[i];
        }
    }
    sort(u1.begin(),u1.end());
    sort(u2.begin(),u2.end());
    for(int i=0;i<u1.size();++i)
    {
        if(s1<u1[i])
        {
            ans++;
        }
        else
        {
            s1-=u1[i];
        }
    }
    for(int i=0;i<u2.size();++i)
    {
        if(s2<u2[i])
        {
            ans++;
        }
        else
        {
            s2-=u2[i];
        }
    }
    cout<<ans;
    return 0;
}