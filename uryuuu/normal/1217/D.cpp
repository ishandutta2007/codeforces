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
#define lb(x) (x&(-x));
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=5005;
const ll Mod=1000000007;

vector<int>g[maxn];
int d[maxn];
int n;

int tupo()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
        {
            q.push(i);
            d[i]=-1;
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            d[v]--;
            if(d[v]==0)
            {
                q.push(v);
                d[v]=-1;
            }
        }
        q.pop();
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]!=-1)
            return 1;
    }
    return 0;
}


struct node
{
    int u,v;
}t[maxn];
int main()
{
    sync;
    int m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        cin>>t[i].u>>t[i].v;
        g[t[i].u].push_back(t[i].v);
        d[t[i].v]++;
    }
    if(tupo())
    {
        cout<<2<<endl;
        for(int i=0;i<m;i++)
        {
            if(t[i].u<t[i].v)
                cout<<1<<' ';
            else
                cout<<2<<' ';
        }
    }
    else
    {
        cout<<1<<endl;
        for(int i=0;i<m;i++)
            cout<<1<<' ';
    }
    cout<<endl;
    return 0;
}