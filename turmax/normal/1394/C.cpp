#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
pair <bool,pair<int,int> > check(vector <pair<int,int> > a,int k)
{
    int ma1=1e18;
    int mi1=0;
    int ma2=1e18;
    int mi2=0;
    int mar=1e18;
    int mir=(-1e18);
    for(int i=0;i<a.size();++i)
    {
        ma1=min(ma1,a[i].first+k);
        mi1=max(mi1,a[i].first-k);
        ma2=min(ma2,a[i].second+k);
        mi2=max(mi2,a[i].second-k);
        mar=min(mar,a[i].first-a[i].second+k);
        mir=max(mir,a[i].first-a[i].second-k);
    }
    if(ma1<mi1 || ma2<mi2 || mar<mir)
    {
        return {false,{-1,-1}};
    }
    for(int i=mi1;i<=ma1;++i)
    {
        int x=i;
        int y=mi2;
        if((x-y)>=mir && (x-y)<=mar && (x+y)!=0)
        {
            return {true,{x,y}};
        }
    }
    for(int i=mi1;i<=ma1;++i)
    {
        int x=i;
        int y=ma2;
        if((x-y)>=mir && (x-y)<=mar && (x+y)!=0)
        {
            return {true,{x,y}};
        }
    }
    for(int i=mi2;i<=ma2;++i)
    {
        int x=mi1;
        int y=i;
        if((x-y)>=mir && (x-y)<=mar && (x+y)!=0)
        {
            return {true,{x,y}};
        }
    }
    for(int i=mi2;i<=ma2;++i)
    {
        int x=ma1;
        int y=i;
        if((x-y)>=mir && (x-y)<=mar && (x+y)!=0)
        {
            return {true,{x,y}};
        }
    }
    return {false,{-1,-1}};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <pair<int,int> > a(n);
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        pair <int,int> curr={0,0};
        for(int j=0;j<s.size();++j)
        {
            if(s[j]=='B')
            {
                curr.first++;
            }
            else
            {
                curr.second++;
            }
        }
        a[i]=curr;
    }
    int low=(-1);
    int up=1e6;
    pair <int,int> res;
    while(true)
    {
        if((up-low)==1)
        {
            cout<<up<<endl;
            for(int i=0;i<res.first;++i)
            {
                cout<<'B';
            }
            for(int i=0;i<res.second;++i)
            {
                cout<<'N';
            }
            exit(0);
        }
        int k=(low+up)/2;
        pair <bool,pair<int,int> > o=check(a,k);
        if(o.first)
        {
            res=o.second;
            up=k;
        }
        else
        {
            low=k;
        }
    }
    return 0;
}