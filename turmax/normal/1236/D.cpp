#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,m;
map <pair<int,int>,int> prep;
vector <vector <int> > a;
vector <vector <int> > b;
int lx,rx;
int ly,ry;
int x,y;
int sum;
int di;
bool turn;
pair <int,int> to1()
{
    if(di==0)
    {
        if(a[x].empty())
        {
            return {x,ry};
        }
        if(a[x][a[x].size()-1]<y)
        {
            return {x,ry};
        }
        else
        {
            return {x,min((*lower_bound(a[x].begin(),a[x].end(),y)),ry)};
        }
    }
    if(di==2)
    {
        if(a[x].empty())
        {
            return {x,ly};
        }
        if(a[x][0]>y)
        {
            return {x,ly};
        }
        else
        {
            int z=lower_bound(a[x].begin(),a[x].end(),y)-a[x].begin();
            z--;
            return {x,max(a[x][z],ly)};
        }
    }
    if(di==1)
    {
        if(b[y].empty())
        {
            return {rx,y};
        }
        if(b[y][b[y].size()-1]<x)
        {
            return {rx,y};
        }
        else
        {
            return {min(*lower_bound(b[y].begin(),b[y].end(),x),rx),y};
        }
    }
    if(di==3)
    {
        if(b[y].empty())
        {
            return {lx,y};
        }
        if(b[y][0]>x)
        {
            return {lx,y};
        }
        else
        {
            int z=lower_bound(b[y].begin(),b[y].end(),x)-b[y].begin();
            z--;
            return {max(b[y][z],lx),y};
        }
    }
}
pair <int,int> form(pair <int,int> a)
{
    if(di==0)
    {
        a.second--;
    }
    if(di==1)
    {
        a.first--;
    }
    if(di==2)
    {
        a.second++;
    }
    if(di==3)
    {
        a.first++;
    }
    return a;
}
bool go()
{
    pair <int,int> to;
    to=to1();
    to=form(to);
    if(to==make_pair(x,y))
    {
        if(turn || x!=0 || y!=0)
        {
        return false;
        }
        else
        {
        turn=true;
        ++di;
        di%=4;
        return true;
        }
    }
    else
    {
        sum+=(abs(to.first+to.second-x-y));
        x=to.first;
        y=to.second;
        if(di==0)
        {
            lx=x;
        }
        if(di==1)
        {
            ry=y;
        }
        if(di==2)
        {
            rx=x;
        }
        if(di==3)
        {
            ly=y;
        }
        ++di;
        di%=4;
        return true;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k;
    cin>>n>>m>>k;
    a.resize(n);
    b.resize(m);
    for(int i=0;i<k;++i)
    {
        cin>>x>>y;
        x--;
        y--;
        prep[{x,y}]=1;
        a[x].push_back(y);
        b[y].push_back(x);
    }
    for(int i=0;i<n;++i)
    {
        sort(a[i].begin(),a[i].end());
    }
    for(int i=0;i<m;++i)
    {
        sort(b[i].begin(),b[i].end());
    }
    x=0;
    y=0;
    sum=1;
    lx=0;
    rx=n;
    ly=(-1);
    ry=m;
    di=0;
    turn=false;
    //cout<<x<<" "<<y<<endl;
    while(go())
    {
        //cout<<x<<" "<<y<<" "<<" "<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<endl;
    }
    if(sum==(n*m-k))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}