#include<iostream>
#include<stdio.h>
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
const int maxn=100005;
const ll Mod=1000000007;

ll a[maxn];
ll dfs(vector<ll>&v, int s)
{
    if(s<0)
        return 0;
    vector<ll>v1,v2;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]&(1<<s))
        {
            v1.push_back(v[i]);
        }
        else
        {
            v2.push_back(v[i]);
        }
    }
    if(v1.size()==0)
    {
        return dfs(v2,s-1);
    }
    else if(v2.size()==0)
    {
        return dfs(v1,s-1);
    }
    return min(dfs(v1,s+1),dfs(v2,s+1))+(1<<s);
}

int main()
{
    sync;
    vector<ll>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        v.push_back(a[i]);
    }

    cout<<dfs(v,31);
    return 0;
}