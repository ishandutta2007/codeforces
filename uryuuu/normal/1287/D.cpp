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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2005;
const ll Mod=1000000007;

vector<int>g[maxn];
int n,p[maxn],c[maxn],a[maxn];

vector<int>dfs(int x)
{
    vector<int>ans;
    for(int i=0;i<g[x].size();i++)
    {
        vector<int>tmp=dfs(g[x][i]);
        for(int j=0;j<tmp.size();j++)
            ans.push_back(tmp[j]);
    }
    if(x==0)
        return ans;
    if(ans.size()<c[x])
    {
        cout<<"NO"<<endl;
        exit(0);
    }
    vector<int>news;
    for(int i=0;i<c[x];i++)
        news.push_back(ans[i]);
    news.push_back(x);
    for(int i=c[x];i<ans.size();i++)
    {
        news.push_back(ans[i]);
    }
    ans=news;
    return ans;
}

int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>c[i];
        g[p[i]].push_back(i);
    }
    vector<int>ans=dfs(0);
    cout<<"YES"<<endl;
    for(int i=0;i<ans.size();i++)
    {
        a[ans[i]]=i+1;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}