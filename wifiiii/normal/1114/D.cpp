#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef long long ll;
typedef vector<int> vec;
typedef pair<ll,ll> pii;

int a[5005];
int vis[5005][5005];
vec v;
int dfs(int l,int r)
{
    if(l>=r) return 0;
    if(vis[l][r]) return vis[l][r];
    int ret;
    if(v[l]==v[r]) ret = dfs(l+1,r-1)+1;
    else ret = min(dfs(l+1,r)+1,dfs(l,r-1)+1);
    return (vis[l][r]=ret);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        if(a[i]!=a[i+1]) v.pb(a[i]);
    }
    n = v.size();
    cout << dfs(0,n-1) << endl;
}