#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=2e5+5;
vector <int> a[maxn];
vector <int> b[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);b[y].push_back(x);
    }
    int l=25;
    pair <int,int> is[n][2];
    bool used[n][2];
    set <pair<pair<int,int>,pair<int,int> > > d;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<2;++j)
        {
        is[i][j]={1e18,1e18};
        used[i][j]=false;
        }
    }
    is[0][0]={0,0};
    for(int i=0;i<n;++i) for(int j=0;j<2;++j) d.insert({is[i][j],{i,j}});
    while(!d.empty())
    {
        pair <pair<int,int>,pair<int,int> > o=(*d.begin());
        d.erase(d.begin());
        int curr=o.second.first;
        used[curr][o.second.second]=true;
        int h=o.first.first;
        int w=o.first.second;
        for(auto v:a[curr])
        {
            if(h%2==0)
            {
                if(used[v][0]) continue;
                d.erase({is[v][0],{v,0}});
                is[v][0]=min(is[v][0],{h,w+1});
                d.insert({is[v][0],{v,0}});
            }
            else if(h%2==1)
            {
                if(used[v][0]) continue;
                d.erase({is[v][0],{v,0}});
                is[v][0]=min(is[v][0],{h+1,w+1});
                d.insert({is[v][0],{v,0}});
            }
        }
        for(auto v:b[curr])
        {
            if(h%2==1)
            {
                if(used[v][1]) continue;
                d.erase({is[v][1],{v,1}});
                is[v][1]=min(is[v][1],{h,w+1});
                d.insert({is[v][1],{v,1}});
            }
            else if(h%2==0)
            {
                if(used[v][1]) continue;
                d.erase({is[v][1],{v,1}});
                is[v][1]=min(is[v][1],{h+1,w+1});
                d.insert({is[v][1],{v,1}});
            }
        }
    }
    pair <int,int> z=min(is[n-1][0],is[n-1][1]);
    if(z.first>=l)
    {
        int ans=1;
        for(int i=0;i<z.first;++i) {ans*=2;ans%=p;}
        ans%=p;
        ans--;
        ans+=z.second;
        ans%=p;ans+=p;ans%=p;
        cout<<ans;
        return 0;
    }
    int is1[n][l];
    bool used1[n][l];
    set <pair<int,pair<int,int> > > d1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<l;++j)
        {
            is1[i][j]=1e18;
            used1[i][j]=false;
        }
    }
    is1[0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<l;++j)
        {
            d1.insert({is1[i][j],{i,j}});
        }
    }
    while(!d1.empty())
    {
        pair <int,pair<int,int> > o=(*d1.begin());
        d1.erase(d1.begin());
        int curr=o.second.first;int h=o.second.second;
        int w=o.first;
        if(w>is1[curr][h]) continue;
        for(auto v:a[curr])
        {
            if(h%2==0)
            {
                if(!used1[v][h] && is1[v][h]>(w+1))
                {
                    is1[v][h]=(w+1);
                    d1.insert({w+1,{v,h}});
                }
            }
            else if((h+1)<l)
            {
                if(!used1[v][h+1] && is1[v][h+1]>(w+1+(1<<h)))
                {
                    is1[v][h+1]=(w+1+(1<<h));
                    d1.insert({w+1+(1<<h),{v,h+1}});
                }
            }
        }
        for(auto v:b[curr])
        {
            if(h%2==1)
            {
                if(!used1[v][h] && is1[v][h]>(w+1))
                {
                    is1[v][h]=(w+1);
                    d1.insert({w+1,{v,h}});
                }
            }
            else if((h+1)<l)
            {
                if(!used1[v][h+1] && is1[v][h+1]>(w+1+(1<<h)))
                {
                    is1[v][h+1]=(w+1+(1<<h));
                    d1.insert({w+1+(1<<h),{v,h+1}});
                }
            }
        }
    }
    int mi=1e18;
    for(int i=0;i<l;++i)
    {
        mi=min(mi,is1[n-1][i]);
    }
    cout<<(mi%p);
    return 0;
}