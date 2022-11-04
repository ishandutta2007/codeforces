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
const int maxn=100005;
const ll Mod=1000000007;


struct node
{
    ll u,w;
}c[maxn],d[maxn];


struct nod
{
    ll u,v,w;
}s[maxn];

ll a[maxn];
int main()
{
    sync;
    ll n,m;
    cin>>n>>m;
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        a[u]+=w;
        a[v]-=w;
    }
    ll ct=0,dt=0;
    for(int i=1;i<=n;i++)
    {
//        cout<<a[i]<<' ';
        if(a[i]>0)
        {
            c[ct].u=i;
            c[ct++].w=a[i];
        }
        else if(a[i]<0)
        {
            d[dt].u=i;
            d[dt++].w=-a[i];
        }
    }
//    cout<<endl;
    ll r=0;
    ll cnt=0;
    ll l=0;
    while(r<dt)
    {
        while(d[r].w>0)
        {
            if(c[l].w>d[r].w)
            {
                s[cnt].u=c[l].u;
                s[cnt].v=d[r].u;
                s[cnt++].w=d[r].w;
                c[l].w-=d[r].w;
                d[r].w-=d[r].w;
            }
            else if(c[l].w<d[r].w)
            {
                s[cnt].u=c[l].u;
                s[cnt].v=d[r].u;
                s[cnt++].w=c[l].w;
                d[r].w-=c[l].w;
                l++;
            }
            else
            {
                s[cnt].u=c[l].u;
                s[cnt].v=d[r].u;
                s[cnt++].w=c[l].w;
                l++;
                d[r].w-=d[r].w;
            }
        }
        r++;
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<s[i].u<<' '<<s[i].v<<' '<<s[i].w<<endl;
    
    return 0;
}