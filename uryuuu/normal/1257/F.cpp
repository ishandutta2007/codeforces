//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2000005;
int a[maxn],n;
vector<int>v;
map<vector<int>,int>vis;
int ans=-1;
void dfs1(int i,int now)
{
    if(i==15)
    {
        v.clear();
        for(int j=1;j<=n;j++)
        {
            v.push_back(__builtin_popcount((now^a[j])%(1<<15)));
        }
        for(int j=1;j<n;j++)
        {
            v[j-1]=v[j]-v[j-1];
        }
        v.pop_back();
        if(!vis.count(v))
            vis[v]=now;
        return;
    }
    dfs1(i+1,now);
    dfs1(i+1,now|(1<<i));
}
void dfs2(int i,int now)
{
    if(i==15)
    {
        v.clear();
        for(int j=1;j<=n;j++)
            v.push_back(__builtin_popcount(now^(a[j]>>15)));
        for(int j=1;j<n;j++)
        {
            v[j-1]-=v[j];
        }
        v.pop_back();
        if(vis.count(v))
            ans=vis[v]|(now<<15);
        return ;
    }
    dfs2(i+1,now);
    dfs2(i+1,now|(1<<i));
}
int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs1(0,0);
    dfs2(0,0);
    cout<<ans<<endl;
    return 0;
}