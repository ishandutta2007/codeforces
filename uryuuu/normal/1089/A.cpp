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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=205;
const ll Mod=1000000007;
//const ll Mod=998244353;

int dp[maxn][maxn][4][4];

int ans[6][2];


void solve(int i,int j,int a,int b)
{
    int cnt=a+b;
    cout<<a<<':'<<b<<endl;
    int k,f;
    for(int g=a+b;g>=1;g--)
    {
        f=0;
        if(a+b==5)
        {
            if(b==3)
            {
                for(k=0;k<=13;k++)
                {
                    if(i<k||j<15)
                        break;
                    if(dp[i-k][j-15][a][b-1])
                    {
                        i-=k;
                        j-=15;
                        b--;
                        f=1;
                        ans[g][0]=k;
                        ans[g][1]=15;
                        break;
                    }
                }
                if(f)
                    continue;
                for(k=14;k<=200;k++)
                {
                    if(i<k||j<k+2)
                        break;
                    if(dp[i-k][j-k-2][a][b-1])
                    {
                        i-=k;
                        j-=(k+2);
                        b--;
                        f=1;
                        ans[g][0]=k;
                        ans[g][1]=k+2;
                        break;
                    }
                }
                if(f)
                    continue;
            }
            if(a==3)
            {
                for(k=0;k<=13;k++)
                {
                    if(i<15||j<k)
                        break;
                    if(dp[i-15][j-k][a-1][b])
                    {
                        i-=15;
                        j-=k;
                        a--;
                        f=1;
                        ans[g][0]=15;
                        ans[g][1]=k;
                        break;
                    }
                }
                if(f)
                    continue;
                for(k=14;k<=200;k++)
                {
                    if(j<k||i<k+2)
                        break;
                    if(dp[i-k-2][j-k][a-1][b])
                    {
                        i-=(k+2);
                        j-=k;
                        a--;
                        f=1;
                        ans[g][0]=k+2;
                        ans[g][1]=k;
                        break;
                    }
                }
                if(f)
                    continue;
            }
        }
        else
        {
            if(b&&a!=3)
            {
                for(k=0;k<=23;k++)
                {
                    if(i<k||j<25)
                        break;
                    if(dp[i-k][j-25][a][b-1])
                    {
                        i-=k;
                        j-=25;
                        b--;
                        f=1;
                        ans[g][0]=k;
                        ans[g][1]=25;
                        break;
                    }
                }
                if(f)
                    continue;
                for(k=24;k<=200;k++)
                {
                    if(i<k||j<k+2)
                        break;
                    if(dp[i-k][j-k-2][a][b-1])
                    {
                        i-=k;
                        j-=(k+2);
                        b--;
                        f=1;
                        ans[g][0]=k;
                        ans[g][1]=k+2;
                        break;
                    }
                }
                if(f)
                    continue;
            }
            if(a&&b!=3)
            {
                for(k=0;k<=23;k++)
                {
                    if(i<25||j<k)
                        break;
                    if(dp[i-25][j-k][a-1][b])
                    {
                        i-=25;
                        j-=k;
                        a--;
                        f=1;
                        ans[g][0]=25;
                        ans[g][1]=k;
                        break;
                    }
                }
                if(f)
                    continue;
                for(k=24;k<=200;k++)
                {
                    if(j<k||i<k+2)
                        break;
                    if(dp[i-k-2][j-k][a-1][b])
                    {
                        i-=(k+2);
                        j-=k;
                        a--;
                        f=1;
                        ans[g][0]=k+2;
                        ans[g][1]=k;
                        break;
                    }
                }
                if(f)
                    continue;
            }
        }
    }
    for(int i=1;i<cnt;i++)
    {
        cout<<ans[i][0]<<':'<<ans[i][1]<<' ';
    }
    cout<<ans[cnt][0]<<':'<<ans[cnt][1]<<endl;
}



int main()
{
    sync;
    dp[0][0][0][0]=1;
    int k,h;
    int a,b;
    for(int i=0;i<=200;i++)
    {
        for(int j=0;j<=200;j++)
        {
            for(a=0;a<=3;a++)
            {
                for(b=0;b<=3;b++)
                {
                    if(a+b>5)
                        continue;
                    if(a+b==5)
                    {
                        if(b==3)
                        {
                            for(k=0;k<=13;k++)
                            {
                                if(i<k||j<15)
                                    break;
                                if(dp[i-k][j-15][a][b-1])
                                    dp[i][j][a][b]=1;
                            }
                            for(k=14;k<=200;k++)
                            {
                                if(i<k||j<k+2)
                                    break;
                                if(dp[i-k][j-k-2][a][b-1])
                                    dp[i][j][a][b]=1;
                            }
                        }
                        if(a==3)
                        {
                            for(k=0;k<=13;k++)
                            {
                                if(i<15||j<k)
                                    break;
                                if(dp[i-15][j-k][a-1][b])
                                    dp[i][j][a][b]=1;
                            }
                            for(k=14;k<=200;k++)
                            {
                                if(j<k||i<k+2)
                                    break;
                                if(dp[i-k-2][j-k][a-1][b])
                                    dp[i][j][a][b]=1;
                            }
                        }
                    }
                    else
                    {
                        if(b&&a!=3)
                        {
                            for(k=0;k<=23;k++)
                            {
                                if(i<k||j<25)
                                    break;
                                if(dp[i-k][j-25][a][b-1])
                                    dp[i][j][a][b]=1;
                            }
                            for(k=24;k<=200;k++)
                            {
                                if(i<k||j<k+2)
                                    break;
                                if(dp[i-k][j-k-2][a][b-1])
                                    dp[i][j][a][b]=1;
                            }
                        }
                        if(a&&b!=3)
                        {
                            for(k=0;k<=23;k++)
                            {
                                if(i<25||j<k)
                                    break;
                                if(dp[i-25][j-k][a-1][b])
                                    dp[i][j][a][b]=1;
                            }
                            for(k=24;k<=200;k++)
                            {
                                if(j<k||i<k+2)
                                    break;
                                if(dp[i-k-2][j-k][a-1][b])
                                    dp[i][j][a][b]=1;
                            }
                        }
                    }
                }
            }
        }
    }
    
//    cout<<dp[25][0][1][0]<<' '<<dp[50][0][2][0]<<' '<<dp[75][0][3][0]<<endl;
    ll q;
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        if(dp[u][v][3][0])
        {
            solve(u,v,3,0);
            continue;
        }
        if(dp[u][v][3][1])
        {
            solve(u,v,3,1);
            continue;
        }
        if(dp[u][v][3][2])
        {
            solve(u,v,3,2);
            continue;
        }
        if(dp[u][v][2][3])
        {
            solve(u,v,2,3);
            continue;
        }
        if(dp[u][v][1][3])
        {
            solve(u,v,1,3);
            continue;
        }
        if(dp[u][v][0][3])
        {
            solve(u,v,0,3);
            continue;
        }
        
        cout<<"Impossible"<<endl;
    }
    
    return 0;
}