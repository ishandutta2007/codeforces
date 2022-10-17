#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod = 1e9+7;

vector<int> a[150005];
int par[150005];
int findd(int u)
{
    return u==par[u]?u:par[u]=findd(par[u]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) par[i]=i;
    for(int i=1;i<=n;++i) a[i].pb(i);
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        int x=findd(u),y=findd(v);
        if(a[x].size()>a[y].size()) swap(x,y);
        for(int i:a[x]) a[y].pb(i);
        par[x]=y;
    }
    int x=findd(1);
    for(int i:a[x]) cout<<i<<" ";
    cout<<endl;
}