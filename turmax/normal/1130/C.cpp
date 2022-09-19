#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int cou(vector <pair<int,int> > a,pair <int,int> b)
{
    for(int i=0;i<a.size();++i)
    {
         if(a[i]==b)
         {
             return 1;
         }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int x1,y1,x2,y2;
    cin>>x1>>y1;
    cin>>x2>>y2;
    int a[n+2][n+2];
    string s;
    for(int i=0;i<n;++i)
    {
        cin>>s;
        a[i+1][0]=1;
        a[i+1][n+1]=1;
        a[0][i+1]=1;
        a[n+1][i+1]=1;
        for(int j=0;j<n;++j)
        {
            a[i+1][j+1]=(s[j]=='1');
        }
    }
    int o;
    vector <pair<int,int> > v1;
    v1.push_back({x1,y1});
    deque <pair<int,int> > h1;
    h1.push_back({x1,y1});
    pair <int,int> l;
    while(true)
    {
        deque <pair<int,int> > r1;
        o=v1.size();
        while(h1.size()>0)
        {
            l=h1.front();
            if(a[l.first-1][l.second]==0 && cou(v1,{l.first-1,l.second})==0)
            {
                v1.push_back({l.first-1,l.second});
                r1.push_back({l.first-1,l.second});
            }
            if(a[l.first+1][l.second]==0 && cou(v1,{l.first+1,l.second})==0)
            {
                v1.push_back({l.first+1,l.second});
                r1.push_back({l.first+1,l.second});
            }
            if(a[l.first][l.second-1]==0 && cou(v1,{l.first,l.second-1})==0)
            {
                v1.push_back({l.first,l.second-1});
                r1.push_back({l.first,l.second-1});
            }
            if(a[l.first][l.second+1]==0 && cou(v1,{l.first,l.second+1})==0)
            {
                v1.push_back({l.first,l.second+1});
                r1.push_back({l.first,l.second+1});
            }
            h1.pop_front();
        }
        if(v1.size()==o)
        {
            break;
        }
        h1=r1;
    }
    vector <pair<int,int> > v2;
    v2.push_back({x2,y2});
    deque <pair<int,int> > h2;
    h2.push_back({x2,y2});
    while(true)
    {
        deque <pair<int,int> > r2;
        o=v2.size();
        while(h2.size()>0)
        {
            l=h2.front();
            if(a[l.first-1][l.second]==0 && cou(v2,{l.first-1,l.second})==0)
            {
                v2.push_back({l.first-1,l.second});
                r2.push_back({l.first-1,l.second});
            }
            if(a[l.first+1][l.second]==0 && cou(v2,{l.first+1,l.second})==0)
            {
                v2.push_back({l.first+1,l.second});
                r2.push_back({l.first+1,l.second});
            }
            if(a[l.first][l.second-1]==0 && cou(v2,{l.first,l.second-1})==0)
            {
                v2.push_back({l.first,l.second-1});
                r2.push_back({l.first,l.second-1});
            }
            if(a[l.first][l.second+1]==0 && cou(v2,{l.first,l.second+1})==0)
            {
                v2.push_back({l.first,l.second+1});
                r2.push_back({l.first,l.second+1});
            }
            h2.pop_front();
        }
        if(v2.size()==o)
        {
            break;
        }
        h2=r2;
    }
    int y=1e9;
    for(int i=0;i<v1.size();++i)
    {
        for(int j=0;j<v2.size();++j)
        {
            y=min(y,(v1[i].first-v2[j].first)*(v1[i].first-v2[j].first)+(v1[i].second-v2[j].second)*(v1[i].second-v2[j].second));
        }
    }
    cout<<y;
    return 0;
}