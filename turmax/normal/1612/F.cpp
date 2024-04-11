#include <bits/stdc++.h>

using namespace std;
#define int long long
int o=1e6;
set <int> d;
set <int> use;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int q1;
    cin>>q1;
    while(q1--)
    {
        int x,y;
        cin>>x>>y;
        d.insert(x*o+y);
    }
    queue<vector<int> > q;
    q.push({1,1,0});
    use.insert({1,1});
    while(!q.empty())
    {
         vector <int> v=q.front();q.pop();int x=v[0];int y=v[1];int we=v[2];
         if(x==n && y==m)
         {
             cout<<we;
             return 0;
         }
         int val=x+y;
         if(d.count(x*o+y)) ++val;
         pair <int,int> o1={min(val,n),y};
         pair <int,int> o2={x,min(val,m)};
         if(!use.count(o1.first*o+o1.second) && (x-y<=50 || (x+y)>=n || y==m))
         {
             q.push({o1.first,o1.second,we+1});
             use.insert(o1.first*o+o1.second);
         }
         if(!use.count(o2.first*o+o2.second) && (y-x<=50 || (x+y)>=m || x==n))
         {
             q.push({o2.first,o2.second,we+1});
             use.insert(o2.first*o+o2.second);
         }
    }
    return 0;
}