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
//#pragma comment(linker, "/STACK:36777216")  //hdu 
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
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;


int a[maxn];
int pre[maxn],suc[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    pre[1]=1;
    
    int lmt=1;
    
    for(int i=2;i<=n;i++)
    {
        pre[i]=1;
        if(a[i]>a[i-1])
            pre[i]+=pre[i-1];
    }
    suc[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        suc[i]=1;
        if(a[i]>a[i+1])
            suc[i]+=suc[i+1];
    }
    for(int i=1;i<=n;i++)
    {
        lmt=max(lmt,pre[i]);
        lmt=max(lmt,suc[i]);
    }
    int mx,mn;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        mx=max(pre[i],suc[i]);
        if(mx==lmt)
            sum++;
    }
    if(sum>1)
    {
        cout<<0<<endl;
        return 0;
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(pre[i]>1&&suc[i]>1)
        {
            mx=max(pre[i],suc[i]);
            mn=min(pre[i],suc[i]);
            if(mx<lmt)
                continue;
            mx=mx/2*2;
            if(mx<mn)
                ans++;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}