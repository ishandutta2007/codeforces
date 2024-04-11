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
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

int vis[10];
map<int,ll>mp;

void dfs(int st)
{
    if(st==10)
    {
        ll s=0ll;
        int d=0;
        for(int i=1;i<=9;i++)
        {
            if(vis[i])
            {
                s=10ll*s+1ll*i;
                d+=i;
            }
//            cout<<vis[i]<<' ';
        }
//        cout<<s<<' '<<d<<endl;
        if(mp[d]==0||mp[d]>s)
            mp[d]=s;
        return;
    }
    vis[st]=1;
    dfs(st+1);
    vis[st]=0;
    dfs(st+1);
}



int main()
{
    sync;
    int t;
    int x;
    dfs(1);
    cin>>t;
    while(t--)
    {
        cin>>x;
        if(x==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(mp[x]==0)
            cout<<-1<<endl;
        else
            cout<<mp[x]<<endl;

    }
    
    
    return 0;
}