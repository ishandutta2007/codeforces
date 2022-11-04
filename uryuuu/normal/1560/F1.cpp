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
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;


int dp[1030][12];
int a[20];
int n;
int pw[maxn];
int k;

ll dfs(int pos,ll pre,int st,int now,int fl)
{
//    cout<<pre<<' '<<now<<' '<<k<<' '<<fl<<endl;
    if(pos>n)
        return pre;
    if(fl==1)
    {
        if(now<k)
        {
            if(st&1)
                return dfs(pos+1,10ll*pre,st,now,fl);
            return dfs(pos+1,10ll*pre,st|1,now+1,fl);
        }
        for(int i=0;i<=9;i++)
        {
            if(st&pw[i])
                return dfs(pos+1,10ll*pre+i,st,now,fl);
        }
        return 1e18;
    }
    ll mn=1e18;
    if(st&pw[a[pos]])
        mn=min(mn,dfs(pos+1,10ll*pre+a[pos],st,now,fl));
    else
    {
        if(now<k)
        {
            mn=min(mn,dfs(pos+1,10ll*pre+a[pos],st|pw[a[pos]],now+1,fl));
        }
    }
    
    for(int i=a[pos]+1;i<=9;i++)
    {
        if(st&pw[i])
        {
            mn=min(mn,dfs(pos+1,10ll*pre+i,st,now,1));
            break;
        }
        else
        {
            if(now<k)
            {
                mn=min(mn,dfs(pos+1,10ll*pre+i,st|pw[i],now+1,1));
            }
        }
    }
    return mn;
}

int main()
{
    sync;
    pw[0]=1;
    for(int i=1;i<=9;i++)
        pw[i]=2*pw[i-1];
    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x>>k;
        n=0;
        while(x)
        {
            a[++n]=x%10;
            x/=10;
        }
        reverse(a+1,a+n+1);
        cout<<dfs(1,0,0,0,0)<<endl;
    }
    return 0;
}