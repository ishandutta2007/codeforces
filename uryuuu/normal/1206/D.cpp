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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

int n;
ll a[maxn];
ll mp[300][300];
ll dis[300][300];
ll minc;

void floyed()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<k;i++)
        {
            for(int j=i+1;j<k;j++)
            {
                minc=min(minc,mp[i][k]+mp[k][j]+dis[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}


int main()
{
    sync;
    int m;
    n=1;
    cin>>m;
    ll x;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        if(x!=0)
            a[n++]=x;
    }
    n--;
    if(n>200)
    {
        cout<<3<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            mp[i][j]=dis[i][j]=999999ll;
            mp[i][i]=dis[i][i]=0;
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]&a[j])
                dis[i][j]=dis[j][i]=mp[j][i]=mp[i][j]=1ll;
        }
    }
    
    minc=999999;
    floyed();
    if(minc==999999)
        cout<<-1<<endl;
    else
        cout<<minc<<endl;
    return 0;
}