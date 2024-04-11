#include <bits/stdc++.h>

using namespace std;
#define int long long
long long p=998244353;
bool comp(pair <int,pair<int,int> > a1,pair<int,pair<int,int> > a2)
{
    return make_pair(a1.first,a1.second.second)<make_pair(a2.first,a2.second.second);
}
int po(int x)
{
    if(x==0)
    {
        return 1;
    }
    if(x==1)
    {
        return 2;
    }
    if(x%2==0)
    {
        int u=po(x/2);
        return (u*u)%p;
    }
    int u=po(x-1);
    return (2*u)%p;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cout<<p<<endl;
    int n;
    cin>>n;
    vector <pair<int,int> > a(n);
    vector <pair<int,int> > b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        cin>>b[i].first>>b[i].second;
    }
    vector <pair<int,pair<int,int> > > a1;
    vector <pair<int,pair<int,int> > > b1;
    for(int i=0;i<n;++i)
    {
        //cout<<i<<endl;
        a1.push_back(make_pair(a[i].first,make_pair(i,0)));
        a1.push_back(make_pair(a[i].second,make_pair(i,1)));
        b1.push_back(make_pair(b[i].first,make_pair(i,0)));
        b1.push_back(make_pair(b[i].second,make_pair(i,1)));
    }
    sort(a1.begin(),a1.end(),comp);
    sort(b1.begin(),b1.end(),comp);
    vector <int> h1(n);
    vector <int> h2(n);
    int has1=0;
    int d1=0;
    int has2=0;
    int d2=0;
    pair <int,pair<int,int> > u1;
    pair <int,pair<int,int> > u2;
    for(int i=0;i<2*n;++i)
    {
        u1=a1[i];
        //cout<<u1.first<<" "<<u1.second.first<<" "<<u1.second.second<<" a "<<endl;
        if(u1.second.second==0)
        {
            has1+=po(u1.second.first);
            h1[u1.second.first]=(-d1);
            has1%=p;
        }
        else
        {
            has1-=po(u1.second.first);
            h1[u1.second.first]+=(has1+d1);
            d1+=po(u1.second.first);
            d1%=p;
        }
        u2=b1[i];
        //cout<<u2.first<<" "<<u2.second.first<<" "<<u2.second.second<<endl;
        if(u2.second.second==0)
        {
            has2+=po(u2.second.first);
            h2[u2.second.first]=(-d2);
            has2%=p;
        }
        else
        {
            has2-=po(u2.second.first);
            h2[u2.second.first]+=(has2+d2);
            has2%=p;
            d2+=po(u2.second.first);
            d2%=p;
        }
        //cout<<has1<<" "<<has2<<endl;
    }
    for(int i=0;i<n;++i)
    {
        h1[i]%=p;
        h1[i]+=p;
        h1[i]%=p;
        h2[i]%=p;
        h2[i]+=p;
        //cout<<(h2[i])<<endl;
        h2[i]%=p;
        //cout<<h2[i]<<endl;
    }
    /*for(int i=0;i<n;++i)
    {
        cout<<h1[i]<<" "<<h2[i]<<endl;
    }*/
    //cout<<p<<endl;
    for(int i=0;i<n;++i)
    {
        if(h1[i]!=h2[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}