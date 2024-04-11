#include <bits/stdc++.h>

using namespace std;
#define int long long
pair <int,int> a[10][10];
map <pair<pair<int,int>,bool>,long double> res;
pair <int,int> move1(pair <int,int> u)
{
    int x=u.first;
    int y=u.second;
    if(x==0 && y==0)
    {
        return {0,0};
    }
    if((y==9 && x%2==1) || (y==0 && x%2==0))
    {
        return {x-1,y};
    }
    if(x%2==0)
    {
        return {x,y-1};
    }
    else
    {
        return {x,y+1};
    }
}
pair<int,int> mov(pair <int,int> u,int n)
{
    pair <int,int> z=u;
    for(int i=0;i<n;++i)
    {
        z=move1(z);
    }
    return z;
}
long double f(pair<pair <int,int>,bool> g)
{
    pair <int,int> u=g.first;
    if(u==make_pair(0LL,0LL))
    {
        return (long double)0;
    }
    if(res.count(g)==1)
    {
        return res[g];
    }
    long double mi1=0;
    int z=0;
    for(int i=1;i<=6;++i)
    {
        mi1+=f({mov(u,i),true});
        if(mov(u,i)==make_pair(0LL,0LL))
        {
            z=i;
            break;
        }
    }
    if(z==0)
    {
        z=6;
    }
    mi1/=6.0;
    mi1+=1.0;
    if(!g.second)
    {
        res[g]=mi1*(6.0/(z+0.0));
        return mi1*(6.0/(z+0.0));
    }
    if((a[u.first][u.second].first)==(-1))
    {
        res[g]=mi1*(6.0/(z+0.0));
        return mi1*(6.0/(z+0.0));
    }
    res[g]=min(mi1*(6.0/(z+0.0)),f({a[u.first][u.second],false}));
    return res[g];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x;
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            cin>>x;
            if(x==0)
            {
                a[i][j]={-1,-1};
            }
            else
            {
                a[i][j]={i-x,j};
            }
        }
    }
    cout<<fixed<<setprecision(15)<<f({{9,0},true});
    return 0;
}