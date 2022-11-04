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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=505;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll dp[2][maxn][maxn];
ll p[maxn],inv[maxn];
ll c[maxn][maxn];

ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res%Mod;
}
 
ll C(int n,int m)
{
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}

ll calc[maxn][maxn];


int main()
{
    sync;
    p[0]=inv[0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
//        inv[i]=ksm(p[i],Mod-2);
    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //
    for(int i=maxn-3;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;
    
    int j,k,h;
    for(int i=1;i<=500;i++)
    {
        for(j=0;j<=i;j++)
            c[i][j]=C(i,j);
    }
    
    for(int i=1;i<maxn;i++)
    {
        for(j=0;j<maxn;j++)
        {
            calc[i][j]=ksm(i,j);
        }
    }
    
    int n,up;
    cin>>n>>up;
    dp[0][n][0]=1ll;
    ll ans=0;
    ll s;
    ll dmg,lstk,lstj;
    int f=0;
    int mx=0;
    int UUP;
    int mxj=n,mxk=0,upj=0,upk=0;
    int id;
    for(int i=1;i<=up;i++) //i  j  k  h 
    {
        f=0;
        upk=mxk+n-1;
        upj=mxj;
        mxj=0;mxk=0;
        id=i%2;
        memset(dp[id],0,sizeof(dp[id]));
        
        for(j=2;j<=upj;j++)
        {
            for(k=i;k<=min(up,upk);k++)
            {
                for(h=0;h<=upj-j;h++)
                {
                    dmg=(j+h)-1;
                    if(dmg>k)
                        break;
                    lstj=j+h;
                    lstk=k-dmg;
                    if(dp[1-id][lstj][lstk]==0)
                        continue;
                    if(min(k,up)-(lstk+1)+1<0)
                        continue;
                    s=c[lstj][h]*calc[min(k,up)-(lstk+1)+1][h]%Mod*dp[1-id][lstj][lstk]%Mod;
                    dp[id][j][k]+=s;
                }
                dp[id][j][k]%=Mod;
                if(dp[id][j][k])
                {
                    f=1;
                    mxk=max(mxk,k);
                    mxj=max(mxj,j);
                }
            }
        }
        
        for(k=i;k<=upk;k++)
        {
            for(h=2;h<=n;h++)
            {
                dmg=h-1;
                if(dmg>k)
                    break;
                lstj=h;
                lstk=k-dmg;
                if(dp[1-id][lstj][lstk]==0)
                    continue;
                if(min(k,up)-(lstk+1)+1<0)
                    continue;
                s=c[lstj][h]*calc[min(k,up)-(lstk+1)+1][h]%Mod*dp[1-id][lstj][lstk]%Mod;
                ans+=s;
            }
            ans%=Mod;
        }
        if(f==0)
            break;
    }
    cout<<(ans%Mod+Mod)%Mod<<endl;
    return 0;
}