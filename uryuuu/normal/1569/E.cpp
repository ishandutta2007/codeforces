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
const int maxn=35;
//const ll Mod=1000000007;
const ll Mod=998244353;

int k,n,mid;
ll pw[maxn];
int plc[maxn];

int rk[maxn];
ll A,h;
int fl=0;
int w[2000005];


int getp(int l,int r,int st)
{
    for(int i=0;i<mid;i++)
    {
        w[i]=l+i;
    }
    int dep=k+1,tot=mid;
    int now=0,cnt;
    while(tot>1)
    {
        cnt=0;
        for(int i=0;i<tot;i+=2)
        {
            if(st&(1<<now))
            {
                rk[w[i+1]]=plc[dep];
                w[cnt++]=w[i];
            }
            else
            {
                rk[w[i]]=plc[dep];
                w[cnt++]=w[i+1];
            }
            now++;
        }
        tot/=2;
        dep--;
    }
    if(st&(1<<now))
        rk[w[0]]=1;
    else
        rk[w[0]]=2;
    return (st&(1<<now));
}

unordered_map<int,int>mp;
vector<int>ans[2000005];

int main()
{
    sync;
    cin>>k>>A>>h;
    pw[0]=1ll;
    for(int i=1;i<=32;i++)
    {
        pw[i]=1ll*A*pw[i-1]%Mod;
    }
    plc[1]=1;
    plc[2]=2;
    plc[3]=3;
    plc[4]=5;
    plc[5]=9;
    plc[6]=17;

    n=(1<<k);
    
    mid=n/2ll;
    int tot=1<<mid;
    int j;
    ll sum,d;
    int id=0;
    
    for(int i=0;i<tot;i++)
    {
        getp(1,mid,i);
        sum=0;
        for(j=1;j<=mid;j++)
        {
            sum=(sum+1ll*j*pw[rk[j]])%Mod;
        }
        if(mp[sum]==0)
        {
            mp[sum]=++id;
        }
        ans[mp[sum]].push_back(i);
    }
    
    int L,R;
    for(int i=0;i<tot;i++)
    {
        R=getp(mid+1,n,i);
//        for(j=mid+1;j<=n;j++)
//            cout<<rk[j]<<' ';
//        cout<<endl;
        sum=0;
        for(j=mid+1;j<=n;j++)
        {
            sum=(sum+1ll*j*pw[rk[j]])%Mod;
        }
        d=(h-sum+Mod+Mod)%Mod;
        if(mp[d]==0)
            continue;
        d=mp[d];
        for(int v:ans[d])
        {
            L=getp(1,mid,v);
            if(L!=R)
            {
                for(j=1;j<=n;j++)
                    cout<<rk[j]<<' ';
                cout<<endl;
                return 0;
            }
        }
    }
    
    cout<<-1<<endl;
    
    return 0;
}