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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
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
const int maxn=1000005;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn],b[maxn];

vector<int>g[maxn],h;
unordered_map<int,int>mp;

int main()
{
    sync;
    mp.reserve(1024);
    mp.max_load_factor(0.25);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        h.clear();
        mp.clear();
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int j;
        int w;
        for(int i=1;i<=n;i++)
        {
            for(j=1;j*j<=a[i];j++)
            {
                if(a[i]%j==0)
                {
//                    cout<<a[i]<<' '<<j<<endl;
                    if(mp[j]==0)
                    {
                        mp[j]=1;
                        h.push_back(j);
                    }
                    g[j].push_back(i);
                    if(a[i]!=j*j)
                    {
                        w=a[i]/j;
                        if(mp[w]==0)
                        {
                            mp[w]=1;
                            h.push_back(w);
                        }
                        g[w].push_back(i);
                    }
                }
            }
        }
        int sz,ans=0,sum=0;
        for(int id:h)
        {
            if(g[id].size()==n)
                continue;
            sz=g[id].size();
            for(j=0;j<sz;j++)
            {
                g[id].push_back(g[id][j]);
            }
            sz=g[id].size();
            sum=1;
//            cout<<id<<':';
//            for(j=0;j<sz;j++)
//                cout<<g[id][j]<<' ';
//            cout<<endl;
            for(j=1;j<sz;j++)
            {
                if(g[id][j]==g[id][j-1]%n+1)
                    sum++;
                else
                    sum=1;
                ans=max(ans,sum);
            }
        }
        for(int id:h)
            g[id].clear();
        cout<<ans<<endl;
        
    }
    
    return 0;
}